#include "../cards_abstraction_provider.h"

#include <cmath>

CardsAbstractionProvider::CardsAbstractionProvider(
  std::shared_ptr<CardsAbstractionStorage>& storage)
  : storage(storage)
{
}

uint32_t CardsAbstractionProvider::get_hand_iso_number(
    const std::vector<Card>& hole_cards,
    const std::vector<Card>& public_cards){
  if(public_cards.empty()){
    std::vector<std::vector<uint8_t >> possible_combination;
    possible_combination.resize(4);

    CardsAbstractionHelper::add_card(&hole_cards[0], &possible_combination);
    CardsAbstractionHelper::add_card(&hole_cards[1], &possible_combination);

    CardsAbstractionHelper::sort_vector(&possible_combination);
    CardsAbstractionHelper::erase_emptys(&possible_combination);
    size_t hash_=CardsAbstractionHelper::hash(&possible_combination);

    auto search=storage->preflop_index_table.find(hash_);

    return search->second;
  }
  else {
    uint32_t publicIso = get_public_cards_iso_number(public_cards);
    uint8_t x = hole_cards[0].get_suit() * 4 + hole_cards[0].get_rank();
    uint8_t y = hole_cards[1].get_suit() * 4 + hole_cards[1].get_rank();
    if (x > y)
      std::swap(x, y);
    return uint32_t(publicIso * (52 * 52) + (x * 52 + y));
  }
}

uint32_t CardsAbstractionProvider::get_public_cards_iso_number(const std::vector<Card>& public_cards){
  std::vector<std::vector<uint8_t >> possible_combination;
  possible_combination.resize(4);
  for(uint32_t i = 0; i < public_cards.size(); ++i) {
    CardsAbstractionHelper::add_card(&public_cards[i], &possible_combination);
  }
  CardsAbstractionHelper::sort_vector(&possible_combination);
  CardsAbstractionHelper::erase_emptys(&possible_combination);
  size_t hash_=CardsAbstractionHelper::hash(&possible_combination);
  auto search=storage->flop_index_table.find(hash_);
  switch(public_cards.size()){
    case 3:
      search=storage->flop_index_table.find(hash_);
      break;
    case 4:
      search=storage->turn_index_table.find(hash_);
      break;
    case 5:
      search=storage->river_index_table.find(hash_);
  }
  return search->second;
}

void CardsAbstractionProvider::get_canonical_public_cards(
    uint32_t iso_number, Round r, std::vector<Card>& public_cards_out)
{
  auto search= storage->flop_card_table.find(iso_number);;

  switch(r) {
    case PREFLOP:
      return;
    case FLOP:
      search = storage->flop_card_table.find(iso_number);
      break;

    case TURN:
      search = storage->turn_card_table.find(iso_number);
      break;
    case RIVER:
      search = storage->flop_card_table.find(iso_number);
  }
  std::vector<Card> c=search->second;
  for(uint8_t i=0;i<c.size();++i) {
    public_cards_out.push_back(c[i]);
  }
}



void CardsAbstractionProvider::get_canonical_cards_combination(
    uint32_t iso_number,Round r,
    std::vector<Card>& hole_cards_out,
    std::vector<Card>& public_cards_out) {
  if(r==PREFLOP){
    auto search=storage->preflop_card_table.find(iso_number);
    hole_cards_out.push_back(search->second[0]);
    hole_cards_out.push_back(search->second[1]);
  }
  else {
    uint32_t holeIsoNumber = iso_number % ((uint32_t) (52 * 52));
    uint8_t x = holeIsoNumber / 52;
    uint8_t y = holeIsoNumber % 52;
    hole_cards_out.push_back(Card(x));
    hole_cards_out.push_back(Card(y));
    uint32_t public_iso_number = uint32_t((iso_number - holeIsoNumber) / (52 * 52));
    get_canonical_public_cards(public_iso_number, r, public_cards_out);
  }
}



uint32_t CardsAbstractionProvider::get_iso_public_cards_number(Round r) {
  switch(r) {
    case PREFLOP:
      return 0;
    case FLOP :
      return storage->flop_card_table.size();
    case TURN:
      return storage->turn_card_table.size();
    case RIVER:
      return storage->river_card_table.size();
  }
  throw "Invalid value of round in get_iso_public_cards_number";
}

