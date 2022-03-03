#include <index.hpp>

using namespace wasm;


ACTION index::add(uint64_t id, string owner, uint64_t balance)
{
    account a{id, owner, balance};
    wasm::db::set(a);
}

ACTION index::get( uint64_t id, string owner, uint64_t code)
{
    account account1;
    account1.id = id;
    wasm::db::get(account1);

    print("account get_by_id====");
    print("id:" + std::to_string(account1.id));
    print("owner:" + account1.owner);
    print("balance:" + std::to_string(account1.balance));


    account account2;
    account2.owner = owner;
    wasm::db::get(account2, wasm::name("by_owner").value);

    print("account get_by_owner====");
    print("id:" + std::to_string(account2.id));
    print("owner:" + account2.owner);
    print("balance:" + std::to_string(account2.balance));


    account account3;
    account3.balance = code;
    wasm::db::get(account3, wasm::name("by_code").value);

    print("account get_by_balance====");
    print("id:" + std::to_string(account3.id));
    print("owner:" + account3.owner);
    print("balance:" + std::to_string(account3.balance));

}

WASM_DISPATCH( index, (add)(get))
