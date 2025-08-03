<h1 align="center">Live Chat</h1>

A simple chat application to practice ZMQ and Qt.

## Build and Run

#### Client

```sh
$ mkdir build
$ cmake -B build -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -DCMAKE_BUILD_TYPE=Debug
$ cmake build --build
$ ./build/bin/live_chat_client
```

#### Server

```sh
$ cmake build --build
$ ./build/bin/live_chat_server
```
