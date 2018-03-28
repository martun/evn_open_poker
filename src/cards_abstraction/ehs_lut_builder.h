#pragma once
#include "../../third_party/SKPokerEval/src/SevenEval.h"
#include "ehs_lut_storage.h"
#include "cards_abstraction_provider.h"

// Class to build Look-Up Tables for EHS.
class EhsLutBuilder
{
public:
	EhsLutBuilder(std::shared_ptr<CardsAbstractionProvider>&,EhsLutStorage&);

	// Call to this function build all the required EHS and EHS squared tables.
	void buildPreflop();
	void buildAll();
	void buildFlop();
	void buildTurn();
	void buildRiver();
	void compute_insert_preflop(std::vector<Card>& hole_cards,std::vector<Card>& public_c);
	void compute_insert_flop(std::vector<Card>& public_cards);
	void compute_insert_turn(std::vector<Card>& public_cards);
	void compute_insert_river(std::vector<Card>& public_cards);
	void insert(double ehs, double ehs_squared,
				std::vector<Card>& hole_cards,
				std::vector<Card>& public_cards,
				std::unordered_map<uint32_t ,double >& ehs_table_out,
				std::unordered_map<uint32_t ,double >& ehs_squared_table_out);

private:
	std::shared_ptr<CardsAbstractionProvider>& abstractionProvider;
	EhsLutStorage storage;

};

