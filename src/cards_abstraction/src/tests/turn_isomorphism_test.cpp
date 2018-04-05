#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"

TEST(CardsIsomorphismUnitTest, turn_test_1) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_turn();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,1));
    hole_cards.push_back(Card(0,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,0));
    public_cards1.push_back(Card(3,12));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,1));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(0,1));
    public_cards2.push_back(Card(0,12));
    public_cards2.push_back(Card(0,0));
    public_cards2.push_back(Card(0,4));


    CardsAbstractionProvider provider(storage);

    // Verify that hole_cards1 and hole_cards2 are isomorphic in preflop.
    EXPECT_EQ(provider.get_hand_iso_number(hole_cards, public_cards1),
              provider.get_hand_iso_number(hole_cards, public_cards2));
}


TEST(CardsIsomorphismUnitTest, turn_test_2) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_turn();
    std::vector<Card> hole_cards1;
    hole_cards1.push_back(Card(0,1));
    hole_cards1.push_back(Card(0,3));
    std::vector<Card> public_cards;
    public_cards.push_back(Card(3,0));
    public_cards.push_back(Card(3,12));
    public_cards.push_back(Card(3,4));
    public_cards.push_back(Card(3,1));

    std::vector<Card> hole_cards2;
    hole_cards2.push_back(Card(0,1));
    hole_cards2.push_back(Card(3,3));

    CardsAbstractionProvider provider(storage);

    // Verify that hole_cards1 and hole_cards2 with public_cards
    // are not  isomorphic in turn.
    EXPECT_NE(provider.get_hand_iso_number(hole_cards1, public_cards),
              provider.get_hand_iso_number(hole_cards2, public_cards));
}

