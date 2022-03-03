#include <database.hpp>

#include <string>
#include <table.hpp>

ACTION database::set_data(  std::string key, std::string value ) {
    db_store(0,key.data(),key.size(),value.data(),value.size());
}

ACTION database::get_data(  std::string key ) {
    auto value_len = db_get(key.data(),key.size(),NULL, 0);

    std::string db_value;
    db_value.reserve(value_len);
    db_get(key.data(),key.size(),db_value.data(),value_len);

    std::string value(db_value.data(),value_len);


    print("database get_data=====");
    print("key:" + key);
    print("value:" + value);



}

WASM_DISPATCH( database, (set_data)(get_data))