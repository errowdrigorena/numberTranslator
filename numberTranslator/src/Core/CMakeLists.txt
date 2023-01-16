add_library(Core TranslationOperations.cpp 
				AuxiliarOperations.cpp
				SentenceTranslator.cpp
				GuidonDecimalTranslationCommand.cpp
				ASentenceTranslationCommand.cpp
				DecimalTranslationCommand.cpp
				UnitTranslationCommand.cpp
				TeensTranslationCommand.cpp
				HundredTranslationCommand.cpp
				ThowsandTranslationCommand.cpp
				MillionTranslationCommand.cpp
				BillionTranslationCommand.cpp
				DefaultTranslationCommand.cpp
				Translator.cpp)

target_include_directories(Core PUBLIC include)
