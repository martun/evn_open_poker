#pragma once

#include "cards_abstraction_provider.h"
#include "ehs_lut_storage.h"
#include "ehs_lut_provider.h"
#include "KMeans.h"
#include "Point.h"
#include <stdint.h>
#include <vector>
#include <memory>
// Class for building look-up tables for EHS and EHS squared based bucketing.
class EhsBucketingBuilder
{
public:
	EhsBucketingBuilder(std::shared_ptr<CardsAbstractionProvider> provider);

	// Builds all the required tables and saves them.
	void build_all();

private:
	 std::shared_ptr<CardsAbstractionProvider> abstractionProvider;
};

