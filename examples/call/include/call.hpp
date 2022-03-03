#include <wasm.hpp>
#include <asset.hpp>
#include <inline_transaction.hpp>

#include <string>
using namespace wasm;

namespace wasm {

   using std::string;

   CONTRACT call_contract : public contract {
      public:
         using contract::contract;
 
         ACTION get_ret();
         ACTION get_ret2();


   };
} /// namespace wasm
