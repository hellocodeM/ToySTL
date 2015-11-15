#ifndef TOYSTL_NEW_HPP
#define TOYSTL_NEW_HPP

#include <cstdlib>

void* operator new(size_t count) { 
    return std::malloc(count); 
}

void operator delete(void* ptr) { 
    std::free(ptr); 
}

#endif
