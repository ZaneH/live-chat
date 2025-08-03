<h1 align="center">Live Chat</h1>

<div align="center">
  A simple chat application to practice ZMQ and Qt.
  <br />
  <br />
  <img width="650" height="382" alt="Screenshot_20250803_173823" src="https://github.com/user-attachments/assets/6c4d10e5-fc7d-47c3-a7d4-b86195e28681" />
</div>

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
