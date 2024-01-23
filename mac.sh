#!bin/sh
# Shell script which do build up for runnig
brew install boost
mkdir build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Release -DOPENSSL_ROOT_DIR=/opt/homebrew/opt/openssl/ -DCMAKE_INSTALL_PREFIX:PATH=../tdlib -DTD_ENABLE_LTO=ON ../td
cmake --build . --target install
cd ../cpp
mkdir build
cd ./build
cmake -DCMAKE_BUILD_TYPE=Release -DTd_DIR=<full path to TdCloud sources>/tdlib/lib/cmake/Td ..
cmake --build .