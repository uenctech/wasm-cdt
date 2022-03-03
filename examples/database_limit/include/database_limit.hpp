#include <wasm.hpp>
using namespace wasm;
using namespace std;

CONTRACT database_limit : public contract {
   public:
      using contract::contract;

      ACTION set_data(std::string key, uint64_t size, int num);

};
