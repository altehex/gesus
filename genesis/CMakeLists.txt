cmake_minimum_required(VERSION 3.16)


project(gesus_genesis
  LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -O3")

set(CMAKE_AUTORCC ON)


qt_standard_project_setup()


qt_add_library(gesus_genesis STATIC
  genesis_color.cpp
  genesis_color.hpp
  genesis_tile.cpp
  genesis_tile.hpp
)

set_target_properties(gesus_genesis PROPERTIES
  INTERPROCEDURAL_OPTIMIZATION   ON
)


target_link_options(gesus_genesis
  PUBLIC "-Wl,--gc-sections"
)

target_link_libraries(gesus_genesis PRIVATE Qt6::Core)
target_link_libraries(gesus_genesis PRIVATE Qt6::Widgets)


target_include_directories(gesus_genesis INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

