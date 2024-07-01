/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:10 by nechaara          #+#    #+#             */
/*   Updated: 2024/07/01 17:19:27 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include "Includes.hpp"

class PhoneBook
{
	private: 
		Contact phone_book[8];
	public:
		PhoneBook();
		~PhoneBook();
	
		void	setContact(Contact contact);
		void	displaySpecificContact(Contact contact);
};

#endif