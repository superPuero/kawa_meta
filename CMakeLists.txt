cmake_minimum_required(VERSION 3.15)

project(kawa_meta LANGUAGES CXX)

add_library(kawa_meta INTERFACE)
add_library(kawa_meta::kawa_meta ALIAS kawa_meta)

target_include_directories(kawa_meta INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

target_compile_features(kawa_meta INTERFACE cxx_std_17)