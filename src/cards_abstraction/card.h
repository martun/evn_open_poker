#pragma once
#include <stdint.h>



class Card
{
public:
	Card(uint8_t card);
	Card(uint8_t suit, uint8_t rank);
	/// Returns the suit of the card, a number from range [0..3].
	uint8_t get_suit() const;

	/// Returns the rank of the card, a number from range [0..12].
	uint8_t get_rank() const;

	uint8_t get_card_num() const;

	Card operator==(const Card& other) const{

		return this->card_==other.card_;
	}

	Card operator++(){
		card_++;
		return *this;
	}
private:
	// Stores the card number in it, a number from 0..52, where the last 2 bits show the suit.
	uint8_t card_;

};

