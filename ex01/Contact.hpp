/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:38 by nechaara          #+#    #+#             */
/*   Updated: 2024/07/16 00:49:55 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Includes.hpp"

class Contact
{
	private:
		std::string name;
		std::string surname;
		std::string nickname;
		std::string phone_number;
		std::string darkest_secret;

		bool	is_string_valid(std::string input) {
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

	public:
		bool	setName(std::string name) {
			if (!is_string_valid(name))
				return false;
			this->name = name;
			return true;
		}
		std::string	getName(void) {
			return name;
		}
		bool	setSurname(std::string surname) {
			if (!is_string_valid(name))
				return false;
			this->surname = surname;
			return true;
		}
		std::string getSurname(void) {
			return surname;
		}
		bool	setNickname(std::string nickname) {
			if (!is_string_valid(name))
				return false;
			this->nickname = nickname;
			return true;
		}
		std::string getNickname(void) {
			return nickname;
		}
		bool	setPhoneNumber(std::string phone_number) {
			if(!is_string_valid(phone_number))
				return false;
			this->phone_number = phone_number;
			return true;
		}
		std::string getPhoneNumber(void) {
			return phone_number;
		}
		bool	setDarkestSecret(std::string darkest_secret) {
			if (!is_string_valid(darkest_secret))
				return false;
			this->darkest_secret = darkest_secret;
			return true;
		}
		std::string getDarkestSecret(void) {
			return darkest_secret;
		}
};

#endif