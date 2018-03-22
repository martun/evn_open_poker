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

class CardsAbstractionStorage {

public:
    CardsAbstractionStorage();

    void save(const std::string& file_path) const;
    void load(const std::string& file_path);
    void load_cards_from_string(
      const std::string& str,
      Round r,
      std::unordered_map<unsigned int,std::vector<Card>> &table_out
    );

    void load_indexes_from_string(
      const std::string &,
      std::unordered_map<size_t ,unsigned int> &
    );

    void save_cards_to_string(
      const std::unordered_map<unsigned int,std::vector<Card>> &table,
      Round r,
      std::string& str_out) const;

    void save_indexes_to_string(
      const std::unordered_map<size_t ,unsigned int>& table,
      std::string& str_out) const;

public:
    std::unordered_map<unsigned int,std::vector<Card>> flop_card_table;
    std::unordered_map<size_t ,unsigned int> flop_index_table;

    std::unordered_map<unsigned int,std::vector<Card>> turn_card_table;
    std::unordered_map<size_t ,unsigned int> turn_index_table;

    std::unordered_map<unsigned int,std::vector<Card>> river_card_table;
    std::unordered_map<size_t ,unsigned int> river_index_table;

};

