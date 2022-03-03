#include <print_per_second.hpp>
#include <string>

ACTION print_per_second::execute() {
    int i = 0;
    for (;;) {
        print("execute time:"+ std::to_string(++i));
    }
}

WASM_DISPATCH( print_per_second, (execute))