cmake_minimum_required(VERSION 3.13)

project(lfs)

add_library(lfs lfs.c lfs.h lfs_util.c lfs_util.h)

target_link_libraries( lfs 
    pico_stdlib
)