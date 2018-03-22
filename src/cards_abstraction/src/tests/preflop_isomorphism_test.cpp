#include <gtest/gtest.h>
#include <gmock/gmock.h>

#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
#include "cards_abstraction_provider.h"
#include "card.h"
#include <iostream>
#include <stdint.h>
#include <string>
#include <memory>
#include <vector>

TEST(CardsIsomorphismUnitTest, preflop_test_1) {
  auto storage = std::make_shared<CardsAbstractionStorage>();
  CardsAbstractionBuilder builder(*storage);
  builder.build_preflop();
  std::vector<Card> hole_cards1;
  hole_cards1.push_back(Card(1));
  hole_cards1.push_back(Card(3));

  std::vector<Card> hole_cards2;
  hole_cards1.push_back(Card(1+13));
  hole_cards1.push_back(Card(3+13));

  std::vector<Card> public_cards;

  CardsAbstractionProvider provider(storage);

  // Verify that hole_cards1 and hole_cards2 are isomorphic in preflop.
  EXPECT_EQ(provider.get_hand_iso_number(hole_cards1, public_cards), 
    provider.get_hand_iso_number(hole_cards2, public_cards));
}

