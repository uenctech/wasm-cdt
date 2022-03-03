#include <alloc_mem.hpp>
#include <string>

ACTION alloc_mem::execute() {
    print("alloc_mem:10M");
    malloc(10*1024*1024);
}

WASM_DISPATCH( alloc_mem, (execute))