cmake_minimum_required(VERSION 3.16)


project(gesus
  VERSION 0.0
  LANGUAGES CXX
)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS "-Wall -O3")

set(CMAKE_AUTORCC ON)


find_package(Qt6 REQUIRED COMPONENTS Core)
find_package(Qt6 REQUIRED COMPONENTS Widgets)

qt_standard_project_setup()


qt_add_executable(gesus
  MANUAL_FINALIZATION
  gesus.cpp
)

set_target_properties(gesus PROPERTIES
  INTERPROCEDURAL_OPTIMIZATION   ON

  MACOSX_BUNDLE     ON
  WIN32_EXECUTABLE  ON
)


add_subdirectory(
  ui
)


target_link_options(gesus
  PUBLIC "-Wl,--gc-sections"
)

target_link_libraries(gesus PRIVATE
  gesus_ui
  Qt6::Widgets
)


qt_finalize_executable(gesus)


# WIP ----------------------

install(TARGETS gesus
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
#	SCRIPT  {???}
)

# qt_generate_deploy_app_script(
#     TARGET MyApp
#     OUTPUT_SCRIPT deploy_script
#     NO_UNSUPPORTED_PLATFORM_ERROR
# )
