#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"

TEST(CardsIsomorphismUnitTest, river_test_1) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_river();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,1));
    hole_cards.push_back(Card(0,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,0));
    public_cards1.push_back(Card(3,12));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,1));
    public_cards1.push_back(Card(3,9));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(0,1));
    public_cards2.push_back(Card(0,12));
    public_cards2.push_back(Card(0,0));
    public_cards2.push_back(Card(0,9));
    public_cards2.push_back(Card(0,4));


    CardsAbstractionProvider provider(storage);

    // Verify that hole_cards1 and hole_cards2 are isomorphic in preflop.
    EXPECT_EQ(provider.get_hand_iso_number(hole_cards, public_cards1),
              provider.get_hand_iso_number(hole_cards, public_cards2));
}


TEST(CardsIsomorphismUnitTest, river_test_2) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_river();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,1));
    hole_cards.push_back(Card(0,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,0));
    public_cards1.push_back(Card(3,12));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,1));
    public_cards1.push_back(Card(3,9));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(0,1));
    public_cards2.push_back(Card(1,12));
    public_cards2.push_back(Card(0,0));
    public_cards2.push_back(Card(0,9));
    public_cards2.push_back(Card(0,4));


    CardsAbstractionProvider provider(storage);

    // Verify that hole_cards1 and hole_cards2 are not isomorphic in river.
    EXPECT_NE(provider.get_hand_iso_number(hole_cards, public_cards1),
              provider.get_hand_iso_number(hole_cards, public_cards2));
}
