/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 12:09:54 by gneri             #+#    #+#             */
/*   Updated: 2021/12/09 11:05:04 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <cctype>
#include <limits>
#define MAX_INT 2147483647
#define MIN_INT -2147483648

void	toChar(const std::string & input)
{
	char c = static_cast<char>(input[0]);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void	toInt(const std::string & input)
{
	long int ero = atol(input.c_str());
	if (ero > MAX_INT || ero < MIN_INT)
	{
		std::cout << "Error: out of range!" << std::endl;
		return ;
	}
	if ((ero >= 0 && ero <= 32) || ero == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (ero >= 33 && ero <= 126)
		std::cout << "char: " << static_cast<char>(ero) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	std::cout << "int: " << ero << std::endl;
	std::cout << "float: " << static_cast<float>(ero) << ".0f" << std::endl;
	std::cout << "double: " << static_cast<double>(ero) << ".0" << std::endl;
}

void	toFloat(const std::string & input)
{
	double f = atof(input.c_str());
	if ((f >= 0 && f <= 32) || f == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (f >= 33 && f <= 126)
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (f < MIN_INT || f > MAX_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(f) << std::endl;
	if (f - static_cast<int>(f) > 0)
		std::cout << "float: " << static_cast<float>(f) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(f) << ".0f" << std::endl;
	if (f - static_cast<int>(f) > 0)
		std::cout << "double: " << f << std::endl;
	else
		std::cout << "double: " << f << ".0" << std::endl;
}

void	toDouble(const std::string & input)
{
	double d = atof(input.c_str());
	if ((d >= 0 && d <= 32) || d == 127)
		std::cout << "char: Non displayable" << std::endl;
	else if (d >= 33 && d <= 126)
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	else
		std::cout << "char: impossible" << std::endl;
	if (d < MIN_INT || d > MAX_INT)
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << static_cast<int>(d) << std::endl;
	if (d - static_cast<int>(d) > 0)
		std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	else
		std::cout << "float: " << static_cast<float>(d) << ".0f" << std::endl;
	if (d - static_cast<int>(d) > 0)
		std::cout << "double: " << d << std::endl;
	else
		std::cout << "double: " << d << ".0" << std::endl;
}

int getType(const std::string & input)
{
    std::string float_exceptions[3] = {"-inff", "+inff", "nanf"};
    std::string double_exceptions[3] = {"-inf", "+inf", "nan"};
    
    if (input.size() == 1 && input[0] >= 33 && input[0] < 48 && input[0] > 57 && input[0] <= 126)
        return 1;
    if (input.find('.') == std::string::npos && input.find('f') == std::string::npos)
    {
        for (int i = 0; i < 3; i++)
        {
            if (!(input.compare(float_exceptions[i]) || input.compare(double_exceptions[i])))
                return 0;
        }
		return 2;
    }
	if (input.find('f') != std::string::npos)
	{
		for (int i = 0; i < 3; i++)
		{
			if (!(input.compare(double_exceptions[i])))
				return 0;
		}
		return 3;
	}
	else
		return 4;
}

int main(int argc, char **argv)
{
    if (argc == 2)
    {
        const std::string input = argv[1];
        int ret = getType(input);
		std::cout << ret << std::endl;
		switch (ret)
		{
			case 1:
				toChar(input);
				break;
			case 2:
				toInt(input);
				break;
			case 3:
				toFloat(input);
				break;
			case 4:
				toDouble(input);
				break;
		}
    }
}