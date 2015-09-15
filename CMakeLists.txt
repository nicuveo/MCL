# project

project(MCL)

cmake_minimum_required(VERSION 2.8.12)



# compil

set(CMAKE_CXX_FLAGS         "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -Wextra -pedantic")
set(CMAKE_CXX_FLAGS_DEBUG   "${CMAKE_CXX_FLAGS_DEBUG} -O0 -pg -g3 -ggdb3 -DDEBUG -coverage")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Werror -O3 -DNDEBUG")

include_directories(include src)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif(NOT CMAKE_BUILD_TYPE)



# library

file(GLOB_RECURSE CXXFILES src/*.cc)
add_library(mcl STATIC ${CXXFILES})



# tools

file(GLOB_RECURSE CLCC_FILES tools/clcc/*.cc)
file(GLOB_RECURSE CLCD_FILES tools/clcd/*.cc)
file(GLOB_RECURSE CLCT_FILES tools/clct/*.cc)

add_executable(clcc ${CLCC_FILES})
add_executable(clcd ${CLCD_FILES})
add_executable(clct ${CLCT_FILES})

target_include_directories(clcc PRIVATE tools/clcc)
target_include_directories(clcd PRIVATE tools/clcd)
target_include_directories(clct PRIVATE tools/clct)

target_link_libraries(clcc mcl boost_program_options)
target_link_libraries(clcd mcl boost_program_options)
target_link_libraries(clct mcl boost_program_options)



# tests

file(GLOB_RECURSE TESTFILES check/*.cc)
file(GLOB_RECURSE ANAFILES  src/* include/*)
add_executable(tests ${TESTFILES})
target_link_libraries(tests mcl --coverage)

add_custom_target(run_tests
    COMMAND ./tests
    DEPENDS tests
    COMMENT "running tests")

add_custom_target(run_analysis
    COMMAND ${PROJECT_SOURCE_DIR}/scripts/analysis
            -I ${PROJECT_SOURCE_DIR}/include
            -I ${PROJECT_SOURCE_DIR}/src
            ${ANAFILES}
    COMMENT "running code analysis")

add_custom_target(run_coverage
    COMMAND ${PROJECT_SOURCE_DIR}/scripts/coverage .
            ${PROJECT_SOURCE_DIR}/doc/coverage
            ${PROJECT_SOURCE_DIR}/include
            ${PROJECT_SOURCE_DIR}/src
    DEPENDS run_tests
    COMMENT "generating coverage report")

if(CMAKE_BUILD_TYPE MATCHES debug)
  add_custom_target(check DEPENDS run_tests run_analysis run_coverage)
else()
  add_custom_target(check DEPENDS run_tests)
endif()



# install

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/nauths DESTINATION include)
install(TARGETS mcl  DESTINATION lib)
install(TARGETS clcc DESTINATION bin)
install(TARGETS clcd DESTINATION bin)
install(TARGETS clct DESTINATION bin)



# misc

add_custom_target(flower COMMAND cat ${PROJECT_SOURCE_DIR}/scripts/flower)
