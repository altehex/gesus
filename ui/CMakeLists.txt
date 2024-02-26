cmake_minimum_required(VERSION 3.16)


project(gesus_ui
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


qt_add_library(gesus_ui STATIC
  main_window.cpp
  main_window_slots.cpp
  main_window.hpp
  palette_editor.hpp
  plane_editor.hpp
  sprite_editor.hpp
  stash.hpp
  stash.cpp
  tile_editor.cpp
  tile_editor.hpp

  about.cpp
  about.hpp
  settings.hpp

  draw.cpp
  draw.hpp
  style.cpp
  style.hpp
)

set_target_properties(gesus_ui PROPERTIES
  INTERPROCEDURAL_OPTIMIZATION   ON
)


target_link_options(gesus_ui
  PUBLIC "-Wl,--gc-sections"
)

target_link_libraries(gesus_ui PRIVATE
  gesus_genesis
  Qt6::Core
  Qt6::Widgets
)

