
WASM.CDT是一个用于WebAssembly (WASM)的工具链，以及一组用于促进WASM平台合同编写的工具。除了作为一个通用的WebAssembly工具链，WASM.cdt特有的优化可用于支持构建WASM智能合约。这个新的工具链是围绕Clang 7构建的，这意味着WASM.CDT具有来自LLVM的最新优化和分析。

## 一、目录结构
* libraries 合约引用的库的头文件、源文件
* examples  合约示例
* modules   和cmake相关的编译工具文件
* tools    wasm编译工具文件
* wasm_llvm   llvm的工程
* wasm_llvm/lib/Target/WebAssembly  wasm的编译器前后端

  

## 二、编译安装
注意事项：
* 1.配置最低4核8G
* 2.若是虚拟机的话不要共享目录中安装

直接用cmake直接安装
```
mkdir build
cmake ..
make
make install
```


编译好之后需要进行安装，安装的路径为`/usr/local/wasm.cdt`
内容包括：
```
1.头文件  /usr/local/wasm.cdt/include 
2.静态库 /usr/local/wasm.cdt/lib 
3.二进制程序 /usr/local/wasm.cdt/lib  
4.cmake编译时用到的文件 /usr/local/lib/cmake/wasm.cdt 
```


### 安装后的二进制工具
* wasm-cpp
* wasm-cc
* wasm-lld
* wasm2wast
* wast2wasm
* wasm-ranlib
* wasm-ar


## 三、编译合约文件
可以参考eos官方文档
https://developers.eos.io/manuals/eosio.cdt/latest/how-to-guides/compile/compile-a-contract-via-cli

### 编译方式
#### 1.用wasm-cc、wasm-cpp工具链直接编
```
wasm-cpp -abigen ../src/hello.cpp -o hello.wasm -I ../include/
```

#### 2.用cmake编译
```
$ cd examples/hello
$ mkdir build
$ cd build
$ cmake ..
$ make
```

