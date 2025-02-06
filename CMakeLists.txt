# CMakeLists.txt - root file for Zephyr freestanding project
cmake_minimum_required(VERSION 3.20.0)

# ZEPHYR_BASE is defined in zephyr-env.sh script
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(zephyr_basic)

target_sources(app PRIVATE src/main.c)
