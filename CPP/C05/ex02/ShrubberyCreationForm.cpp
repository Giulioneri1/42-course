/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneri <gneri@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:32:59 by gneri             #+#    #+#             */
/*   Updated: 2021/11/30 17:24:04 by gneri            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& form) : AForm(form), _target(form._target)
{
    
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& form)
{
    (void)form;
    return *this;
}

const char* ShrubberyCreationForm::FailOpenFile::what() const throw()
{
    return("Failed to open the file");
}

void    ShrubberyCreationForm::FormAction() const
{
    std::ofstream   file;

    file.open(this->_target + "_shrubbery");
    if (file.fail())
        throw ShrubberyCreationForm::FailOpenFile();
    file << "                                   .         ;" << std::endl;
    file << "      .              .              ;%     ;;" << std::endl;
    file << "        ,           ,                :;%  %;" << std::endl;         
    file << "         :         ;                   :;%;'     .," << std::endl;
    file << ",.        %;     %;            ;        %;'    ,;" << std::endl;  
    file << "   ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;       
    file << "    %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl;
    file << "     ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
    file << "     `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
    file << "      `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
    file << "         `:%;.  :;bd%;          %;@%;'" << std::endl;
    file << "          `@%:.  :;%.         ;@@%;'" << std::endl;
    file << "           `@%.  `;@%.      ;@@%;" << std::endl;        
    file << "            `@%%. `@%%    ;@@%;" << std::endl;
    file << "             ;@%. :@%%  %@@%;" << std::endl;           
    file << "              %@bd%%%bd%%:;" << std::endl;           
    file << "                #@%%%%%:;;" << std::endl;                  
    file << "                %@@%%%::;" << std::endl;
    file << "                %@@@%(o);  . '" << std::endl;                            
    file << "                %@@@o%;:(.,'" << std::endl;                            
    file << "            `.. %@@@o%::;" << std::endl;                           
    file << "               `)@@@o%::;" << std::endl;                           
    file << "                %@@(o)::;" << std::endl;                          
    file << "               .%@@@@%::;" << std::endl;                                  
    file << "               ;%@@@@%::;." << std::endl;                                   
    file << "               ;%@@@@%%:;;;." << std::endl;                              
    file << "            ...;%@@@@@%%:;;;;,.." << std::endl;
    file.close();
}