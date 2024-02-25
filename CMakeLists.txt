cmake_minimum_required(VERSION 3.16)


project(gesus
  VERSION 0.0
  LANGUAGES CXX
)


set(
  CMAKE_CXX_STANDARD 23
  CMAKE_CXX_STANDARD_REQUIRED ON
)

set(CMAKE_CXX_FLAGS "-Wall -O3")

set(CMAKE_AUTORCC ON)


set(GESUS_PROJECT_VERSION ${PROJECT_VERSION})


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

add_compile_definitions(
  GESUS_APP_NAME="gesus"
  GESUS_VERSION=${GESUS_PROJECT_VERSION}
)


target_link_options(gesus
  PUBLIC "-Wl,--gc-sections"
)

target_link_libraries(gesus PRIVATE
  gesus_ui
  Qt6::Widgets
)


add_subdirectory(genesis)
add_subdirectory(ui)


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
