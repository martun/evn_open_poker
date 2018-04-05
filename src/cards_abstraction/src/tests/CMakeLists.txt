enable_testing()
add_test(
        NAME preflop_isomorphism_test
        COMMAND preflop_isomorphism_test
)

add_test(
        NAME flop_isomorphism_test
        COMMAND flop_isomorphism_test
)

add_test(
        NAME turn_isomorphism_test
        COMMAND turn_isomorphism_test
)

add_test(
        NAME river_isomorphism_test
        COMMAND river_isomorphism_test
)

add_executable(preflop_isomorphism_test
  test_main.cpp
  preflop_isomorphism_test.cpp
        )

target_link_libraries(preflop_isomorphism_test
  BucketingLib
  gtest)

add_executable(flop_isomorphism_test
    test_main.cpp
    flop_isomorphism_test.cpp
)

target_link_libraries(flop_isomorphism_test
BucketingLib
gtest)


add_executable(turn_isomorphism_test
test_main.cpp
turn_isomorphism_test.cpp
)

target_link_libraries(turn_isomorphism_test
BucketingLib
gtest)

add_executable(river_isomorphism_test
test_main.cpp
river_isomorphism_test.cpp
)

target_link_libraries(river_isomorphism_test
BucketingLib
gtest)