add_library(Utilities AuxiliarOperations.cpp
				TranslationOperations.cpp )

target_include_directories(Utilities PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")