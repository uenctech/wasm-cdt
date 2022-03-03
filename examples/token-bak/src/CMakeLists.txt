project(token)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
find_package(wasm.cdt)

add_contract( token token token.cpp )
target_include_directories( token PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( token ${CMAKE_SOURCE_DIR}/../ricardian )
