/*
 * ConsoleOutputObserver.cpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */
#include <OutputInterfaces/ConsoleOutputObserver.hpp>
#include <OutputInterfaces/ISubject.hpp>
#include <iostream>

namespace output_interfaces
{

void Console_output_observer::update(const std::string& text)
{
  std::cout << text;
}


}


