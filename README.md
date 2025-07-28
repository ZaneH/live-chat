<h1 align="center">Peer Chat</h1>

A simple chat application to practice ZMQ and Qt.

## Build and Run

``` sh
$ mkdir build
$ cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
$ cmake build --build
$ ./build/bin/chat_client
```
