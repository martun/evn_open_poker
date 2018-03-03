#pragma once

// Class for building look-up tables for EHS and EHS squared based bucketing.
class EhsBucketingBuilder
{
public:
	EhsBucketingBuilder();

	// Builds all the required tables and saves them.
	void build_all();
};

