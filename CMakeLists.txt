cmake_minimum_required (VERSION 2.6)
project (Snippets)

set_property(GLOBAL PROPERTY USE_FOLDERS ON)

include_directories(.)

# To make folders in project
set(SIDDHARTA_RAO
    SiddhartaRao/BitOperations.hpp
)
source_group("SiddhartaRao" FILES ${SIDDHARTA_RAO})

if(MSVC)
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
  set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_DEBUG} /MTd")
else()
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
endif()



add_executable(${PROJECT_NAME} main.cpp)
