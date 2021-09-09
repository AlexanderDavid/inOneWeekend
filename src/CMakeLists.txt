find_package(fmt REQUIRED)
find_package(Eigen3  3.4 REQUIRED)

add_library(inOneWeekend_lib
    "../include/color.hh"
    "../include/ray.hh"
    "../include/Hittable.hh"
    "../include/HittableList.hh"
    color.cc
    ray.cc
    Hittable.cc
    HittableList.cc)
add_library(inOneWeekend::lib ALIAS inOneWeekend_lib)
target_link_libraries(inOneWeekend_lib PUBLIC
  cmake_cpp_boilerplate::compiler_options
  fmt::fmt
  Eigen3::Eigen)
target_include_directories(inOneWeekend_lib PUBLIC "${PROJECT_SOURCE_DIR}/include")

if(${BP_BUILD_TESTS_COVERAGE})
    target_compile_options(inOneWeekend_lib PUBLIC -fprofile-arcs -ftest-coverage)
    target_link_libraries(inOneWeekend_lib PUBLIC gcov)
endif()

add_executable(inOneWeekend main.cc)
target_link_libraries(inOneWeekend PRIVATE inOneWeekend::lib)
