#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"

TEST(CardsIsomorphismUnitTest, save_to_file_load_test) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_all();
    storage->save("cardsAbstractionLUTs.bin");
    auto tStorage = std::make_shared<CardsAbstractionStorage>();
    tStorage->load("cardsAbstractionLUTs.bin");
//    auto itr = storage->preflop_card_table.begin();
//    uint8_t first = itr->second[0].get_card_num();
    std::unordered_map<unsigned int,std::vector<Card>> test=tStorage->preflop_card_table;
    std::cout<<test.begin()->first;
//    while (itr !=  storage->preflop_card_table.end())
//    {
//        EXPECT_EQ(first,second);
//      ++itr;
//    }
//
//     itr = storage->flop_card_table.begin();
//    while (itr !=  storage->preflop_card_table.end())
//    {
//        EXPECT_EQ(itr->second[0].get_card_num()
//                  ,tStorage->flop_card_table.find(itr->first)->second[0].get_card_num());
//        ++itr;
//    }
//
//    itr = storage->turn_card_table.begin();
//    while (itr !=  storage->preflop_card_table.end())
//    {
//        EXPECT_EQ(itr->second[0].get_card_num()
//                  ,tStorage->turn_card_table.find(itr->first)->second[0].get_card_num());
//        ++itr;
//    }
//
//    itr = storage->river_card_table.begin();
//    while (itr !=  storage->preflop_card_table.end())
//    {
//        EXPECT_EQ(itr->second[0].get_card_num()
//                  ,tStorage->river_card_table.find(itr->first)->second[0].get_card_num());
//        ++itr;
//    }
}