

#ifndef EVN_OPEN_POKER_MASTER_CARD_ABSTRACTION_FUNCTIONS_H
#define EVN_OPEN_POKER_MASTER_CARD_ABSTRACTION_FUNCTIONS_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "card.h"
#include "cards_abstraction_storage.h"
#include "card_abstraction_helper.h"

class CardsAbstractionHelper{
public:
    static void add_card(const Card*,std::vector<std::vector<uint8_t>> *);
    static void sort_vector(std::vector<std::vector<uint8_t>>*);
    static void erase_emptys(std::vector<std::vector<uint8_t>>*);
    static void river_optimezer(std::vector<std::vector<uint8_t>>*);
    static void insert(std::unordered_map<unsigned int,std::vector<std::vector<uint8_t >>>*,
        std::unordered_map<size_t ,unsigned int>*index_table,std::vector<std::vector<uint8_t >>*, unsigned int*);
    static size_t hash(const std::vector<std::vector<uint8_t >>* v);

};
#endif //EVN_OPEN_POKER_MASTER_CARD_ABSTRACTION_FUNCTIONS_H
