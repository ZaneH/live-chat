cmake_minimum_required(VERSION 3.16)
project(ChatApp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(chat_client
    src/apps/ClientApp.cpp
    src/libs/Models/User.cpp
    src/libs/Models/Message.cpp
)

target_include_directories(chat_client PRIVATE
    src/libs
)
