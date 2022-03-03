#include <table_opt.hpp>

#include <string>


ACTION table_opt::add_account(std::string owner, uint64_t balance) {
   accounts account_list( _self, 0 );

    account_list.emplace( wasm::no_payer, [&]( auto& a ){
    a.owner   = owner;
    a.balance = balance;
    });

}

ACTION table_opt::get_account(  std::string owner ) {

    accounts account_list( _self, 0 );
    account account_info;
    account_list.get( account_info, owner );



    print("table_opt get_account=====");
    print("owner:" + account_info.owner);
    print("balance:" + std::to_string(account_info.balance));

}

WASM_DISPATCH( table_opt, (add_account)(get_account))