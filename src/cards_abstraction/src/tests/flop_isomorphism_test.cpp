#include <gtest/gtest.h>
//#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"

TEST(CardsIsomorphismUnitTest, flop_test_1) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_flop();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,3));
    hole_cards.push_back(Card(1,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,2));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,5));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(2,4));
    public_cards2.push_back(Card(2,2));
    public_cards2.push_back(Card(2,5));

    CardsAbstractionProvider provider(storage);

    // Verify that  public_cards1
    // and  public_cards_2 are isomorphic in flop.
    EXPECT_EQ(provider.get_hand_iso_number(hole_cards, public_cards2),
              provider.get_hand_iso_number(hole_cards, public_cards1));
}


TEST(CardsIsomorphismUnitTest, flop_test_2) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_flop();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,3));
    hole_cards.push_back(Card(1,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,2));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,5));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(2,4));
    public_cards2.push_back(Card(2,2));
    public_cards2.push_back(Card(2,5));

    std::vector<Card> hole_cards1;
    hole_cards1.push_back(Card(2,3));
    hole_cards1.push_back(Card(3,3));

    CardsAbstractionProvider provider(storage);

    // Verify that hole_cards1
    // and hole_cards2, with public_cards_1 and public_cards_2
    // are not isomorphic in flop.
    EXPECT_NE(provider.get_hand_iso_number(hole_cards, public_cards2),
              provider.get_hand_iso_number(hole_cards1, public_cards1));
}

TEST(CardsIsomorphismUnitTest, flop_test_3) {
    auto storage = std::make_shared<CardsAbstractionStorage>();
    CardsAbstractionBuilder builder(*storage);
    builder.build_flop();
    std::vector<Card> hole_cards;
    hole_cards.push_back(Card(0,3));
    hole_cards.push_back(Card(1,3));
    std::vector<Card> public_cards1;
    public_cards1.push_back(Card(3,2));
    public_cards1.push_back(Card(3,4));
    public_cards1.push_back(Card(3,5));

    std::vector<Card> public_cards2;
    public_cards2.push_back(Card(2,6));
    public_cards2.push_back(Card(2,2));
    public_cards2.push_back(Card(2,4));

    CardsAbstractionProvider provider(storage);

    // Verify that  public_cards1
    // and  public_cards_2 are not isomorphic in flop.
    EXPECT_NE(provider.get_hand_iso_number(hole_cards, public_cards2),
              provider.get_hand_iso_number(hole_cards, public_cards1));
}



