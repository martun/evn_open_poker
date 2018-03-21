#include "../cards_abstraction_storage.h"
#include "../cards_abstraction_builder.h"
#include <fstream>
CardsAbstractionStorage::CardsAbstractionStorage(){
}

void CardsAbstractionStorage::save(){
   std::string flopCardTable;
    std::string turnCardTable;
    std::string riverCardTable;
    saveCardsToString(flop_card_table,FLOP,flopCardTable);
    saveCardsToString(turn_card_table,TURN,turnCardTable);
    saveCardsToString(river_card_table,RIVER,riverCardTable);
    std::string flopIndexTable;
    std::string turnIndexTable;
    std::string riverIndexTable;
    saveIndexesToString(flop_index_table,flopIndexTable);
    saveIndexesToString(turn_index_table,turnIndexTable);
    saveIndexesToString(river_index_table,riverIndexTable);
//    std::ofstream out("output.txt");
//    out << flopCardTable<<"\n";
//    out<< turnCardTable<<"\n";
//    out<< riverCardTable<<"\n";
//    out<<flopIndexTable<<"\n";
//    out<< turnIndexTable<<"\n";
//    out<<riverIndexTable<<"\n";
//    out.close();
    }
void CardsAbstractionStorage::load(){
//    std::ifstream ifile("output.txt");  //if file existes
//    if(!ifile){
        (new CardsAbstractionBuilder(*this))->build_all();
//    }
//    else{
//        std::string flopCardTable; //get stringes from somewhere
//        std::string turnCardTable;
//        std::string riverCardTable;
//        std::ifstream infile;
//        infile.open ("output.txt");
//        getline(infile,flopCardTable);
//        getline(infile,turnCardTable);
//        getline(infile,riverCardTable);
//
//        loadCardsFromString(flopCardTable,FLOP,flop_card_table);
//        loadCardsFromString(turnCardTable,TURN,turn_card_table);
//        loadCardsFromString(riverCardTable,RIVER,river_card_table);
//        int size=flop_card_table.size();
//         size=turn_card_table.size();
//         size=river_card_table.size();
//        std::string flopIndexTable;
//        std::string turnIndexTable;
//        std::string riverIndexTable;
//        loadIndexesFromString(flopIndexTable,flop_index_table);
//        loadIndexesFromString(turnIndexTable,turn_index_table);
//        loadIndexesFromString(riverIndexTable,river_index_table);
//    }
}

void CardsAbstractionStorage::saveIndexesToString(std::unordered_map<size_t ,unsigned int> &table,std::string &str){
    int size=table.size()*(sizeof(unsigned long)+sizeof(uint));
    str.resize(size);
    auto itr=table.begin();
    int count=0;
    while(count!=size) {
        memcpy(&str[0] + count, &itr->first, sizeof(unsigned long));
        count+= sizeof(unsigned long);
        std::memcpy(&str[0] + count, &itr->second, sizeof(uint));
        count+= sizeof(uint);
        itr++;
    }

}

void CardsAbstractionStorage::loadIndexesFromString(std::string &str,std::unordered_map<size_t ,unsigned int> &table){
    int size=str.size()/(sizeof(unsigned long)+ sizeof(uint));
    int step=sizeof(uint)+sizeof(unsigned long);
    size_t hash;
    unsigned int index;
    for(int i=0;i<size;i++){
       memcpy(&hash,&str[0]+i*step, sizeof(unsigned long));
        memcpy(&index,&str[0]+i*step+sizeof(unsigned long), sizeof(uint));
        table.insert({{hash,index}});
    }

}
void CardsAbstractionStorage::saveCardsToString(std::unordered_map<unsigned int,std::vector<Card>> &table,
                                                Round r,std::string &str) {
    int num_of_cards = r + 2;
    int size = table.size() * (sizeof(uint) + sizeof(uint) * num_of_cards);
    str.resize(size);
    auto itr = table.begin();
    int count=0;
    for(int i=0;i<table.size();i++){
        std::memcpy(&str[0]+count, &itr->first, sizeof(uint));
        count+= sizeof(uint);
        for(int j=0;j<num_of_cards;j++){
            std::memcpy(&str[0] + count, &itr->second[j], sizeof(uint));
            count+= sizeof(uint);
        }
        itr++;
    }
}
void CardsAbstractionStorage::loadCardsFromString(std::string &str,Round r,
                                                  std::unordered_map<unsigned int,std::vector<Card>> &table_out){
    int num_of_cards = r + 2;
    int strsize=str.size();
    int size=str.size()/(sizeof(uint) + sizeof(uint) * num_of_cards);
    int count=0;

    Card *c;
    for(int i=0;i<size;i++){
       int index;

        memcpy(&index, &str[count], sizeof(uint));

        count+= sizeof(uint);
        std::vector<Card> cards;
        for(int j=0;j<num_of_cards;j++){
            int card;
            memcpy(&card,&str[count], sizeof(uint));
            count+=sizeof(uint);
             c=new Card(card);
            cards.push_back(*c);
        }
        table_out.insert({{index,cards}});
    }

}

