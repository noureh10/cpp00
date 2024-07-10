/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:25:55 by nechaara          #+#    #+#             */
/*   Updated: 2024/07/10 14:10:56 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool areStringsEqual(const std::string& str1, const std::string& str2) {
	return str1 == str2;
}

int main(void)
{
	std::string	user_input;
	PhoneBook	phone_book;
	
	std::cout << GREEN << "PHONEBOOK" << CRESET << std::endl;
	do {
		std::cout << RED << "ADD | SEARCH | EXIT" << CRESET << std::endl;
		std::cin >> user_input;
		if (std::cin.eof()){
			std::cerr << RED << "Program interrupted, exiting" << CRESET << std::endl;
			return 1;
		}
		if (areStringsEqual(user_input, "ADD"))
			phone_book.setContact();
		else if (areStringsEqual(user_input, "SEARCH")){
		}
			
	} while (std::cin.eof());
	
}
