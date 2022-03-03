#include <wasm.hpp>
using namespace wasm;
using namespace std;

CONTRACT print_per_second : public contract {
   public:
      using contract::contract;

      ACTION execute();

};
