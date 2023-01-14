/*
 * AuxiliarOperations.hpp
 *
 *  Created on: Jan 14, 2023
 *      Author: iban
 */

#ifndef SRC_CORE_AUXILIAROPERATIONS_HPP_
#define SRC_CORE_AUXILIAROPERATIONS_HPP_

#include <string>
#include <vector>

namespace core
{
	std::string convert_to_lowercase(const std::string& word);

	std::vector<std::string> read_file_line_by_line(const std::string& fileName);
}



#endif /* SRC_CORE_AUXILIAROPERATIONS_HPP_ */
