#pragma once
#include <stdint.h>
#include <vector>
#include "card.h"
#include "Utils.h"

// Provides access to Look-up tables built by EhsLutBuilder class.
class EhsLutProvider
{
public:
	EhsLutProvider();

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
	// Some look-up tables or LMDB handles.

};

