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

    FILE*  out=fopen((const char*)file_path,"w");
    // writing the sizes
    uint32_t preFlopEhsTableSize = preflopEhsTable.size();
    fwrite (&preFlopEhsTableSize
            , sizeof(uint32_t)
            , 1, out );

    uint32_t FlopEhsTableSize = flopEhsTable.size();
    fwrite (&FlopEhsTableSize
            , sizeof(uint32_t)
            , 1, out );

    uint32_t turnEhsTableSize = turnEhsTable.size();
    fwrite (&turnEhsTableSize
            , sizeof(uint32_t)
            , 1, out );

    uint32_t riverEhsTableSize = riverEhsTable.size();
    fwrite (&riverEhsTableSize
            , sizeof(uint32_t)
            , 1, out );

    //writing strings into file
    if(fwrite (preflopEhsTable.c_str()
            , sizeof(char)
            , preFlopEhsTableSize
            , out )
        !=preFlopEhsTableSize)
          throw "Error while writing to file";
    if(fwrite (preflopEhsSquaredTable.c_str()
            , sizeof(char)
            , preFlopEhsTableSize
            , out )
        !=preFlopEhsTableSize)
          throw "Error while writing to file";
    if(fwrite (flopEhsTable.c_str()
            , sizeof(char)
            , FlopEhsTableSize
            , out )
        !=FlopEhsTableSize)
          throw "Error while writing to file";
    if(fwrite (flopEhsSquaredTable.c_str()
            , sizeof(char)
            , FlopEhsTableSize
            , out )
       !=FlopEhsTableSize)
         throw "Error while writing to file";
    if(fwrite (turnEhsTable.c_str()
            , sizeof(char)
            , turnEhsTableSize
            , out )
        !=turnEhsTableSize
          throw "Error while writing to file";
    if(fwrite (turnEhsSquaredTable.c_str()
            , sizeof(char)
            , turnEhsTableSize
            , out )
        !=turnEhsTableSize)
          throw "Error while writing to file";
    if(fwrite (riverEhsTable.c_str()
            , sizeof(char)
            , riverEhsTableSize
            , out )
        !=riverEhsTableSize)
          throw "Error while writing to file";;
   if(fwrite (riverEhsSquaredTable.c_str()
            , sizeof(char)
            , riverEhsTableSize
            , out )
       !=riverEhsTableSize)
         throw "Error while writing to file";
    fclose(out);
}


void EhsLutStorage::load(std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
                         const std::string& file_path) {
    FILE* in=fopen((const char *) file_path, "r");  //tries to open file
    if(in==NULL){                   //if file not exists existes
        throw "File is not existing";

    }
    else{
        uint32_t  prefTableSize
                , flopTableSize
                , turnTableSize
                , riverTableSize;
        std::fread(reinterpret_cast<char*>(&prefTableSize)
                , sizeof(prefTableSize),1,in);

        std::fread(reinterpret_cast<char*>(&flopTableSize)
                , sizeof(flopTableSize),1,in);

        std::fread(reinterpret_cast<char*>(&turnTableSize)
                , sizeof(turnTableSize),1,in);

        std::fread(reinterpret_cast<char*>(&riverTableSize)
                , sizeof(riverTableSize),1,in);
        char buffer0[prefTableSize]
           , buffer1[prefTableSize]
           , buffer2[flopTableSize]
           , buffer3[flopTableSize]
           , buffer4[turnTableSize]
           , buffer5[turnTableSize]
           , buffer6[riverTableSize]
           , buffer7[riverTableSize];


        std::fread(buffer0, sizeof(char)
                ,prefTableSize,in);
        std::fread(buffer1, sizeof(char)
                ,prefTableSize,in);

        std::fread(buffer2, sizeof(char)
                ,flopTableSize,in);
        std::fread(buffer3, sizeof(char)
                ,flopTableSize,in);

        std::fread(buffer4, sizeof(char)
                ,turnTableSize,in);
        std::fread(buffer5, sizeof(char)
                ,turnTableSize,in);
        std::fread(buffer6, sizeof(char)
                ,riverTableSize,in);
        std::fread(buffer7, sizeof(char)
                ,riverTableSize,in);
        std::string preflopEhsStr       (buffer0)
                  , preflopEhsSquaredStr(buffer1)
                  , flopEhsStr          (buffer2)
                  , flopEhsSquaredStr   (buffer3)
                  , turnEhsStr          (buffer4)
                  , turnEhsSquaredStr   (buffer5)
                  , riverEhsStr         (buffer6)
                  , riverEhsSquaredStr  (buffer7);

        load_from_string(preflopEhsStr,preflop_ehs_table);
        load_from_string(preflopEhsSquaredStr,preflop_ehs_squared_table);

        load_from_string(flopEhsStr,flop_ehs_table);
        load_from_string(flopEhsSquaredStr,flop_ehs_squared_table);

        load_from_string(turnEhsStr,turn_ehs_table);
        load_from_string(turnEhsSquaredStr,turn_ehs_squared_table);

        load_from_string(riverEhsStr,river_ehs_table);
        load_from_string(riverEhsSquaredStr,river_ehs_squared_table);
    }
    fclose(in);
}

void EhsLutStorage::save_to_string(std::unordered_map<uint32_t ,double >& table,
                                   std::string& str_out) const {
    uint32_t str_size = table.size() * (sizeof(uint32_t) + sizeof(double));
    str_out.resize(str_size);
    int count = 0;
    auto itr = table.begin();
    while(count!=str_size) {
        memcpy(&str_out[0] + count, &itr->first, sizeof(uint32_t));
        count += sizeof(uint32_t);
        std::memcpy(&str_out[0] + count, &itr->second, sizeof(double));
        count += sizeof(double);
        itr++;
    }
}

void EhsLutStorage::load_from_string(std::string& str,
                                     std::unordered_map<uint32_t ,double >& table_out) const {
    uint32_t size = str.size() / (sizeof(uint32_t) + sizeof(double));
    uint8_t step = sizeof(uint32_t) + sizeof(double);
    uint32_t count =0;
    while(count != size){

        uint32_t isoNum;
        memcpy(&isoNum,&str[0]+count * step, sizeof(uint32_t));

        double ehsVal;
        memcpy(&ehsVal,&str[0]+count * step + sizeof(uint32_t), sizeof(double));

        table_out.insert({{isoNum,ehsVal}});
        count++;
    }
}