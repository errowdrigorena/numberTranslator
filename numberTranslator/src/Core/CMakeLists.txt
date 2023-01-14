add_library(Core TranslationOperations.cpp 
				AuxiliarOperations.cpp
				NumberCompositionHandler.cpp)

target_include_directories(Core PUBLIC include)
