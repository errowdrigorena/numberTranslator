add_library(Core SentenceTranslator.cpp
				Translator.cpp)

add_subdirectory(Commands)
add_subdirectory(Utilities)

target_link_libraries(Core PRIVATE Commands Utilities)

target_include_directories(Core PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
