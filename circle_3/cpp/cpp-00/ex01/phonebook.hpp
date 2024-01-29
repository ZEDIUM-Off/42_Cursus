/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:47:51 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 10:49:33 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include <iostream>
# include <string>
#	include <iomanip>
# include <cstdlib>



#define MAX_CONTACTS 8

typedef std::string str;
typedef unsigned int uint;

str	input(str message);

class Contact {
	private:
    str	first_name;
    str last_name;
		str nickname;
    str phone_number;
    str darkest_secret;

	public:
		Contact();
		Contact(str first_name, str last_name, str nickname, str phone_number, str darkest_secret);
		
		void 	setFirstName(str first_name);
		void 	setLastName(str last_name);
		void 	setNickname(str nickname);
		void 	setPhoneNumber(str phone_number);
		void 	setDarkestSecret(str darkest_secret);

		str		getFirstName();
		str		getLastName();
		str		getNickname();
		str		getPhoneNumber();
		str		getDarkestSecret();

		void	displayContact(int index);
		str		formatField(str field);

		void	askFields();

};

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    uint current_contact;

public:
    PhoneBook();

    void			addContact(Contact new_contact);
    Contact		getContact(int index);
    uint				getContactCount();
		void			displayContacts();
		void			search();
};

#endif