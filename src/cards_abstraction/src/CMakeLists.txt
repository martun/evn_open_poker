set(CMAKE_VERBOSE_MAKEFILE on)


add_library(IsomorphismLib
		cards_abstraction_builder.cpp
		cards_abstraction_provider.cpp
		card_abstraction_helper.cpp
		cards_abstraction_storage.cpp
		card.cpp
		)

add_library(EhsLib
		ehs_lut_builder.cpp
		ehs_lut_storage.cpp
		ehs_lut_provider.cpp
		)
target_link_libraries(EhsLib
		IsomorphismLib
)
add_library(BucketingLib
		bucket_config.cpp
		bucketing_provider.cpp
		ehs_bucketing_builder.cpp
		history_bucketing_builder.cpp
		ehs_bucketing_provider.cpp
		history_bucketing_provider.cpp
		)
target_link_libraries(BucketingLib
		EhsLib)

add_subdirectory(tests)
