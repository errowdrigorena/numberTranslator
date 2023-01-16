/*
 * FileOutputObserver.cpp
 *
 *  Created on: Jan 16, 2023
 *      Author: iban
 */

#include<OutputInterfaces/FileOutputObserver.hpp>
#include<Core/Utilities/AuxiliarOperations.hpp>

namespace output_interfaces
{

File_output_observer::File_output_observer(std::string file_name) :
		file_name_{file_name}
{
	; //do nothing
}

void File_output_observer::update(const std::string& text)
{
	core::write_file(file_name_, text);
}


}


