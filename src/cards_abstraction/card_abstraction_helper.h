#pragma once
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
    static void insert_( std::vector<std::vector<uint8_t >> *,std::vector<Card>*,
                    unsigned int *,std::unordered_map<size_t, unsigned int> *index_table,std::unordered_map<unsigned int,std::vector<Card>> *card_table);
    static size_t hash(const std::vector<std::vector<uint8_t >>* v);

};
