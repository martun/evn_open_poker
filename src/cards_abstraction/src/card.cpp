#include "card.h"

Card::Card(uint8_t card)
{
    card_=card;
}

Card::Card(uint8_t suit, uint8_t rank)
{
    card_=suit + rank * 4;
}
uint8_t Card:: get_suit() const{
    return uint8_t(card_%4);
}

uint8_t Card:: get_rank() const{
    return uint8_t(card_/4);
}

uint8_t Card:: get_card_num() const{
    return card_;
}