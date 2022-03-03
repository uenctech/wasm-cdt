#include <recursion_call.hpp>
#include <tuple>
#include <string>

#include <inline_transaction.hpp>
#include <system.hpp>
#include <return.hpp>


using namespace wasm;


ACTION recursion_call::exec(int i)
{

    print("recursion_call enter:" + std::to_string(i));
    using contract_call_t = std::tuple<std::string,std::string,std::string,std::string>;
    std::string param = "[" + std::to_string(++i) + "]";
    contract_call_t call_info = std::make_tuple("recursion_call.wasm", "recursion_call.abi", "exec", param);

    auto serialize = pack(call_info);
    call(serialize.data(), serialize.size());

    
}




WASM_DISPATCH( recursion_call, (exec))
