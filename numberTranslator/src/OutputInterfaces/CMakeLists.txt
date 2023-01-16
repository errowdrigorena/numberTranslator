add_library(OutputInterfaces DisplayerSubject.cpp
								ConsoleOutputObserver.cpp
								FileOutputObserver.cpp)

target_include_directories(OutputInterfaces PUBLIC include)
