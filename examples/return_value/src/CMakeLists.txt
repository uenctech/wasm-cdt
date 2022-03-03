project(return_value)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( return_value return_value return_value.cpp )
target_include_directories( return_value PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( return_value ${CMAKE_SOURCE_DIR}/../ricardian )
