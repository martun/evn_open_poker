#include "../cards_abstraction_provider.h"

CardsAbstractionProvider::CardsAbstractionProvider()
{
}

uint32_t CardsAbstractionProvider::get_public_cards_iso_number(const std::vector<Card>& public_cards){
    std::vector<std::vector<uint8_t >> possible_combination;
    possible_combination.resize(4);
    for(int i=0;i<public_cards.size();i++){
        CardsAbstractionHelper::add_card(&public_cards[i],&possible_combination);
    }
    CardsAbstractionHelper::sort_vector(&possible_combination);
    CardsAbstractionHelper::erase_emptys(&possible_combination);
    size_t hash_=CardsAbstractionHelper::hash(&possible_combination);
    auto search=storage.flop_index_table.find(hash_);
    switch(public_cards.size()){
        case 3:
            search=storage.flop_index_table.find(hash_);
            break;
        case 4:
            search=storage.turn_index_table.find(hash_);
            break;
        case 5:
            search=storage.river_index_table.find(hash_);
    }
    return search->second;
}

void CardsAbstractionProvider::get_canonical_public_cards(
        uint32_t iso_number, Round round_,std::vector<Card>& public_cards_out)
{
    auto search= storage.flop_card_table.find(iso_number);;

    switch(round_) {
        case FLOP :
            search = storage.flop_card_table.find(iso_number);
            break;

        case TURN:
            search = storage.turn_card_table.find(iso_number);
            break;
        case RIVER:
            search = storage.flop_card_table.find(iso_number);
    }
    std::vector<std::vector<uint8_t >> c=search->second;
    for(uint8_t i=0;i<c.size();++i) {
        if(!c[i].empty()) {
            for (uint8_t j = 0; j < c[i].size(); ++j) {
               Card *card_ = new Card((uint8_t) i * 4 + j);
//                public_cards_out.insert(card_)
            }
        }
    }
}

