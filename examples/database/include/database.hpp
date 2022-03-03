#include <wasm.hpp>
using namespace wasm;
using namespace std;

CONTRACT database : public contract {
   public:
      using contract::contract;

      ACTION set_data(std::string key, std::string value);
      ACTION get_data(std::string key);

};
