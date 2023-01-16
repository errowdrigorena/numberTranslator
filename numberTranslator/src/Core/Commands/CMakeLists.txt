add_library(Commands GuidonDecimalTranslationCommand.cpp
				ASentenceTranslationCommand.cpp
				DecimalTranslationCommand.cpp
				UnitTranslationCommand.cpp
				TeensTranslationCommand.cpp
				HundredTranslationCommand.cpp
				ThowsandTranslationCommand.cpp
				MillionTranslationCommand.cpp
				BillionTranslationCommand.cpp
				DefaultTranslationCommand.cpp)

target_include_directories(Commands PUBLIC include)