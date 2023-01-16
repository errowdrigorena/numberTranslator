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

class Console_output_observer : public IObserver//, public std::enable_shared_from_this<Console_output_observer>
{
public:
  ~Console_output_observer() = default;
  void update(const std::string& text) override;
  //void subscribe(std::shared_ptr<ISubject> subject) override;
private:
	std::weak_ptr<ISubject> subject_;
};

}


#endif /* INCLUDE_OUTPUTINTERFACES_CONSOLEOUTPUTOBSERVER_HPP_ */
