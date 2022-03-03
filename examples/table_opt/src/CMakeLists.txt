project(token)
cmake_minimum_required(VERSION 3.5)
set(wasm.cdt_DIR /usr/local/lib/cmake/wasm.cdt)
set(WASM_WASM_OLD_BEHAVIOR "Off")
find_package(wasm.cdt)

add_contract( table_opt table_opt table_opt.cpp )
target_include_directories( table_opt PUBLIC ${CMAKE_SOURCE_DIR}/../include )
target_ricardian_directory( table_opt ${CMAKE_SOURCE_DIR}/../ricardian )
