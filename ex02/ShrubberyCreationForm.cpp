#include "ShrubberyCreationForm.hpp"

const int ShrubberyCreationForm::_SIGN = 145;
const int ShrubberyCreationForm::_EXEC = 137;

ShrubberyCreationForm::ShrubberyCreationForm(): Form("Shrubbery", "UNKNOWN", _SIGN, _EXEC) {
	this->_target = "UNKNOWN";
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target): Form("Shrubbery", target, _SIGN, _EXEC) {
	this->_target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &shrubberyCreationForm) :
		Form("Shrubbery", shrubberyCreationForm._target, _SIGN, _EXEC) {
	*this = shrubberyCreationForm;
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
	return;
}

ShrubberyCreationForm & ShrubberyCreationForm::operator=(ShrubberyCreationForm const &shrubberyCreationForm) {
	(void)shrubberyCreationForm;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const {
	std::ofstream  out_file;

	Form::execute(executor);
	out_file.open(Form::getTarget() + "_shrubbery", std::ofstream::out | std::ofstream::trunc);
	if (out_file.fail())
		std::cerr << "Error when opening the outfile" << std::endl;

	out_file << "          1          " << std::endl;
	out_file << "         / \\         " << std::endl;
	out_file << "        /   \\        " << std::endl;
	out_file << "       /     \\       " << std::endl;
	out_file << "      2       3      " << std::endl;
	out_file << "     / \\     / \\     " << std::endl;
	out_file << "    4   5   6   7    " << std::endl;
	out_file << "   /   / \\     / \\   " << std::endl;
	out_file << "  8   9   1   2   3  " << std::endl;
	out_file << "     /               " << std::endl;
	out_file << "    4                " << std::endl;
	out_file.close();
}