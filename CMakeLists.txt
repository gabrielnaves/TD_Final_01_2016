cmake_minimum_required(VERSION 2.6)
project(Gossip)

file(GLOB_RECURSE sources src/*.cpp)

add_executable(gossip ${sources})
target_compile_options(gossip PUBLIC -std=c++11 -Wall)
