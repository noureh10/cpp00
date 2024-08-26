/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 17:25:55 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/26 16:56:14 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include "Includes.hpp"

static bool	isStringValid(std::string input) {
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

static bool	isStringNumber(std::string input) {
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

static bool areStringsEqual(std::string& str1, const std::string& str2) {
	return str1 == str2;
}

int main(void)
{
	std::string		user_input;
	PhoneBook		phone_book;
	int				phone_book_index;
	bool			search_loop;
	
	std::cout << GREEN << "\nPHONEBOOK" << CRESET << std::endl;
	do {
		search_loop = true;
		std::cout << BLUE << "\nADD | SEARCH | EXIT\n" << CRESET << std::endl;
		std::cin >> user_input;
		if (std::cin.eof()){
			std::cerr << RED << "Program interrupted, exiting" << CRESET << std::endl;
			return 1;
		}
		
		if (areStringsEqual(user_input, "ADD"))
			phone_book.setContact();
		else if (areStringsEqual(user_input, "SEARCH")) {
			while (search_loop){
				phone_book.displayPhonebook();
				std::cout << CYAN << "\nPlease enter the index of the contact you want to display : " << CRESET << std::endl;
				std::cin >> user_input;
				if (std::cin.eof()) {
					std::cerr << RED << "Program interrupted, exiting" << CRESET << std::endl;
					return 1;	
				}
				if (isStringNumber(user_input)) {
					phone_book_index = atoi(user_input.c_str());
					if (phone_book_index >=0 && phone_book_index <= 7) {
						phone_book.displaySpecificContact((unsigned int) phone_book_index);
						search_loop = false;
					} else
						std::cerr << RED << "Please enter a valid index" << CRESET << std::endl;
				} else
					std::cerr << RED << "Please enter a valid index" << CRESET << std::endl;
			}
		}
		else if (areStringsEqual(user_input, "EXIT")) {
			std::cout << GREEN << "\nExiting program" << CRESET << std::endl;
			return 0;
		} else
			std::cerr << RED << "\nPlease enter a valid input" << CRESET << std::endl;
	} while (!std::cin.eof());
}
