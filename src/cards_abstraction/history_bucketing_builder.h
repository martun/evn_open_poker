#pragma once

// Class for building look-up tables for EHS and EHS squared based history bucketing.
class HistoryBucketingBuilder
{
public:
	HistoryBucketingBuilder();
	
	// Builds all the required tables and saves them.
	void build_all();
	
};

