# TdCloud <img src="images/logo.jpeg" width=40 height=40>

## Introduction
Recently I faced with problem: the amount of memory in my iCloud and Google Drive is less than 15Gb. So, it's hard to back up even photos. 
Although, Telegram has open-source API TDLib, which allow me to send and upload files/photos to chats. 
This inspired me to implement CLI script, which could back up any folders and files from laptop, because Telegram has unlimited storage.
## Build instruction
### MacOs
Make sure that you've installed boost and glog. Also, if you faced problems while building tdlib  visit [TDLib instruction](https://tdlib.github.io/td/build.html?language=C%2B%2B)
```
<Enter TdCloud directory>
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release -DOPENSSL_ROOT_DIR=/opt/homebrew/opt/openssl/ -DCMAKE_INSTALL_PREFIX:PATH=../tdlib -DTD_ENABLE_LTO=ON ../td
$ cmake --build . --target install
$ cd ../cpp
$ mkdir build
$ cd build
$ cmake -DCMAKE_BUILD_TYPE=Release -DTd_DIR=<full path to TdCloud sources>/tdlib/lib/cmake/Td ..
$ cmake --build .
```
## TODO
- [ ] Improve the build time `cmake --build .`
- [ ] Add build scheme for other platforms
- [ ] Add Logging(glog)
## Libraries
- TDLib(https://github.com/tdlib/td)
- boost(boost::filesystem)
- glog(https://github.com/google/glog)
