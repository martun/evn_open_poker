#pragma once


#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "card.h"
#include "cards_abstraction_storage.h"
#include "card_abstraction_helper.h"

// This class builds Lookup Tables for cards isomorphism.
class CardsAbstractionBuilder
{
public:
	CardsAbstractionBuilder(CardsAbstractionStorage&);
  // Once called this function must build all the required
	// Look-up tables, such that those tables can be used
	// later by cards_abstraction_provider class.
	void build_all();
	void build_preflop();
	void build_flop();
	void build_turn();
	void build_river();

	const CardsAbstractionStorage& getStorage() const;


private:
  CardsAbstractionStorage storage;

};


