project(alloc_mem)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( alloc_mem alloc_mem alloc_mem.cpp )
target_include_directories( alloc_mem PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( alloc_mem ${CMAKE_SOURCE_DIR}/../ricardian )
