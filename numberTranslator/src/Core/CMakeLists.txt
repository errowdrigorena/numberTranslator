add_library(Core TranslationOperations.cpp 
				AuxiliarOperations.cpp
				SentenceTranslator.cpp
				Translator.cpp)

add_subdirectory(Commands)
target_link_libraries(Core PRIVATE Commands)

target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
