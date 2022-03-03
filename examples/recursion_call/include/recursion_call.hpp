#include <wasm.hpp>
#include <asset.hpp>
#include <inline_transaction.hpp>

#include <string>
using namespace wasm;

namespace wasm {

   using std::string;

   CONTRACT recursion_call : public contract {
      public:
         using contract::contract;
 
         ACTION exec(int i);


   };
} /// namespace wasm
