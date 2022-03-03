#include <return_value.hpp>
#include "inline_transaction.hpp"
#include "return.hpp"
#include <string>



ACTION2 return_value::ret_int()
{
    int64_t i = 33;
    print("return_value.wasm set_return before");
    set_return(wasm::pack(i));
    print("return_value.wasm set_return end");
    return 22;
}



extern "C" {
   int64_t apply( uint64_t receiver, uint64_t code, uint64_t action ) {
       //if(code == receiver || code == wasmio_bank.value ){
           switch( action ) { 
             case wasm::name( "ret_int" ).value: 
                return wasm::execute_action_with_return( wasm::regid(receiver), wasm::regid(code), &return_value::ret_int ); 
                 break;
             default:
                 check(false, "action did not exist!");
                 break;
           }
       //}

       return 0;
   }
}