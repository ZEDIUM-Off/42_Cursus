#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
    : AForm("Shrubbery Creation", 145, 137), _target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm(other), _target(other._target) {}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getGradeToExecute())
        throw AForm::GradeTooLowException();

    std::string filename = _target + "_shrubbery";
    std::ofstream file(filename.c_str());  // Utilisez c_str() pour convertir std::string en const char*
    if (!file.is_open())
        throw std::runtime_error("Unable to create file");

    file << "    *    " << std::endl;
    file << "   ***   " << std::endl;
    file << "  *****  " << std::endl;
    file << " ******* " << std::endl;
    file << "*********" << std::endl;
    file << "   |||   " << std::endl;

    file.close();
}
