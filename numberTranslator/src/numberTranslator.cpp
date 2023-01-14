#include <iostream>
#include <optional>
#include <string.h>

void start_translation(std::string input_file_name, std::string output_file_name = {});
void provide_help();
void inform_error();

int main(int argc, char **argv)
{
    if(argc > 2 && strcmp(argv[1], "-i") == 0)
    {
    	if(argc == 3)
    	{
    		start_translation(argv[2]);
    	}
    	else if(argc == 5 && strcmp(argv[3], "-o") == 0)
    	{
    		start_translation(argv[2], argv[4]);
    	}
    	else
    	{
    		inform_error();
    	}

    }
    else if(strcmp(argv[1], "-h") == 0)
    {
    	provide_help();
    }
    else
    {
    	inform_error();
    }

	return 0;
}

void start_translation(std::string input_file_name, std::string output_file_name)
{
	std::cout << "The translation is in process. \n";
	//todo implement
	if(!output_file_name.empty())
	{
		std::cout << "output file is: " << output_file_name << ". \n";
	}
	else
	{
		std::cout << "output file doesn't exist. \n";
	}
}

void provide_help()
{
    std::cout << "There are available options are: \n"
         << "\t -h: provides help information. \n"
		 << "\t -i: provide an input plain text to be translated. "
				 "It must be at the seme level as this executable. \n"
		 << "\t -o: provides an output file name. This parameter is optional."
		 	 	 "If it is not provided otput will be shown in terminal\n"
		 << "To use the program type ./NumberTranslator -i $file_to_translate -o "
				 "$translated_file_name.";
}

void inform_error()
{
    std::cout << "Incorrect arguments. Type ./NumberTranslator -h for help. \n";
}
