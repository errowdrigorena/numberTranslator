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

namespace output_interfaces
{

class IObserver
{
public:
  virtual ~IObserver() = default;
  virtual void update(const std::string& text) = 0;
};

}

#endif /* INCLUDE_OUTPUTINTERFACES_IOBSERVER_HPP_ */
