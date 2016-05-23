cmake_minimum_required (VERSION 2.6)

PROJECT (Dragon)

set (CMAKE_CXX_FLAGS "-fPIC -fPIE -pie -std=c++11")
set (CMAKE_EXE_LINKER_FLAGS "-fPIC -fPIE -pie")

set (DRAGON_DIR "${PROJECT_SOURCE_DIR}")
set (DRAGON_MODULE_DIR "${DRAGON_DIR}/modules")
set (DRAGON_PUBLIC_INCLUDE_DIR "${DRAGON_DIR}/include")
set (DRAGON_TESTS_DIR "${DRAGON_DIR}/tests")
set (DRAGON_DOCS_DIR "${DRAGON_DIR}/docs")

# 添加公用头文件目录
include_directories (include)

# 添加命令行模块
add_subdirectory ("${DRAGON_MODULE_DIR}/Dragon")

# 添加对象模块
add_subdirectory ("${DRAGON_MODULE_DIR}/libDragonObjects")
