#include <cards_abstraction/Utils.h>
#include "../ehs_bucketing_builder.h"


using namespace std;

EhsBucketingBuilder::EhsBucketingBuilder(std::shared_ptr<CardsAbstractionProvider> provider)  {

    auto cardsStorage = std::make_shared<CardsAbstractionStorage>();
    this->abstractionProvider = std::make_shared<CardsAbstractionProvider>(cardsStorage);
}

void EhsBucketingBuilder::build_all() {

    std::shared_ptr<EhsLutStorage> ehsStorage = std::make_shared<EhsLutStorage>();

    EhsLutProvider* ehsProvider = new EhsLutProvider(abstractionProvider, ehsStorage);
//    flop
    vector<Point> flopEhsValues;
    vector<Card> holeCards, publicCards;
    //iterating over isomorphic table(numbers from 0 to table size)
    for(uint32_t i=0; i<this->abstractionProvider->get_iso_public_cards_number(FLOP); i++){
        this->abstractionProvider->get_canonical_cards_combination(i
                                                                   , FLOP
                                                                   , holeCards
                                                                   , publicCards);
        double ehs = ehsProvider->get_EHS(holeCards
                                          , publicCards); //not implemented yet
        vector<double> isoNumEhsPair = {double(i), ehs};
        Point p = Point(double(i),isoNumEhsPair);
        flopEhsValues.push_back(p);
    }

    //turn
    vector<Point> turnEhsValues;
    for(uint32_t i=0; i<abstractionProvider->get_iso_public_cards_number(TURN); i++){
        this->abstractionProvider->get_canonical_cards_combination(i, TURN, holeCards, publicCards);
        double ehs = ehsProvider->get_EHS(holeCards, publicCards);
        vector<double> isoNumEhsPair = {double(i), ehs};
        Point p = Point(double(i),isoNumEhsPair);
        turnEhsValues.push_back(p);
    }

    //river
    vector<Point> riverEhsValues;
    for(uint32_t i=0; i<abstractionProvider->get_iso_public_cards_number(RIVER); i++){
        this->abstractionProvider->get_canonical_cards_combination(i, RIVER, holeCards, publicCards);
        double ehs = ehsProvider->get_EHS(holeCards, publicCards);
        vector<double> isoNumEhsPair = {double(i), ehs};
        Point p = Point(double(i),isoNumEhsPair);
        riverEhsValues.push_back(p);
    }
//    Run Kmeans on each table once
    KMeans kMeans(500, flopEhsValues.size(), 2, 100);
    kMeans.run(flopEhsValues);
}