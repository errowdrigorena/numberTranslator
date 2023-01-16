/*
 * IObserver.hpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#ifndef INCLUDE_OUTPUTINTERFACES_IOBSERVER_HPP_
#define INCLUDE_OUTPUTINTERFACES_IOBSERVER_HPP_

#include <memory>
#include <string>

class ISubject;

namespace output_interfaces
{

class IObserver
{
public:
  virtual ~IObserver() = default;
  virtual void update(const std::string& text) = 0;
  //virtual void subscribe(std::shared_ptr<ISubject> subject) = 0;
};

}

#endif /* INCLUDE_OUTPUTINTERFACES_IOBSERVER_HPP_ */
