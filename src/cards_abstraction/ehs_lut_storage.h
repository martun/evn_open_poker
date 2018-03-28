#pragma once
#include <unordered_map>
#include "cards_abstraction_provider.h"
#include <memory>

class EhsLutStorage{

public:
    EhsLutStorage();
    void save(const std::string& file_path)  const;
    void load(std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
              const std::string& file_path);
    void save_to_string(std::unordered_map<uint32_t ,double >& table,
                        std::string& str_out) const;

    void load_from_string(std::string& str_out,
                          std::unordered_map<uint32_t ,double >& table_out) const;

    std::unordered_map<uint32_t ,double > preflop_ehs_table;
    std::unordered_map<uint32_t ,double > preflop_ehs_squared_table;

    std::unordered_map<uint32_t ,double > flop_ehs_table;
    std::unordered_map<uint32_t ,double > flop_ehs_squared_table;

    std::unordered_map<uint32_t ,double > turn_ehs_table;
    std::unordered_map<uint32_t ,double > turn_ehs_squared_table;

    std::unordered_map<uint32_t ,double > river_ehs_table;
    std::unordered_map<uint32_t ,double > river_ehs_squared_table;
};