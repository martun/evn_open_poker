#include "../cards_abstraction_builder.h"

#include <stdint.h>
#include "vector"
#include "../Utils.h"
#include "../card.h"

CardsAbstractionBuilder::CardsAbstractionBuilder()
{
}
void CardsAbstractionBuilder::build_all(){
    build_flop();
    build_turn();
    build_river();
    storage.save();
}

void CardsAbstractionBuilder::build_flop(){
    uint32_t index=0;
    for (int i = 0; i < CARDS; i++) {
            Card* card_1=new Card(i);
        for (int j = i + 1; j < CARDS; j++) {
            Card* card_2=new Card(j);
            for (int k = j + 1; k < CARDS; k++) {
                Card* card_3=new Card(k);
                std::vector<std::vector<uint8_t >> possible_combination;
                possible_combination.resize(4);
                CardsAbstractionHelper::add_card(card_1,&possible_combination);
                CardsAbstractionHelper::add_card(card_2,&possible_combination);
                CardsAbstractionHelper::add_card(card_3,&possible_combination);
                CardsAbstractionHelper::erase_emptys(&possible_combination);
                CardsAbstractionHelper::sort_vector(&possible_combination);
                CardsAbstractionHelper::insert(&storage.flop_card_table,
                                               &storage.flop_index_table,
                                               &possible_combination,&index);
            }
        }
    }
    std::cout<<storage.flop_card_table.size()<<std::endl;
}

void CardsAbstractionBuilder::build_turn(){
    uint32_t index=0;
    for (int i = 0; i < CARDS; i++) {
        Card *card_1 = new Card(i);
        for (int j = i + 1; j < CARDS; j++) {
            Card *card_2 = new Card(j);
            for (int k = j + 1; k < CARDS; k++) {
                Card *card_3 = new Card(k);
                for (int h = k + 1; h < CARDS; h++) {
                    Card *card_4 = new Card(h);
                    std::vector<std::vector<uint8_t >> possible_combination;
                    possible_combination.resize(4);
                    CardsAbstractionHelper::add_card(card_1,&possible_combination);
                    CardsAbstractionHelper::add_card(card_2,&possible_combination);
                    CardsAbstractionHelper::add_card(card_3,&possible_combination);
                    CardsAbstractionHelper::add_card(card_4,&possible_combination);
                    CardsAbstractionHelper::erase_emptys(&possible_combination);
                    CardsAbstractionHelper::sort_vector(&possible_combination);
                    CardsAbstractionHelper::insert(&storage.turn_card_table,
                                                   &storage.turn_index_table,
                                                   &possible_combination,&index);;

                }
            }
        }
    }
    std::cout<<storage.turn_card_table.size()<<std::endl;
}
void CardsAbstractionBuilder::build_river(){
    uint32_t index=0;
    for (int i = 0; i < CARDS; i++) {
        Card *card_1 = new Card(i);
        for (int j = i + 1; j < CARDS; j++) {
            Card *card_2 = new Card(j);
            for (int k = j + 1; k < CARDS; k++) {
                Card *card_3 = new Card(k);
                for (int h = k + 1; h < CARDS; h++) {
                    Card *card_4 = new Card(h);
                    for (int g = h + 1; g < CARDS; g++) {
                        Card *card_5 = new Card(g);
                        std::vector<std::vector<uint8_t >> possible_combination;
                        possible_combination.resize(4);
                        CardsAbstractionHelper::add_card(card_1,&possible_combination);
                        CardsAbstractionHelper::add_card(card_2,&possible_combination);
                        CardsAbstractionHelper::add_card(card_3,&possible_combination);
                        CardsAbstractionHelper::add_card(card_4,&possible_combination);
                        CardsAbstractionHelper::add_card(card_5,&possible_combination);
                        CardsAbstractionHelper::river_optimezer(&possible_combination);
                        CardsAbstractionHelper::erase_emptys(&possible_combination);
                        CardsAbstractionHelper::sort_vector(&possible_combination);
                        CardsAbstractionHelper::insert(&storage.river_card_table,
                                                       &storage.river_index_table,
                                                       &possible_combination,&index);;
                    }
                }
            }
        }
    }
    std::cout<<storage.river_card_table.size()<<std::endl;
}









