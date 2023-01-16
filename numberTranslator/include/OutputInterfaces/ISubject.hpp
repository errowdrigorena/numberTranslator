/*
 * ISubject.hpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */
#ifndef INCLUDE_OUTPUTINTERFACES_ISUBJECT_HPP_
#define INCLUDE_OUTPUTINTERFACES_ISUBJECT_HPP_

#include<OutputInterfaces/IObserver.hpp>

namespace output_interfaces
{

class ISubject {
public:
  virtual ~ISubject() {}
  virtual void attach(std::shared_ptr<IObserver> observer) = 0;
  virtual void notify() = 0;
  virtual void shareText(const std::string& text) = 0;
};

}

#endif /* INCLUDE_OUTPUTINTERFACES_ISUBJECT_HPP_ */
