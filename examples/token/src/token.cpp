#include <token.hpp>
//#include <chrono>

using namespace wasm;
using namespace std;
//using std::chrono::system_clock;



ACTION token::create( std::string  issuer, std::string token_name,
                      uint64_t maximum_supply )
{
    require_auth( issuer.data(), issuer.size() );
    stats statstable( _self, 0);
   currency_stats curr_stats;

   if(statstable.get( curr_stats, token_name )) {
      print("token has already create!!!");   
      return;
   }
    statstable.emplace( wasm::no_payer, [&]( auto& s ) {
       s.token_name = token_name;
       s.max_supply    = maximum_supply;
       s.issuer        = issuer;
       s.supply        = 0;
    });
}


ACTION token::issue( string issuer, string token_name, uint64_t quantity)
{
    check( quantity > 0, "must issue positive quantity" );
    currency_stats st;
    stats statstable(_self, 0) ;
    check( statstable.get( st, token_name), "token with symbol does not exist, create token before issue" );

   print("token issue find created token");

    require_auth( issuer.data(), issuer.size() );
    check( quantity > 0, "must issue positive quantity" );
    check( quantity <= st.max_supply - st.supply, "quantity exceeds available supply");

    statstable.modify( st, wasm::no_payer, [&]( auto& s ) {
       s.supply += quantity;
    });


    add_balance( issuer, quantity );

}

ACTION token::transfer( string    from,
                        string    to,
                        uint64_t   quantity
                        )
{
    check( from != to, "cannot transfer to self" );
    check( is_account( from.data(), from.size() ), "to account does not exist");
    check( is_account( to.data(), to.size() ), "to account does not exist");

    check( quantity > 0, "must transfer positive quantity" );

    sub_balance( from, quantity );
    add_balance( to, quantity );
}

void token::sub_balance( string owner, uint64_t value ) {
   accounts from_acnts( _self, 0 );

   account from;
   check( from_acnts.get( from, owner ), "no balance object found" );
   check( from.balance >= value, "overdrawn balance" );

   from_acnts.modify( from, wasm::no_payer, [&]( auto& a ) {
         a.balance -= value;
      });

}


void token::add_balance( string owner, uint64_t value)
{
   accounts to_acnts( _self, 0);

   account to;
   if( !to_acnts.get( to, owner )) {
      to_acnts.emplace( wasm::no_payer, [&]( auto& a ){
        a.owner   = owner;
        a.balance = value;
      });
   } else {
      to_acnts.modify( to, wasm::no_payer, [&]( auto& a ) {
        a.balance += value;
      });
   }
}


WASM_DISPATCH( token, (transfer)(issue)(create))
