project(call)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)

find_package(wasm.cdt)

add_contract( call call call.cpp )
target_include_directories( call PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( call ${CMAKE_SOURCE_DIR}/../ricardian )
