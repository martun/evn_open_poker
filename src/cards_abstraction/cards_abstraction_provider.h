#pragma once
#include <stdint.h>
#include <vector>
#include <memory>
#include "card.h"
#include "Utils.h"
#include "cards_abstraction_storage.h"
#include "cards_abstraction_builder.h"

// This class provides access to cards abstraction functionality after the necessary
// look-up tables were built. Reads up lookup tables into the memory.
class CardsAbstractionProvider
{
public:
	CardsAbstractionProvider(std::shared_ptr<CardsAbstractionStorage>& storage);
	
	// Returns isomorphic number of the given hole+public cards combination.
	uint32_t get_hand_iso_number(
		const std::vector<Card>& hole_cards, 
		const std::vector<Card>& public_cards);

	// Returns isomorphic number of the given public cards set.
	uint32_t get_public_cards_iso_number(
		const std::vector<Card>& public_cards);

	/** \brief Given isomorphic number returns the canonical set of public cards.
	 *  \param[in] iso_number The isomorphic number.
	 *  \param[out] public_cards_out Canonical Public cards for the given isomorphic number.
	 */
	void get_canonical_public_cards(
		uint32_t iso_number,
    Round r, 
    std::vector<Card>& public_cards_out);

	/** \brief Given isomorphic number returns the canonical set of hole cards and public cards.
	*  \param[in] iso_number The isomorphic number.
	*  \param[out] hole_cards_out Canonical Hole cards for the given isomorphic number.
	*  \param[out] public_cards_out Canonical Public cards for the given isomorphic number.
	*/
	void get_canonical_cards_combination(
		uint32_t iso_number, Round r,
    std::vector<Card>& hole_cards_out,
		std::vector<Card>& public_cards_out);

	// Returns the total number of iso public cards for the given round.
	uint32_t get_iso_public_cards_number(Round r);

private:

  // Shared pointer to the storage. Storage must be pre-loaded. 
  std::shared_ptr<CardsAbstractionStorage> storage;

};

