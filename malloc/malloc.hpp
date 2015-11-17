#ifndef TOYSTL_NEW_HPP
#define TOYSTL_NEW_HPP

#include <bitset>
#include <cassert>

#include <unistd.h>
#include <sys/mman.h>

namespace toystl {

/* 5 levels of block: 8, 16, 32, 64, 128 bytes
 * number of block: 1024, 512, 256, 128, 64
 */
class BlockManager {
public:
    BlockManager() {
        blocks_base = static_cast<char*>(sbrk(0));
        if (0 != brk(blocks_base + TotalSize())) {
            printf("BlockManager initialize failed: %d", errno);
            exit(1);
        }
    }
    constexpr size_t TotalSize() {
        return 10240 * 8 + 5120 * 16 + 2560 * 32 + 1280 * 64 + 640 * 128;
    }

    void *allocate(size_t count) {
        void *res = nullptr;
        auto worker = [&](auto& block, int block_size) {
            if (block.any()) {
                res = BlockPos(block_size, block.count());
                block.flip(block.count());
            } else {
                printf("allocate failed");
                exit(1);
            }
        };
        if (count > 128) {
            res = mmap(0, count, PROT_WRITE | PROT_READ, MAP_PRIVATE, -1, 0);
        } else if (count > 64) {
            worker(block128_, 128);
        } else if (count > 32) {
            worker(block64_, 64);
        } else if (count > 16) {
            worker(block32_, 32);
        } else if (count > 8) {
            worker(block16_, 16);
        } else {
            worker(block8_, 8);
        }
        return res;
    }

    void deallocate(void *pos) {
        int block_size = 0;
        int count = 0;
        if (!BlockPos(pos, block_size, count)) {
            printf("worse deallocate pointer");
        }
        switch (block_size) {
            case 128:
                block128_.flip(count);
            case 64:
                block64_.flip(count);
            case 32:
                block32_.flip(count);
            case 16:
                block16_.flip(count);
            case 8:
                block8_.flip(count);
            default:
                assert(false);
        }
    }


private:
    /**
     * find the block level and position for a allocated data pointer.
     */
    bool BlockPos(void *data, int& block_size, int& count) {
        char *pos = static_cast<char*>(data);
        if (pos < blocks_base || pos > blocks_base + TotalSize()) {
            return false;
        }
        if (pos > BlockStart(128)) {
            block_size = 128;
            count = (pos - BlockStart(128)) / 128;
        } else if (data > BlockStart(64)) {
            block_size = 64;
            count = (pos - BlockStart(64)) / 64;
        } else if (data > BlockStart(32)) {
            block_size = 32;
            count = (pos - BlockStart(32)) / 32;
        } else if (data > BlockStart(16)) {
            block_size = 16;
            count = (pos - BlockStart(16)) / 16;
        } else {
            block_size = 8;
            count = (pos - BlockStart(8)) / 8;
        }
        return true;
    }

    size_t BlockSize(int block_size) const {
        switch (block_size) {
            case 128:
                return 128 * 640;
            case 64:
                return 64 * 1280;
            case 32:
                return 32 * 2560;
            case 16:
                return 16 * 5120;
            case 8:
                return 8 * 10240;
            default:
                return 0;
        }
    }

    char* BlockPos(int block_size, int count) {
        return BlockStart(block_size) + count * block_size;
    }
    /*
     * find the start position for each level of blocks.
     * the sequential is block128, block64, ...
     */
    char* BlockStart(int block_size ) {
        char *res = blocks_base;
        switch (block_size) {
            case 8: 
                res += BlockSize(16);
            case 16:
                res += BlockSize(32);
            case 32:
                res += BlockSize(64);
            case 64:
                res += BlockSize(128);
            case 128:
                return res;
            default:
                return nullptr;
        }
    }

    std::bitset<10240> block8_;
    std::bitset<5120> block16_;
    std::bitset<2560> block32_; 
    std::bitset<1280> block64_; 
    std::bitset<640> block128_;
    char *blocks_base;
};

BlockManager* ManagerInit() {
    // allocate manager
    char *base = static_cast<char*>(sbrk(0));
    if (0 != brk(base + sizeof(BlockManager))) {
        printf("sbrk failed: %d\n", errno);
        exit(1);
    }
    auto *bm = new (base) BlockManager();
    return bm;
}

BlockManager* GetManager() {
    static BlockManager *manager = ManagerInit();
    return manager;
}

void* malloc(size_t count) { 
    return GetManager()->allocate(count);
}

void free(void* ptr) { 
    GetManager()->deallocate(ptr);
}
}/* end of namespace toystl */
#endif
