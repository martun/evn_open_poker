#include "ehs_lut_provider.h"

EhsLutProvider::EhsLutProvider(
        std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
        std::shared_ptr<EhsLutStorage>& storage)
        : storage(*storage), abstractionProvider(cardsAbstractionProvider)
{
}

double EhsLutProvider::get_EHS(
        const std::vector<Card>& hole_cards,
        const std::vector<Card>& public_cards){

    uint32_t isoNum = abstractionProvider->get_hand_iso_number(hole_cards,public_cards);

    switch (public_cards.size()){
        case 0:
            return storage.preflop_ehs_table.find(isoNum)->second;
        case 3:
            return storage.flop_ehs_table.find(isoNum)->second;
        case 4:
            return storage.turn_ehs_table.find(isoNum)->second;
        case 5:
            return storage.river_ehs_table.find(isoNum)->second;
        default:
            throw ("Invalid number of public cards");
    }
}


double EhsLutProvider::get_EHS_squared(
        const std::vector<Card>& hole_cards,
        const std::vector<Card>& public_cards){

    uint32_t isoNum = abstractionProvider->get_hand_iso_number(hole_cards,public_cards);

    switch (public_cards.size()){
        case 0:
            return storage.preflop_ehs_table.find(isoNum)->second;
        case 3:
            return storage.flop_ehs_table.find(isoNum)->second;
        case 4:
            return storage.turn_ehs_table.find(isoNum)->second;
        case 5:
            return storage.river_ehs_table.find(isoNum)->second;
        default:
            throw ("Invalid number of public cards");
    }
}