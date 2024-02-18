cmake_minimum_required(VERSION 3.16)


project(gesus_ui
  LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -O3")

set(CMAKE_AUTORCC ON)


qt_standard_project_setup()


qt_add_library(gesus_ui STATIC
  main_window.cpp
  main_window.hpp
  tile_editor.hpp
  palette_editor.hpp
  plane_editor.hpp
  sprite_editor.hpp
  settings.hpp
)

set_target_properties(gesus_ui PROPERTIES
  INTERPROCEDURAL_OPTIMIZATION   ON
)


target_link_options(gesus_ui
  PUBLIC "-Wl,--gc-sections"
)

target_link_libraries(gesus_ui PRIVATE Qt6::Core)
target_link_libraries(gesus_ui PRIVATE Qt6::Widgets)


target_include_directories(gesus_ui INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})


