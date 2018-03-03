#pragma once
#include <stdint.h>
#include <vector>
#include "bucket_config.h"
#include "card.h"
#include "Utils.h"

// Abstract class for all bucketing providers.
class BucketingProvider
{
public:
	BucketingProvider(const BucketConfig& config);

	/** \brief Given public cards already dealt, returns the bucket number in the current round.
	*	\param[in] hole_cards Hole cards of the player.
	*	\param[in] public_cards Public cards on the table.
	*/
	virtual uint32_t get_bucket_number(
		const std::vector<Card>& hole_cards,
		const std::vector<Card>& public_cards) = 0;

	/** \brief Given all 5 public cards, returns a vector of bucket numbers for all the rounds.
	 *	\param[in] hole_cards Hole cards of the player.
	 *	\param[in] public_cards Public cards on the table.
	 *  \param[out] buckets_out A vector of 4 elements, containing bucket numbers for Preflop, Flop, Turn and River.
	 */
	virtual void get_bucket_numbers(
		const std::vector<Card>& hole_cards,
		const std::vector<Card>& public_cards,
		std::vector<uint32_t>& buckets_out) = 0;

protected: 

	// Bucketing algorithm configuration.
	BucketConfig config_;
};

