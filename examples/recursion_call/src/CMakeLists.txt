project(recursion_call)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( recursion_call recursion_call recursion_call.cpp )
target_include_directories( recursion_call PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( recursion_call ${CMAKE_SOURCE_DIR}/../ricardian )
