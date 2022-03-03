#include <call.hpp>
#include <tuple>
#include <string>

#include <inline_transaction.hpp>
#include <system.hpp>
#include <return.hpp>


using namespace wasm;




template<typename T>
T get_return_wasm(uint64_t size){
    T return_value = wasm::unpack<T>(get_return(size));
    return return_value;
}

ACTION call_contract::get_ret()
{

    using contract_call_t = std::tuple<std::string,std::string,std::string,std::string>;
    contract_call_t call_info = std::make_tuple("return_value.wasm", "return_value.abi", "ret_int", R"([])");


    auto serialize = pack(call_info);

    print("call.wasm call before");
    uint64_t ret_len = call(serialize.data(), serialize.size());
    print("call.wasm call end");
    print("call.wasm call ret_len:" + std::to_string(ret_len));

    int64_t return_value = get_return_wasm<int64_t>(ret_len);

    
    print("call: call return_value is:" + std::to_string(return_value));
}


ACTION call_contract::get_ret2()
{

    using contract_call_t = std::tuple<std::string,std::string,std::string,std::string>;
    contract_call_t call_info = std::make_tuple("return_value.wasm", "return_value.abi", "ret_int", R"([])");


    auto serialize = pack(call_info);
    int64_t return_value = call_with_return(serialize.data(), serialize.size());

    print("call: call_with_return return_value is:" + std::to_string(return_value));
}


WASM_DISPATCH( call_contract, (get_ret)(get_ret2))
