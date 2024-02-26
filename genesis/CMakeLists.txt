cmake_minimum_required(VERSION 3.16)


project(gesus_genesis
  LANGUAGES CXX
)


set(
  CMAKE_CXX_STANDARD          23
  CMAKE_CXX_STANDARD_REQUIRED ON
)

set(
  CMAKE_CXX_FLAGS_RELEASE_INIT "-Wall -O3"
  CMAKE_CXX_FLAGS_DEBUG_INIT   "-Wall -g -pg"
)

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

target_link_libraries(gesus_genesis PRIVATE
  Qt6::Core
  Qt6::Widgets
)
