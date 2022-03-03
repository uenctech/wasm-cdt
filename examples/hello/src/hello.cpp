#include <hello.hpp>

#include <string>

ACTION hello::hi(  std::string s, int32_t i ) {
    print("hello world!!!!");
    print("s:" + s);
    print("i:" + std::to_string(i));
}

WASM_DISPATCH( hello, (hi))