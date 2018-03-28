#pragma once
#include "ehs_lut_storage.h"
#include "cards_abstraction_provider.h"
#include <stdint.h>
#include <vector>
#include "card.h"
#include "Utils.h"
#include <memory>


// Provides access to Look-up tables built by EhsLutBuilder class.
class EhsLutProvider
{
public:
	EhsLutProvider(std::shared_ptr<CardsAbstractionProvider>& cardsAbstractionProvider,
				   std::shared_ptr<EhsLutStorage>& storage);

	/** \brief Returns EHS value for given cards combination.
	 *
	 */
	double get_EHS(
			const std::vector<Card>& hole_cards,
			const std::vector<Card>& public_cards);

	/** \brief Returns EHS Squared value for given cards combination.
	*
	*/
	double get_EHS_squared(
			const std::vector<Card>& hole_cards,
			const std::vector<Card>& public_cards);

private:
	EhsLutStorage storage;
	std::shared_ptr<CardsAbstractionProvider> abstractionProvider;
};

