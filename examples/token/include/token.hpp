#include <wasm.hpp>
#include <asset.hpp>
#include <table.hpp>
#include <inline_transaction.hpp>

#include <string>
using namespace wasm;

namespace wasm {

   using std::string;

   CONTRACT token : public contract {
      public:
         using contract::contract;
 
         ACTION create  (string issuer, string token_name, uint64_t maximum_supply);
         ACTION transfer(string from, string to, uint64_t quantity);

         ACTION issue( string issuer, string token_name, uint64_t quantity);

      private:
         TABLE  account {
            std::string    owner;
            uint64_t    balance;

            std::string primary_key()const { return owner; }
         };


         TABLE  currency_stats {
            uint64_t       supply;
            uint64_t       max_supply;
            std::string    issuer;
            std::string      token_name;

            std::string  primary_key()const { return token_name; }
         };



         typedef wasm::table< "accounts"_n, account, string > accounts;
         typedef wasm::table< "token_info"_n, currency_stats, string > stats;

         void sub_balance( string owner, uint64_t value );
         void add_balance( string owner, uint64_t value);

   };
} /// namespace wasm
