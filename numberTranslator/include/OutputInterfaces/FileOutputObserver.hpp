/*
 * FileOutputObserver.hpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#ifndef INCLUDE_OUTPUTINTERFACES_FILEOUTPUTOBSERVER_HPP_
#define INCLUDE_OUTPUTINTERFACES_FILEOUTPUTOBSERVER_HPP_

#include <OutputInterfaces/IObserver.hpp>

namespace output_interfaces
{

class File_output_observer : public IObserver
{
public:
  ~File_output_observer() = default;
  File_output_observer(std::string file_name);
  void update(const std::string& text) override;
private:
  std::string file_name_;
};

}



#endif /* INCLUDE_OUTPUTINTERFACES_FILEOUTPUTOBSERVER_HPP_ */
