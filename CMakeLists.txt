cmake_minimum_required(VERSION 3.16)
project(PeerChat LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_AUTOMOC TRUE)

set(OPENGL_gl_LIBRARY /usr/lib64/libGL.so)
set(OPENGL_glx_LIBRARY /usr/lib64/libGLX.so)
set(OPENGL_INCLUDE_DIR /usr/include/GL)

find_package(Qt6 COMPONENTS Widgets REQUIRED)
find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Gui)

qt_add_executable(chat_client
    src/apps/ClientApp.cpp
    src/libs/Models/User.cpp
    src/libs/Models/Message.cpp
    src/gui/ChatWindow.h
    src/gui/ChatWindow.cpp
    src/libs/Network/Consumer.cpp
    src/libs/Network/Consumer.h
    src/libs/Network/Producer.cpp
    src/libs/Network/Producer.h
)

add_executable(chat_server
    src/apps/ChatServer.cpp
)

target_link_libraries(chat_client PRIVATE Qt6::Widgets)
target_link_libraries(chat_client PRIVATE Qt6::Core)
target_link_libraries(chat_client PRIVATE Qt6::Gui)

target_include_directories(chat_client PRIVATE
    src/libs
    /usr/local/include
    /usr/include/GL
)

target_link_libraries(chat_client PRIVATE
    /usr/local/lib/libzmqpp.so
    /usr/local/lib/libzmq.so
    /usr/lib64/libGL.so
)

target_include_directories(chat_server PRIVATE
    src/libs
    /usr/local/include
    /usr/include/boost
)

target_link_libraries(chat_server PRIVATE
    /usr/local/lib/libzmqpp.so
    /usr/local/lib/libzmq.so
)

target_compile_definitions(chat_client PUBLIC ZMQ_BUILD_DRAFT_API)
target_compile_definitions(chat_server PUBLIC ZMQ_BUILD_DRAFT_API)
