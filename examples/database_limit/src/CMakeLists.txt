project(token)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( database_limit database_limit database_limit.cpp )
target_include_directories( database_limit PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( database_limit ${CMAKE_SOURCE_DIR}/../ricardian )
