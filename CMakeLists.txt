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
