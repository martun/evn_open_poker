#pragma once
#include "bucketing_provider.h"
#include "ehs_lut_provider.h"
#include "cards_abstraction_provider.h"

// Provides bucketing based on EHS and EHS Squared values, and does history bucketing,
// I.E. each bucket number is based on the previous bucket numbers.
class HistoryBucketingProvider : public BucketingProvider
{
public:
	HistoryBucketingProvider(const BucketConfig& config);

	/** \brief Given public cards already dealt, returns the bucket number in the current round.
	*	\param[in] hole_cards Hole cards of the player.
	*	\param[in] public_cards Public cards on the table.
	*/
	uint32_t get_bucket_number(
		const std::vector<Card>& hole_cards,
		const std::vector<Card>& public_cards) override;

	/** \brief Given all 5 public cards, returns a vector of bucket numbers for all the rounds.
	*	\param[in] hole_cards Hole cards of the player.
	*	\param[in] public_cards Public cards on the table.
	*  \param[out] buckets_out A vector of 4 elements, containing bucket numbers for Preflop, Flop, Turn and River.
	*/
	void get_bucket_numbers(
		const std::vector<Card>& hole_cards,
		const std::vector<Card>& public_cards,
		std::vector<uint32_t>& buckets_out) override;
private:
	
	// Provider of EHS look-up tables.
	EhsLutProvider ehs_;

	// Provider of cards abstraction Look-up tables.
	CardsAbstractionProvider cards_abstraction_;

};

