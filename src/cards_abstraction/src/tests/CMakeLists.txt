enable_testing()
add_test(
        NAME preflop_isomorphism_test1
        COMMAND preflop_isomorphism_test preflop_test_1
)

add_test(
        NAME preflop_isomorphism_test2
        COMMAND preflop_isomorphism_test preflop_test_2
)


add_test(
        NAME flop_isomorphism_test1
        COMMAND flop_isomorphism_test flop_test_1
)

add_test(
        NAME flop_isomorphism_test2
        COMMAND flop_isomorphism_test flop_test_2
)

add_test(
        NAME flop_isomorphism_test3
        COMMAND flop_isomorphism_test flop_test_3
)


add_test(
        NAME turn_isomorphism_test1
        COMMAND turn_isomorphism_test turn_test_1
)

add_test(
        NAME turn_isomorphism_test2
        COMMAND turn_isomorphism_test turn_test_2
)

add_test(
        NAME river_isomorphism_test1
        COMMAND river_isomorphism_test river_test_1
)

add_test(
        NAME river_isomorphism_test2
        COMMAND river_isomorphism_test river_test_2
)


add_executable(preflop_isomorphism_test
  test_main.cpp
  preflop_isomorphism_test.cpp
)

target_link_libraries(preflop_isomorphism_test
  BucketingLib
  gtest
)

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
gtest
)

add_test(
        NAME save_load_preflop_cards_test
        COMMAND load_save_iso_tables_test save_load_preflop_cards_test
)

add_test(
        NAME save_load_index_preflop_test
        COMMAND load_save_iso_tables_test save_load_index_preflop_test
)

add_test(
        NAME save_load_turn_cards_test
        COMMAND load_save_iso_tables_test save_load_turn_cards_test
)

add_test(
        NAME save_load_index_turn_test
        COMMAND load_save_iso_tables_test save_load_index_turn_test
)


add_executable(load_save_iso_tables_test
        test_main.cpp
        load_save_iso_tables_test.cpp
        )
target_link_libraries(load_save_iso_tables_test
        BucketingLib
        gtest
        )



add_executable(save_to_file_load_test
        test_main.cpp
        Save_To_file_load_test.cpp
        )
target_link_libraries(save_to_file_load_test
        BucketingLib
        gtest
        )
