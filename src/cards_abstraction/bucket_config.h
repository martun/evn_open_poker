#pragma once
#include <stdint.h>

// Configurations for bucketing algorithm.
struct BucketConfig
{
	BucketConfig();
	
	// Number of buckets for preflop.
	uint32_t preflop_buckets_number;
	
	// After the preflop is done, we may want to use another number of preflop buckets for history bucketing.
	uint32_t preflop_buckets_after_number;

	uint32_t flop_buckets_number;
	uint32_t flop_buckets_after_number;

	uint32_t turn_buckets_number;
	uint32_t turn_buckets_after_number;

	uint32_t river_buckets_number;

};