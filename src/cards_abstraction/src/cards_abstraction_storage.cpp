#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"
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

      FILE*  out=fopen(file_path.c_str(),"w");
    // writing the sizes into file
    uint32_t preflopCTableSize = preflopCardTable.size();
    fwrite (&preflopCTableSize
              , sizeof(uint32_t)
              , 1, out );
    uint32_t flopCTableSize = flopCardTable.size();
    fwrite (&flopCTableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t turnCTableSize = turnCardTable.size();
    fwrite (&turnCTableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t riverCTableSize = riverCardTable.size();
    fwrite (&riverCTableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t preflopITableSize = preflopCardTable.size();
    fwrite (&preflopITableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t flopITableSize = flopCardTable.size();
    fwrite (&flopITableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t turnITableSize = turnCardTable.size();
    fwrite (&turnITableSize
            , sizeof(uint32_t)
            , 1, out );
    uint32_t riverITableSize = riverCardTable.size();
    fwrite (&riverITableSize
            , sizeof(uint32_t)
            , 1, out );
    //writing strings into file
    if(fwrite (preflopCardTable.c_str()
            , sizeof(char)
            , preflopCTableSize
            , out )
       !=preflopCTableSize)
        throw "Error while writing to file";
    if(fwrite (flopCardTable.c_str()
            , sizeof(char)
            , flopCTableSize
            , out )
        !=flopCTableSize)
        throw "Error while writing to file";
    if(fwrite (turnCardTable.c_str()
            , sizeof(char)
            , turnCTableSize
            , out )
        !=turnCTableSize)
        throw "Error while writing to file";
    if(fwrite (riverCardTable.c_str()
            , sizeof(char)
            , riverCTableSize
            , out )
        !=riverCTableSize)
        throw "Error while writing to file";
    if(fwrite (preflopIndexTable.c_str()
            , sizeof(char)
            , preflopITableSize
            , out )
        !=preflopITableSize)
        throw "Error while writing to file";
    if(fwrite (flopIndexTable.c_str()
            , sizeof(char)
            , flopITableSize
            , out )
        !=flopITableSize)
        throw "Error while writing to file";
    if(fwrite (turnIndexTable.c_str()
            , sizeof(char)
            , turnITableSize
            , out )
        !=turnITableSize)
        throw "Error while writing to file";
    if(fwrite (riverIndexTable.c_str()
            , sizeof(char)
            , riverITableSize
            , out )
        !=riverITableSize)
        throw "Error while writing to file";
      fclose(out);
}

void CardsAbstractionStorage::load(const std::string& file_path) {
      FILE* in=fopen( file_path.c_str(), "r");  //tries to open file
      if(in==NULL){                   //if file not exists existes
        throw "File is not existing";
      }
      else{          //if file exists, get stringes from file
          //taking sizes of strings from the file
          uint32_t  prefCardTableSize
                  , flopCardTableSize
                  , turnCardTableSize
                  , riverCardTableSize
                  , preflopIndexTableSize
                  , flopIndexTableSize
                  , turnIndexTableSize
                  , riverIndexTableSize;

          std::fread(reinterpret_cast<char*>(&prefCardTableSize)
                     , sizeof(prefCardTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&flopCardTableSize)
                     , sizeof(flopCardTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&turnCardTableSize)
                     , sizeof(turnCardTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&riverCardTableSize)
                     , sizeof(riverCardTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&preflopIndexTableSize)
                     , sizeof(preflopIndexTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&flopIndexTableSize)
                     , sizeof(flopIndexTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&turnIndexTableSize)
                     , sizeof(turnIndexTableSize),1,in);

          std::fread(reinterpret_cast<char*>(&riverIndexTableSize)
                     , sizeof(riverIndexTableSize),1,in);

          char buffer0[prefCardTableSize]
             , buffer1[flopCardTableSize]
             , buffer2[turnCardTableSize]
             , buffer3[riverCardTableSize];


          std::fread(buffer0, sizeof(char)
                     , prefCardTableSize,in);

          std::fread(buffer1, sizeof(char)
                     , flopCardTableSize,in);

          std::fread(buffer2, sizeof(char)
                     , turnCardTableSize,in);

          std::fread(buffer3, sizeof(char)
                     , riverCardTableSize,in);

          std::string preflopCardTable(buffer0)
                     , flopCardTable(buffer1)
                     , turnCardTable(buffer2)
                     , riverCardTable(buffer3);

          load_cards_from_string(preflopCardTable
                                 , PREFLOP
                                 , preflop_card_table);
          load_cards_from_string(flopCardTable
                                 , FLOP
                                 , flop_card_table);
          load_cards_from_string(turnCardTable
                                 , TURN
                                 , turn_card_table);
          load_cards_from_string(riverCardTable
                                 , RIVER
                                 , river_card_table);

          char buffer10[preflopIndexTableSize]
             , buffer11[flopIndexTableSize]
             , buffer12[turnIndexTableSize]
             , buffer13[riverIndexTableSize];


          std::fread(buffer10, sizeof(char)
                  ,preflopIndexTableSize,in);

          std::fread(buffer11, sizeof(char)
                  ,flopIndexTableSize,in);

          std::fread(buffer12, sizeof(char)
                  ,turnIndexTableSize,in);

          std::fread(buffer13, sizeof(char)
                  ,riverIndexTableSize,in);

          std::string preflopIndexTable(buffer10);
          std::string flopIndexTable(buffer11);
          std::string turnIndexTable(buffer12);
          std::string riverIndexTable(buffer13);

          load_indexes_from_string(preflopIndexTable
                                   , preflop_index_table);
          load_indexes_from_string(flopIndexTable
                                   , flop_index_table);
          load_indexes_from_string(turnIndexTable
                                   , turn_index_table);
          load_indexes_from_string(riverIndexTable
                                   , river_index_table);
      }
    fclose(in);
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

