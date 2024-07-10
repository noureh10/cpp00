/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:10 by nechaara          #+#    #+#             */
/*   Updated: 2024/07/08 13:55:33 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Includes.hpp"

class PhoneBook
{
	private: 
		Contact		_phonebook[8];
		int			_number_of_contacts;
		std::string	inputReader(std::string message);
		std::string	displayLimit(std::string str, unsigned int limit);
		void		errorHandler(std::string message);
		
	public:
		PhoneBook();
		~PhoneBook();
	
		void	setContact(void);
		void	displaySpecificContact(unsigned int i);
		void	displayPhonebook(void);
};

#endif