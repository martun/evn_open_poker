#ifndef EVN_OPEN_POKER_MASTER_CARDS_ABSTRACTION_STORAGE_H
#define EVN_OPEN_POKER_MASTER_CARDS_ABSTRACTION_STORAGE_H
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "card.h"


class CardsAbstractionStorage{
public:
    void save();
    void load();
    std::unordered_map<unsigned int,std::vector<std::vector<uint8_t >>> flop_card_table;
    std::unordered_map<size_t ,unsigned int> flop_index_table;
    std::unordered_map<unsigned int,std::vector<std::vector<uint8_t >>> turn_card_table;
    std::unordered_map<size_t ,unsigned int> turn_index_table;
    std::unordered_map<unsigned int,std::vector<std::vector<uint8_t >>> river_card_table;
    std::unordered_map<size_t ,unsigned int> river_index_table;
};

#endif //EVN_OPEN_POKER_MASTER_CARDS_ABSTRACTION_STORAGE_H
