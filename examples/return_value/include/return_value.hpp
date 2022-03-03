#include <wasm.hpp>
using namespace wasm;
using namespace std;



#define ACTION2   [[wasm::action]] int64_t

CONTRACT return_value : public contract {
   public:
      using contract::contract;
      ACTION2 ret_int();

};
