project(hello)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( hello hello hello.cpp )
target_include_directories( hello PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( hello ${CMAKE_SOURCE_DIR}/../ricardian )
