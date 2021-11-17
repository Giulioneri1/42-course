/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 10:42:22 by gneri             #+#    #+#             */
/*   Updated: 2021/11/13 12:09:05 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cout << "Error: Wrong number of arguments" << std::endl;
        return (EXIT_FAILURE); 
    }
    const std::string&	filename = argv[1];
	std::string			s1 = argv[2];
	const std::string&	s2 = argv[3];
    
    std::ifstream   input_file; // FILE TO READ FROM 
    std::ofstream   output_file; // FILE TO WRITE INTO

    input_file.open(filename); //OPENING THE INPUT FILE
    if (input_file.is_open())
    {
		output_file.open(filename + ".replace"); //OPENING THE OUTPUT FILE
		if (output_file.fail())
			std::cout << "Unable to open the file " << std::endl;
		std::string str;
		while (std::getline(input_file, str)) //CHECK EACH LINE UNTIL END OF FILE
		{
            std::size_t found = 0;
            while ((found = str.find(s1)) != std::string::npos && (s1 != s2)) //CHECK IF THE STRING IS FOUND
            {
                str.erase(found, s1.length());
                str.insert(found, s2);
            }
            output_file << str << std::endl;
        }
        input_file.close();
    }
	else
		std::cout << "Unable to open the file " << std::endl;
    output_file.close();    
}