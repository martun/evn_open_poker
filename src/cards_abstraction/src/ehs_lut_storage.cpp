#include "../ehs_lut_storage.h"
#include "../ehs_lut_builder.h"
EhsLutStorage::EhsLutStorage() {

}

void EhsLutStorage::save(const std::string& file_path) const {
    std::string preflopEhsTable;
    save_to_string(preflop_ehs_table,preflopEhsTable);
    std::string preflopEhsSquaredTable;
    save_to_string(preflop_ehs_squared_table,preflopEhsSquaredTable);

    std::string flopEhsTable;
    save_to_string(flop_ehs_table,flopEhsTable);
    std::string flopEhsSquaredTable;
    save_to_string(flop_ehs_squared_table,flopEhsSquaredTable);

    std::string turnEhsTable;
    save_to_string(turn_ehs_table,turnEhsTable);
    std::string turnEhsSquaredTable;
    save_to_string(turn_ehs_squared_table,turnEhsSquaredTable);

    std::string riverEhsTable;
    save_to_string(river_ehs_table,riverEhsTable);
    std::string riverEhsSquaredTable;
    save_to_string(river_ehs_squared_table,riverEhsSquaredTable);
//    TODO put strings to file
}


void EhsLutStorage::load(std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
                         const std::string& file_path) {
    //    std::ifstream ifile("output.txt");  //if file existes
    //    if(!ifile){
    (new EhsLutBuilder(cardsAbstractionProvider, *this))->buildAll();
//}
//    else {
////        TODO get strings form file
//        load_from_string(preflopEhsStr,preflop_ehs_table);
//        load_from_string(preflopEhsSquaredStr,preflop_ehs_squared_table);
//
//        load_from_string(flopEhsStr,flop_ehs_table);
//        load_from_string(flopEhsSquaredStr,flop_ehs_squared_table);
//
//        load_from_string(turnEhsStr,turn_ehs_table);
//        load_from_string(turnEhsSquaredStr,turn_ehs_squared_table);
//
//        load_from_string(riverEhsStr,river_ehs_table);
//        load_from_string(riverEhsSquaredStr,river_ehs_squared_table);
//    }

}

void EhsLutStorage::save_to_string(std::unordered_map<uint32_t ,double >& table,
                                   std::string& str_out) const {
    uint32_t str_size=table.size()*(sizeof(uint32_t)+ sizeof(double));
    str_out.resize(str_size);
    int count = 0;
    auto itr = table.begin();
    while(count!=str_size) {
        memcpy(&str_out[0] + count, &itr->first, sizeof(uint32_t));
        count+= sizeof(uint32_t);
        std::memcpy(&str_out[0] + count, &itr->second, sizeof(double));
        count+= sizeof(double);
        itr++;
    }
}

void EhsLutStorage::load_from_string(std::string& str_out,
                                     std::unordered_map<uint32_t ,double >& table_out) const {

}