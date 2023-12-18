# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(GameConsole)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(GameConsole
        src/GameBase.cpp
        src/SnakeGame.cpp
        src/PongGame.cpp
        src/Renderer.cpp
        src/InputManager.cpp
        src/AudioManager.cpp
        src/GameRegistry.cpp
        main.cpp)

