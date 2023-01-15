add_library(Core TranslationOperations.cpp 
				AuxiliarOperations.cpp
				SentenceTranslator.cpp)

target_include_directories(Core PUBLIC include)
