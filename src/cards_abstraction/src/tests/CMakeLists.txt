
add_executable(preflop_isomorphism_test
  test_main.cpp
  preflop_isomorphism_test.cpp)

target_link_libraries(preflop_isomorphism_test
  BucketingLib
  gtest)

