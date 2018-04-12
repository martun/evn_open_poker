#include "ehs_lut_builder.h"



EhsLutBuilder::EhsLutBuilder(std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
                             EhsLutStorage& storage)
        : abstractionProvider(cardsAbstractionProvider),storage(storage)
{
}

void EhsLutBuilder::buildAll() {
    buildPreflop();
    buildFlop();
    buildTurn();
    buildRiver();
    storage.save("ehsLUTs.bin");
}

void EhsLutBuilder::buildPreflop(){
    for (uint8_t i = 0;i < PreflopTableSize; ++i) {
        std::vector<Card> holeCards;
        std::vector<Card> public_c; //this is empty.
        abstractionProvider->get_canonical_cards_combination(i, PREFLOP, holeCards, public_c);
        compute_insert_preflop(holeCards,public_c);
    }
}

void EhsLutBuilder::buildFlop(){
    for (uint32_t i = 0;i < abstractionProvider->get_iso_public_cards_number(FLOP); ++i) {
        std::vector<Card> public_cards;
        abstractionProvider->get_canonical_public_cards(i,FLOP,public_cards);
        compute_insert_flop(public_cards);
    }
}

void EhsLutBuilder::buildTurn(){
    for (uint32_t i = 0;i < abstractionProvider->get_iso_public_cards_number(TURN); ++i) {
        std::vector<Card> public_cards;
        abstractionProvider->get_canonical_public_cards(i,TURN,public_cards);
        compute_insert_turn(public_cards);

    }
}
void EhsLutBuilder::buildRiver() {
    for (uint32_t i = 0;i < abstractionProvider->get_iso_public_cards_number(RIVER); ++i) {
        std::vector<Card> public_cards;
        abstractionProvider->get_canonical_public_cards(i,RIVER,public_cards);
        compute_insert_river(public_cards);
    }
}

void EhsLutBuilder::compute_insert_preflop(std::vector<Card>& holeCards,std::vector<Card>& public_c){
    double desired = 0;
    double whole_count = 0;
    for (Card oppc1(0); oppc1.get_card_num() < CARDNUM; ++oppc1) {
        if (&oppc1 == &holeCards[0] ||
            &oppc1 == &holeCards[1] )
            continue;
        for (Card oppc2(oppc1.get_card_num() + 1); oppc2.get_card_num() < CARDNUM; ++oppc2) {
            if (&oppc2 == &holeCards[0] ||
                &oppc2 == &holeCards[1])
                continue;
            for (Card pubcard1(0); pubcard1.get_card_num() < CARDNUM; ++pubcard1) {
                if (&pubcard1 == &holeCards[0] ||
                    &pubcard1 == &holeCards[1] ||
                    &pubcard1 == &oppc1 ||
                    &pubcard1 == &oppc2)
                    continue;
                for (Card pubcard2(pubcard1.get_card_num() + 1);
                     pubcard2.get_card_num() < CARDNUM; ++pubcard2) {
                    if (&pubcard2 == &holeCards[0] ||
                        &pubcard2 == &holeCards[1] ||
                        &pubcard2 == &oppc1 ||
                        &pubcard2 == &oppc2)
                        continue;
                    for (Card pubcard3(pubcard2.get_card_num() + 1);
                         pubcard3.get_card_num() < CARDNUM; ++pubcard3) {
                        if (&pubcard3 == &holeCards[0] ||
                            &pubcard3 == &holeCards[1] ||
                            &pubcard3 == &oppc1 ||
                            &pubcard3 == &oppc2)
                            continue;
                        for (Card pubcard4(pubcard3.get_card_num() + 1);
                             pubcard4.get_card_num() < CARDNUM; ++pubcard4) {
                            if (&pubcard4 == &holeCards[0] ||
                                &pubcard4 == &holeCards[1] ||
                                &pubcard4 == &oppc1 ||
                                &pubcard4 == &oppc2)
                                continue;
                            for (Card pubcard5(pubcard4.get_card_num() + 1);
                                 pubcard5.get_card_num() < CARDNUM; ++pubcard5) {
                                if (&pubcard5 == &holeCards[0] ||
                                    &pubcard5 == &holeCards[1] ||
                                    &pubcard5 == &oppc1 ||
                                    &pubcard5 == &oppc2)
                                    continue;

                                uint16_t my_hand_Rank = SevenEval::GetRank(
                                        holeCards[0].get_card_num(),
                                        holeCards[1].get_card_num(),
                                        pubcard1.get_card_num(),
                                        pubcard2.get_card_num(),
                                        pubcard3.get_card_num(),
                                        pubcard4.get_card_num(),
                                        pubcard5.get_card_num());
                                uint16_t opponent_hand_Rank = SevenEval::GetRank(
                                        oppc1.get_card_num(),
                                        oppc1.get_card_num(),
                                        pubcard1.get_card_num(),
                                        pubcard2.get_card_num(),
                                        pubcard3.get_card_num(),
                                        pubcard4.get_card_num(),
                                        pubcard5.get_card_num());
                                if (my_hand_Rank > opponent_hand_Rank)
                                    desired++;
                                if (my_hand_Rank < opponent_hand_Rank)
                                    desired--;
                                whole_count++;
                            }
                        }
                    }
                }
            }
        }
    }

    double ehs = desired / whole_count;
    double ehs_suqared = (desired * desired) / (whole_count * whole_count);
    uint32_t isoNum = abstractionProvider->get_hand_iso_number(holeCards,public_c);
    storage.preflop_ehs_table.insert({{isoNum,ehs}});
    storage.preflop_ehs_squared_table.insert({{isoNum,ehs_suqared}});

}

void EhsLutBuilder::compute_insert_flop(std::vector<Card>& public_cards) {
    for (Card myc1(0); myc1.get_card_num() < CARDNUM; ++myc1) {
        std::vector<Card> hole_cards;
        hole_cards.push_back(myc1);
        for (Card myc2(myc1.get_card_num() + 1); myc2.get_card_num() < CARDNUM; ++myc2) {
            hole_cards.push_back(myc2);
            double desired = 0;
            double whole_count = 0;
            for (Card oppc1(0); oppc1.get_card_num() < CARDNUM; ++oppc1) {
                if (&oppc1 == &myc1 ||
                    &oppc1 == &myc2)
                    continue;
                for (Card oppc2(oppc1.get_card_num() + 1); oppc2.get_card_num() < CARDNUM; ++oppc2) {
                    if (&oppc2 == &myc1 ||
                        &oppc2 == &myc2)
                        continue;
                    for(Card pub4card(0);pub4card.get_card_num() < CARDNUM;++pub4card){
                        if (&pub4card == &myc1 ||
                            &pub4card == &myc2 ||
                            &pub4card == &oppc1 ||
                            &pub4card == &oppc2)
                            continue;
                        for(Card pub5card(pub4card.get_card_num()+1);
                            pub5card.get_card_num() < CARDNUM;
                            ++pub5card){
                            if (&pub5card == &myc1 ||
                                &pub5card == &myc2 ||
                                &pub5card == &oppc1 ||
                                &pub5card == &oppc2)
                                continue;
                            uint16_t my_hand_Rank=SevenEval::GetRank(
                                    myc1.get_card_num(),
                                    myc2.get_card_num(),
                                    public_cards[0].get_card_num(),
                                    public_cards[1].get_card_num(),
                                    public_cards[2].get_card_num(),
                                    pub4card.get_card_num(),
                                    pub5card.get_card_num());
                            uint16_t opponent_hand_Rank=SevenEval::GetRank(
                                    oppc1.get_card_num(),
                                    oppc1.get_card_num(),
                                    public_cards[0].get_card_num(),
                                    public_cards[1].get_card_num(),
                                    public_cards[2].get_card_num(),
                                    pub4card.get_card_num(),
                                    pub5card.get_card_num());
                            if(my_hand_Rank>opponent_hand_Rank)
                                desired++;
                            if(my_hand_Rank<opponent_hand_Rank)
                                desired--;
                            whole_count++;
                        }
                    }
                }
            }

            double ehs = desired / whole_count;
            double ehs_suqared = (desired * desired) / (whole_count * whole_count);
            insert(ehs,ehs_suqared,hole_cards,public_cards,
                   storage.flop_ehs_table,
                   storage.flop_ehs_squared_table);
        }
    }
}


void EhsLutBuilder::compute_insert_turn(std::vector<Card>& public_cards) {
    for (Card myc1(0); myc1.get_card_num() < CARDNUM; ++myc1) {
        std::vector<Card> hole_cards;
        hole_cards.push_back(myc1);
        for (Card myc2(myc1.get_card_num() + 1); myc2.get_card_num() < CARDNUM; ++myc2) {
            hole_cards.push_back(myc2);
            double desired = 0;
            double whole_count = 0;
            for (Card oppc1(0); oppc1.get_card_num() < CARDNUM; ++oppc1) {
                if (&oppc1 == &myc1 ||
                    &oppc1 == &myc2)
                    continue;
                for (Card oppc2(oppc1.get_card_num() + 1); oppc2.get_card_num() < CARDNUM; ++oppc2) {
                    if (&oppc2 == &myc1 ||
                        &oppc2 == &myc2)
                        continue;
                    for(Card pub5card(0);pub5card.get_card_num() < CARDNUM;++pub5card){
                        if (&pub5card == &myc1 ||
                            &pub5card == &myc2 ||
                            &pub5card == &oppc1 ||
                            &pub5card == &oppc2)
                            continue;
                        uint16_t my_hand_Rank=SevenEval::GetRank(
                                myc1.get_card_num(),
                                myc2.get_card_num(),
                                public_cards[0].get_card_num(),
                                public_cards[1].get_card_num(),
                                public_cards[2].get_card_num(),
                                public_cards[3].get_card_num(),
                                pub5card.get_card_num());
                        uint16_t opponent_hand_Rank=SevenEval::GetRank(
                                oppc1.get_card_num(),
                                oppc1.get_card_num(),
                                public_cards[0].get_card_num(),
                                public_cards[1].get_card_num(),
                                public_cards[2].get_card_num(),
                                public_cards[3].get_card_num(),
                                pub5card.get_card_num());
                        if(my_hand_Rank>opponent_hand_Rank)
                            desired++;
                        if(my_hand_Rank<opponent_hand_Rank)
                            desired--;
                        whole_count++;
                    }
                }
            }

            double ehs = desired / whole_count;
            double ehs_suqared = (desired * desired) / (whole_count * whole_count);
            insert(ehs,ehs_suqared,hole_cards,public_cards,
                   storage.turn_ehs_table,
                   storage.turn_ehs_squared_table);
        }
    }
}



void EhsLutBuilder::compute_insert_river(std::vector<Card>& public_cards){
    for (Card myc1(0);myc1.get_card_num() < CARDNUM;++myc1) {
        std::vector<Card> hole_cards;
        hole_cards.push_back(myc1);
        for (Card myc2(myc1.get_card_num()+1);myc2.get_card_num() < CARDNUM;++myc2){
            hole_cards.push_back(myc2);
            double desired=0;
            double whole_count=0;
            for (Card oppc1(0);oppc1.get_card_num() < CARDNUM;++oppc1) {
                if(&oppc1 == &myc1 ||
                   &oppc1 == &myc2)
                    continue;
                for(Card oppc2(oppc1.get_card_num()+1);oppc2.get_card_num() < CARDNUM;++oppc2){
                    if(&oppc2 == &myc1 ||
                       &oppc2 == &myc2)
                        continue;
                    uint16_t my_hand_Rank=SevenEval::GetRank(
                            myc1.get_card_num(),
                            myc2.get_card_num(),
                            public_cards[0].get_card_num(),
                            public_cards[1].get_card_num(),
                            public_cards[2].get_card_num(),
                            public_cards[3].get_card_num(),
                            public_cards[4].get_card_num());
                    uint16_t opponent_hand_Rank=SevenEval::GetRank(
                            oppc1.get_card_num(),
                            oppc1.get_card_num(),
                            public_cards[0].get_card_num(),
                            public_cards[1].get_card_num(),
                            public_cards[2].get_card_num(),
                            public_cards[3].get_card_num(),
                            public_cards[4].get_card_num());
                    if(my_hand_Rank>opponent_hand_Rank)
                        desired++;
                    if(my_hand_Rank<opponent_hand_Rank)
                        desired--;
                    whole_count++;
                }
            }
            double ehs = desired / whole_count;
            double ehs_suqared = (desired * desired) / (whole_count * whole_count);
            insert(ehs,ehs_suqared,hole_cards,public_cards,
                   storage.river_ehs_table,
                   storage.river_ehs_squared_table);
        }
    }
}

void EhsLutBuilder::insert(double ehs, double ehs_squared,
                           std::vector<Card>& hole_cards,
                           std::vector<Card>& public_cards,
                           std::unordered_map<uint32_t ,double >& ehs_table_out,
                           std::unordered_map<uint32_t ,double >& ehs_squared_table_out){
    uint32_t  isoNum = abstractionProvider->get_hand_iso_number(hole_cards,public_cards);
    ehs_table_out.insert({{isoNum,ehs}});
    ehs_squared_table_out.insert({{isoNum,ehs_squared}});
}