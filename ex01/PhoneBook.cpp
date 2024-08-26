/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:24:59 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/26 18:26:12 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) {
	this->_number_of_contacts = 0;
	for (short i = 0; i < 8; i++) {
		this->_phonebook[i].setName(NO_CONTENT);
		this->_phonebook[i].setSurname(NO_CONTENT);
		this->_phonebook[i].setNickname(NO_CONTENT);
		this->_phonebook[i].setPhoneNumber(NO_CONTENT);
		this->_phonebook[i].setDarkestSecret(NO_CONTENT);
	}
}

PhoneBook::~PhoneBook(void) {
	return ;
}

void	PhoneBook::errorHandler(std::string message) {
	std::cerr << RED << message << CRESET << std::endl;
}

std::string PhoneBook::inputReader(std::string message, bool is_first) {
	std::string input;
	
	std::cout << YELLOW << message << CRESET << std::endl;
	if (is_first)
		std::cin.ignore();
	getline(std::cin, input);
	if (std::cin.eof()) {
		this->errorHandler("\nProgram interrupted, exiting");
		exit(EXIT_FAILURE);
	}
	return input;
}

void PhoneBook::setContact(void) {
	std::string input;
	bool		error;
	
	if (_number_of_contacts >= 8)
		_number_of_contacts = 0;
	error = false;
	input = inputReader("First Name: ", true);
	if (!_phonebook[_number_of_contacts].setName(input))
		error=true;
	input = inputReader("Last Name: ", false);
	if (!_phonebook[_number_of_contacts].setSurname(input))
		error = true;
	input = inputReader("Nickname: ", false);
	if (!_phonebook[_number_of_contacts].setNickname(input))
		error = true;
	input = inputReader("Phone number: ", false);
	if (!_phonebook[_number_of_contacts].setPhoneNumber(input))
		error = true;
	input = inputReader("Darkest secret: ", false);
	if (!_phonebook[_number_of_contacts].setDarkestSecret(input))
		error = true;
	if (error) { 
		errorHandler(ERROR_WRONG_INPUT);
		_phonebook[_number_of_contacts].setName(NO_CONTENT);
		_phonebook[_number_of_contacts].setSurname(NO_CONTENT);
		_phonebook[_number_of_contacts].setNickname(NO_CONTENT);
		_phonebook[_number_of_contacts].setPhoneNumber(NO_CONTENT);
		_phonebook[_number_of_contacts].setDarkestSecret(NO_CONTENT);
		return ; 
	}
	std::cout << GREEN << "\nContact added to the phonebook" << CRESET << std::endl;
	this->_number_of_contacts++;
}

std::string PhoneBook::displayLimit(std::string str, unsigned int limit)
{
	std::string paddedStr;

	if (limit <= 0)
		return "";
	if (str.size() > limit) {
		return str.substr(0, limit - 1) + ".";
	} else {
		paddedStr = str;
		paddedStr.append(limit - str.size(), ' ');
		return paddedStr;
	}
}

void	PhoneBook::displayPhonebook(void) {
	for (short i = 0; i < 8; i++) {
		std::cout << CYAN << "         " << i << "|"
			<< displayLimit(this->_phonebook[i].getName(), 10) << "|"
			<< displayLimit(this->_phonebook[i].getSurname(), 10) << "|"
			<< displayLimit(this->_phonebook[i].getNickname(), 10)
			<< CRESET << std::endl;
	}
}

void	PhoneBook::displaySpecificContact(unsigned int i)
{
	std::cout << CYAN << "First name : " << this->_phonebook[i].getName() << std::endl;
	std::cout << CYAN << "Last name : " << this->_phonebook[i].getSurname() << std::endl;
	std::cout << CYAN << "Nickname : " << this->_phonebook[i].getNickname() << std::endl;
	std::cout << CYAN << "Phone number : " << this->_phonebook[i].getPhoneNumber() << std::endl;
	std::cout << CYAN << "Darkest secret : " << this->_phonebook[i].getDarkestSecret() << std::endl;
}