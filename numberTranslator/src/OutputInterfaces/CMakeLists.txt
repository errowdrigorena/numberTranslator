add_library(OutputInterfaces DisplayerSubject.cpp
								ConsoleOutputObserver.cpp)

target_include_directories(OutputInterfaces PUBLIC include)
