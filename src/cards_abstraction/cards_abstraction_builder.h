#pragma once

// This class builds Lookup Tables for cards isomorphism.
class CardsAbstractionBuilder
{
public:
	CardsAbstractionBuilder();

	// Once called this function must build all the required
	// Look-up tables, such that those tables can be used 
	// later by cards_abstraction_provider class.
	void build_all();

private:
	// Some look-up tables or LMDB handles over here.

};

