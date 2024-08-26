/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 15:44:22 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/26 16:25:41 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

bool	Contact::isStringValid(std::string input) {
	const char *str_check;
	
	if (input.empty())
		return false;
	str_check = input.c_str();
	for (long unsigned int i = 0; i < input.size(); i++) {
		if (!isascii(str_check[i]))
			return false;
	}
	return true;
}

bool Contact::isStringNumber(std::string input) {
	const char *num_check;
	
	if (!isStringValid(input))
		return false;
	num_check = input.c_str();
	for (long unsigned int i = 0; i < input.size(); i++) {
		if (!isnumber(num_check[i]))
			return false;
	}
	return true;
} 

bool	Contact::setName(std::string name) {
			if (!isStringValid(name))
				return false;
			this->_name = name;
			return true;
		}
std::string	Contact::getName(void) {
	return _name;
}

bool	Contact::setSurname(std::string surname) {
	if (!isStringValid(surname))
		return false;
	this->_surname = surname;
	return true;
}
std::string Contact::getSurname(void) {
	return _surname;
}
bool	Contact::setNickname(std::string nickname) {
	if (!isStringValid(nickname))
		return false;
	this->_nickname = nickname;
	return true;
}
std::string Contact::getNickname(void) {
	return _nickname;
}
bool	Contact::setPhoneNumber(std::string phone_number) {
	if(!isStringNumber(phone_number))
		return false;
	this->_phone_number = phone_number;
	return true;
}
std::string Contact::getPhoneNumber(void) {
	return _phone_number;
}
bool	Contact::setDarkestSecret(std::string darkest_secret) {
	if (!isStringValid(darkest_secret))
		return false;
	this->_darkest_secret = darkest_secret;
	return true;
}
std::string Contact::getDarkestSecret(void) {
	return _darkest_secret;
}