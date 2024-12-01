cmake_minimum_required(VERSION 3.29)
project(website)

set(CMAKE_CXX_STANDARD 20)

add_executable(website main.cpp
        User.cpp
        User.h
        Post.cpp
        Post.h
        Socialmediaplatform.cpp
        Socialmediaplatform.h)
