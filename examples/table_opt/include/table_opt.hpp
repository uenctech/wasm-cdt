#include <wasm.hpp>
#include <table.hpp>


using namespace wasm;
using namespace std;

CONTRACT table_opt : public contract {
   public:
      using contract::contract;

      ACTION add_account(std::string owner, uint64_t balance);
      ACTION get_account(std::string owner);

      TABLE  account {
         string         owner;
         uint64_t       balance;

         string primary_key()const { return owner; }
      };


      typedef wasm::table< "accounts"_n, account, string > accounts;


};
