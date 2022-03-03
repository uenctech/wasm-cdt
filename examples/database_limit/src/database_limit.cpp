#include <database_limit.hpp>

#include <string>
#include <table.hpp>

ACTION database_limit::set_data(  std::string key, uint64_t size, int num) {
    std::string s(size, 'a');
    for(int i = 0; i < num; i++)
    {
        db_store(0,key.data(),key.size(),s.data(),s.size());
    }
}



WASM_DISPATCH( database_limit, (set_data))