#include "../cards_abstraction_storage.h"
#include "../cards_abstraction_builder.h"
#include <fstream>

CardsAbstractionStorage::CardsAbstractionStorage() {

}

void CardsAbstractionStorage::save(const std::string& file_path) const {
  std::string preflopCardTable;
  std::string flopCardTable;
  std::string turnCardTable;
  std::string riverCardTable;

  save_cards_to_string(preflop_card_table, PREFLOP, preflopCardTable);
  save_cards_to_string(flop_card_table, FLOP, flopCardTable);
  save_cards_to_string(turn_card_table, TURN, turnCardTable);
  save_cards_to_string(river_card_table, RIVER, riverCardTable);

  std::string preflopIndexTable;
  std::string flopIndexTable;
  std::string turnIndexTable;
  std::string riverIndexTable;

  save_indexes_to_string(preflop_index_table, preflopIndexTable);
  save_indexes_to_string(flop_index_table, flopIndexTable);
  save_indexes_to_string(turn_index_table, turnIndexTable);
  save_indexes_to_string(river_index_table, riverIndexTable);
  
  //    std::ofstream out("output.txt");
  //    out << preflopCardTable<<"\n";
  //    out << flopCardTable<<"\n";
  //    out<< turnCardTable<<"\n";
  //    out<< riverCardTable<<"\n";
  //    out<<preflopIndexTable<<"\n";
  //    out<<flopIndexTable<<"\n";
  //    out<< turnIndexTable<<"\n";
  //    out<<riverIndexTable<<"\n";
  //    out.close();
}

void CardsAbstractionStorage::load(const std::string& file_path) {
  //    std::ifstream ifile("output.txt");  //if file existes
  //    if(!ifile){
  (new CardsAbstractionBuilder(*this))->build_all();
  //    }
  //    else{
  //        std::string preflopCardTable; //get stringes from somewhere
  //        std::string flopCardTable;
  //        std::string turnCardTable;
  //        std::string riverCardTable;
  //        std::ifstream infile;
  //        infile.open ("output.txt");
  //        getline(infile,preflopCardTable);
  //        getline(infile,flopCardTable);
  //        getline(infile,turnCardTable);
  //        getline(infile,riverCardTable);
  //
  //        load_cards_from_string(preflopCardTable,PREFLOP,preflop_card_table);
  //        load_cards_from_string(flopCardTable,FLOP,flop_card_table);
  //        load_cards_from_string(turnCardTable,TURN,turn_card_table);
  //        load_cards_from_string(riverCardTable,RIVER,river_card_table);
  //        int size=flop_card_table.size();
  //         size=turn_card_table.size();
  //         size=river_card_table.size();
  //        std::string preflopIndexTable;
  //        std::string flopIndexTable;
  //        std::string turnIndexTable;
  //        std::string riverIndexTable;
  //        load_indexes_from_string(preflopIndexTable,preflop_index_table);
  //        load_indexes_from_string(flopIndexTable,flop_index_table);
  //        load_indexes_from_string(turnIndexTable,turn_index_table);
  //        load_indexes_from_string(riverIndexTable,river_index_table);
  //    }
}

void CardsAbstractionStorage::save_indexes_to_string(
    const std::unordered_map<size_t ,unsigned int>& table,
    std::string &str_out) const {
  int size = table.size() * (sizeof(uint32_t) + sizeof(uint));
  str_out.resize(size);
  auto itr = table.begin();
  int count=0;
  while(count!=size) {
    memcpy(&str_out[0] + count, &itr->first, sizeof(uint32_t));
    count += sizeof(uint32_t);
    std::memcpy(&str_out[0] + count, &itr->second, sizeof(uint));
    count += sizeof(uint);
    itr++;
  }
}

void CardsAbstractionStorage::load_indexes_from_string(
    const std::string& str,
    std::unordered_map<size_t, unsigned int> &table) {
  uint32_t size = str.size() / (sizeof(uint32_t) + sizeof(uint));
  uint32_t step = sizeof(uint32_t) + sizeof(uint32_t);
  size_t hash;
  uint32_t index;
  for(uint32_t i=0; i<size; i++){
    memcpy(&hash,&str[0] + i * step, sizeof(uint32_t));
    memcpy(&index,&str[0] + i * step + sizeof(uint32_t), sizeof(uint32_t));
    table.insert({{hash,index}});
  }

}
void CardsAbstractionStorage::save_cards_to_string(
    const std::unordered_map<unsigned int,std::vector<Card>> &table,
    Round r,
    std::string& str_out) const {
  int num_of_cards = r + 2;
  int size = table.size() * (sizeof(uint) + sizeof(uint) * num_of_cards);
  str_out.resize(size);
  auto itr = table.begin();
  int count=0;
  for(uint32_t i=0;i<table.size();i++){
    std::memcpy(&str_out[0]+count, &itr->first, sizeof(uint));
    count+= sizeof(uint);
    for(int j=0;j<num_of_cards;j++){
      std::memcpy(&str_out[0] + count, &itr->second[j], sizeof(uint));
      count+= sizeof(uint);
    }
    itr++;
  }
}

void CardsAbstractionStorage::load_cards_from_string(
    const std::string& str,
    Round r,
    std::unordered_map<unsigned int,std::vector<Card>> &table_out) {
  int num_of_cards = r + 2;
  int size = str.size()/(sizeof(uint) + sizeof(uint) * num_of_cards);
  int count = 0;

  for(int i = 0; i < size; ++i){
    int index;

    memcpy(&index, &str[count], sizeof(uint));

    count += sizeof(uint);
    std::vector<Card> cards;
    for(int j=0;j<num_of_cards;j++){
      int card;
      memcpy(&card,&str[count], sizeof(uint));
      count += sizeof(uint);
      cards.push_back(Card(card));
    }
    table_out.insert({{index,cards}});
  }
}

