/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nechaara <nechaara.student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 15:19:38 by nechaara          #+#    #+#             */
/*   Updated: 2024/08/26 16:26:03 by nechaara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
#define CONTACT_HPP

#include "Includes.hpp"

class Contact
{
	private:
		std::string _name;
		std::string _surname;
		std::string _nickname;
		std::string _phone_number;
		std::string _darkest_secret;
		bool	isStringValid(std::string input);
		bool	isStringNumber(std::string input);
	public:
		bool		setName(std::string name);
		std::string	getName(void);
		bool		setSurname(std::string surname);
		std::string	getSurname(void);
		bool		setNickname(std::string nickname);
		std::string	getNickname(void);
		bool		setPhoneNumber(std::string phone_number);
		std::string	getPhoneNumber(void);
		bool		setDarkestSecret(std::string darkest_secret);
		std::string	getDarkestSecret(void);
};

#endif