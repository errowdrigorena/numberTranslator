/*
 * ConsoleOutputObserver.hpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#ifndef INCLUDE_OUTPUTINTERFACES_CONSOLEOUTPUTOBSERVER_HPP_
#define INCLUDE_OUTPUTINTERFACES_CONSOLEOUTPUTOBSERVER_HPP_

#include <OutputInterfaces/IObserver.hpp>

namespace output_interfaces
{

class Console_output_observer : public IObserver
{
public:
  ~Console_output_observer() = default;
  void update(const std::string& text) override;
};

}


#endif /* INCLUDE_OUTPUTINTERFACES_CONSOLEOUTPUTOBSERVER_HPP_ */
