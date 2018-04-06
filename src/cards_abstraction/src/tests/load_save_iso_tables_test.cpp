#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"

TEST(CardsIsomorphismUnitTest, save_load_preflop_cards_test) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_preflop();
    std::string pref_table_str;
    storage->save_cards_to_string(storage->preflop_card_table
                                  , PREFLOP
                                  , pref_table_str
                                 );
    std::unordered_map<unsigned int,std::vector<Card>> pref_table;
    storage->load_cards_from_string(pref_table_str
                                    , PREFLOP
                                    , pref_table);

    auto itr = storage->preflop_card_table.begin();

    int count = 0;
    for( ; itr!=storage->preflop_card_table.end(); ++itr) {
        auto it = pref_table.find(itr->first);
        EXPECT_EQ(it->second[0].get_card_num()
                 ,itr->second[0].get_card_num());
        std::cout<< count <<"ok"<<std:: endl;
        count++;
    }
}

TEST(CardsIsomorphismUnitTest, save_load_index_preflop_test) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_preflop();
    std::string pref_table_str;
    storage->save_indexes_to_string(
            storage->preflop_index_table
            , pref_table_str
                                   );
    std::unordered_map<size_t, unsigned int> pref_table ;

    storage->load_indexes_from_string(
            pref_table_str
            , pref_table);

    auto itr = storage->preflop_index_table.begin();

    int count = 0;
    for (; itr != storage->preflop_index_table.end(); ++itr) {
        auto it = pref_table.find(itr->first);
        EXPECT_EQ(it->second
                  , itr->second);
        std::cout << count << "ok" << std::endl;
        count++;
    }
}

TEST(CardsIsomorphismUnitTest, save_load_turn_cards_test) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_turn();
    std::string turn_table_str;
    storage->save_cards_to_string(storage->turn_card_table
                                  , TURN
                                  , turn_table_str
                                 );
    std::unordered_map<unsigned int,std::vector<Card>> turn_table;
    storage->load_cards_from_string(turn_table_str
                                    , TURN
                                    , turn_table);

    auto itr = storage->turn_card_table.begin();

    int count = 0;
    for( ; itr!=storage->turn_card_table.end(); ++itr) {
        auto it = turn_table.find(itr->first);
        EXPECT_EQ(it->second[0].get_card_num()
                  ,itr->second[0].get_card_num());
        std::cout<< count <<"ok"<<std:: endl;
        count++;
    }
}

TEST(CardsIsomorphismUnitTest, save_load_index_turn_test) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_turn();
    std::string turn_table_str;
    storage->save_indexes_to_string(
            storage->turn_index_table
            , turn_table_str
                                   );
    std::unordered_map<size_t, unsigned int> turn_table ;

    storage->load_indexes_from_string(
            turn_table_str
            , turn_table);


    auto itr = storage->turn_index_table.begin();

    int count = 0;
    for (; itr != storage->turn_index_table.end(); ++itr) {
        auto it = turn_table.find(itr->first);
        EXPECT_EQ(it->second
                  , itr->second);
        std::cout << count << "ok" << std::endl;
        count++;
    }
}