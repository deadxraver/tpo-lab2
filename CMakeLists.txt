project(tpo-lab2)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.tar.gz
)
FetchContent_MakeAvailable(googletest)

add_library(math_lib src/math.cpp)

add_executable(count src/main.cpp)
target_link_libraries(count math_lib)

enable_testing()

add_executable(base_math_test test/base_test.cpp)
target_link_libraries(base_math_test GTest::gtest_main GTest::gmock math_lib)
target_include_directories(base_math_test PRIVATE src)
add_test(BASE_MATH_TEST base_math_test)
