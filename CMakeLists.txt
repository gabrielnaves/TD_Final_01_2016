cmake_minimum_required(VERSION 2.6)
project(Gossip)

file(GLOB_RECURSE sources src/*.c)

add_executable(gossip ${sources})
target_compile_options(gossip PUBLIC -ansi -Wall)
target_include_directories(gossip PUBLIC src)
