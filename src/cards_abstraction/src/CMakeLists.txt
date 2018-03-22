set(CMAKE_VERBOSE_MAKEFILE on)

add_library(BucketingLib
    bucket_config.cpp
    cards_abstraction_provider.cpp
    card_abstraction_helper.cpp
    cards_abstraction_storage.cpp
    ehs_lut_builder.cpp
    bucketing_provider.cpp
    ehs_lut_provider.cpp
    card.cpp
    ehs_bucketing_builder.cpp       
    history_bucketing_builder.cpp
    cards_abstraction_builder.cpp  
    ehs_bucketing_provider.cpp      
    history_bucketing_provider.cpp
	)

add_subdirectory(tests)
