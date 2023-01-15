cmake_minimum_required (VERSION 3.1)

#Version
SET(CMAKE_CXX_STANDARD 14)

# Third Party
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)
###############################################

#project
project (numberTranslator)
include_directories(include)

add_subdirectory(src)
add_subdirectory(tst)

add_executable(NumberTranslator "${CMAKE_CURRENT_SOURCE_DIR}/src/numberTranslator.cpp")
target_link_libraries(NumberTranslator PRIVATE Core)

#tests
#copy test auxiliars
file(COPY "${CMAKE_CURRENT_SOURCE_DIR}/tst/AuxiliarFiles" DESTINATION "${CMAKE_CURRENT_BINARY_DIR}")
enable_testing()
#Maybe not the best idea
add_executable(NumberTranslatorTestCore "${CMAKE_CURRENT_SOURCE_DIR}/tst/Core/TranslationOperationsTest.cpp"
									"${CMAKE_CURRENT_SOURCE_DIR}/tst/Core/AuxiliarOperationsTest.cpp"
									"${CMAKE_CURRENT_SOURCE_DIR}/tst/Core/SentenceTranslatorTest.cpp")
target_link_libraries(NumberTranslatorTestCore 
	PRIVATE 
		GTest::gtest_main 
		Core)
#target_link_libraries(NumberTranslatorTest PRIVATE Core)

include(GoogleTest)
gtest_discover_tests(NumberTranslatorTestCore)
