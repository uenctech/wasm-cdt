#include <wasm.hpp>
using namespace wasm;
using namespace std;

CONTRACT alloc_mem : public contract {
   public:
      using contract::contract;

      ACTION execute();

};
