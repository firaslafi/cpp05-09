/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:32:26 by flafi             #+#    #+#             */
/*   Updated: 2024/04/26 15:40:52 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./ShrubberyCreationForm.hpp"
# include <fstream>
ShrubberyCreationForm::ShrubberyCreationForm(void): Form("ShrubberyCreationForm", 145, 137)
{
    this->_target = "defaultTarget";
}

ShrubberyCreationForm::ShrubberyCreationForm(string target): Form("ShrubberyCreationForm", 145, 137), _target(target)
{
    // this->_target = "defaultTarget";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    
}
// copy assign and copy operator
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &source): Form(source)
{
    *this = source;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &source)
{
    this->_target = source._target;
    return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (this->getSigned() == false)
        throw Form::FormNotSignedException();
    else if (executor.getGrade() > this->getGradeToExecute())
        throw Form::GradeTooLowException();
    // run the tree in ASCII
    std::ofstream myFile(_target + "_shrubbery");
    myFile <<"                    ,@@@@@@@," << endl;
    myFile <<"       ,,,.   ,@@@@@@@@,  .oo8888o." << endl;
    myFile <<"    ,&%%&%&&%,@@@@@@@@@@@,8888888o" << endl;
    myFile <<"   ,%&\%&&%&&%,@@@@@@/@@@888888888'" << endl;
    myFile <<"   %&&%&%&/%&&%@@@@/ /@@@8888888888'" << endl;
    myFile <<"   %&&%/ %&%%&&@@ V /@@' `888 `/88'" << endl;
    myFile <<"   `&% ` /%&'    |.|         '|8'" << endl;
    myFile <<"       |o|        | |         | |" << endl;
    myFile <<"       |.|        | |         | |" << endl;
    myFile <<" jgs \\/ ._//_/__/  ,_//__\\/.  _//__/_" << endl;
    myFile.close();
}

std::ostream &operator<<(std::ostream &outpudstream, ShrubberyCreationForm const &obj)
{
    outpudstream << "ShrubberyCreationForm under the name of " << obj.getName() << endl;
    return (outpudstream);
}