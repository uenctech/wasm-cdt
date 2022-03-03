project(print_per_second)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( print_per_second print_per_second print_per_second.cpp )
target_include_directories( print_per_second PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( print_per_second ${CMAKE_SOURCE_DIR}/../ricardian )
