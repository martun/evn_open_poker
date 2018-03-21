#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include "card.h"
#include "Utils.h"
#include <sstream>
#include <fstream>
#include <string>
#include <iostream>
#include <cstring>


class CardsAbstractionStorage{

public:
    CardsAbstractionStorage();
    void save();
    void load();
    void loadCardsFromString(std::string &,Round r,std::unordered_map<unsigned int,std::vector<Card>> &);
    void loadIndexesFromString(std::string &,std::unordered_map<size_t ,unsigned int> &);
    void saveCardsToString(std::unordered_map<unsigned int,std::vector<Card>>&,Round r,std::string &);
    void saveIndexesToString(std::unordered_map<size_t ,unsigned int> &,std::string &);
    std::unordered_map<unsigned int,std::vector<Card>>flop_card_table;
    std::unordered_map<size_t ,unsigned int> flop_index_table;
    std::unordered_map<unsigned int,std::vector<Card>> turn_card_table;
    std::unordered_map<size_t ,unsigned int> turn_index_table;
    std::unordered_map<unsigned int,std::vector<Card>> river_card_table;
    std::unordered_map<size_t ,unsigned int> river_index_table;
};
