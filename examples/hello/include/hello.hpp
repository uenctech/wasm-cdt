#include <wasm.hpp>
using namespace wasm;
using namespace std;

CONTRACT hello : public contract {
   public:
      using contract::contract;

      ACTION hi(std::string s, int32_t i);

};
