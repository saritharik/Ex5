cmake_minimum_required(VERSION 3.8)
project(Ex5)

#set(CMAKE_CXX_STANDARD 98)
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpthread")
set(CMAKE_CXX_FLAGS -pthread)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(src lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)
set(SOURCE_FILES src/BoardConsole.cpp include/BoardConsole.h src/GameLogic.cpp include/GameLogic.h
        src/Point.cpp include/Point.h include/Board.h include/Player.h src/Human.cpp include/Human.h
        src/AI.cpp include/AI.h src/Game.cpp include/Game.h include/UserInterface.h
        include/UserPrinterConsole.h src/UserPrinterConsole.cpp include/Remote.h src/Remote.cpp
        include/Client.h src/Client.cpp include/VirtualRemote.h src/VirtualRemote.cpp)
set(TEST_FILES tests/BoardTest.cpp
        tests/BoardTest.h tests/AITest.cpp tests/AITest.h tests/HumanTest.cpp tests/HumanTest.h
        tests/PointTest.cpp tests/PointTest.h  tests/GameLogicTest.cpp tests/GameLogicTest.h)
set(SERVER_FILES server/Server.cpp server/Server.h server/ServerPrinter.cpp server/ServerPrinter.h server/Command.h server/CommandsManager.cpp server/CommandsManager.h server/StartCommand.cpp server/StartCommand.h server/ListGamesCommand.cpp server/ListGamesCommand.h server/JoinCommand.cpp server/JoinCommand.h server/ClientHandler.cpp server/ClientHandler.h server/GameSettings.h server/ThreadArgs.cpp server/ThreadArgs.h server/ThreadPool.cpp server/ThreadPool.h server/Task.cpp server/Task.h)

add_executable(Ex5 ${SOURCE_FILES} src/main.cpp)
add_executable(tests ${SOURCE_FILES} ${TEST_FILES} tests/gtest_main.cpp)
add_executable(server ${SOURCE_FILES} ${SERVER_FILES} server/server_main.cpp)

target_link_libraries(tests gtest gtest_main gmock)