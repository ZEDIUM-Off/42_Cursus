/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:20:41 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 11:27:22 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook() {
	current_contact = 0;
}

void PhoneBook::addContact(Contact new_contact) {
	contacts[current_contact % MAX_CONTACTS] = new_contact;
	current_contact++;
}

Contact PhoneBook::getContact(int index) {
	if (index < 0 || (uint)index >= current_contact) {
		std::cout << "Invalid index." << std::endl;
					return Contact();
	}
	return contacts[index % MAX_CONTACTS];
}

uint PhoneBook::getContactCount() {
	return current_contact < MAX_CONTACTS ? current_contact : MAX_CONTACTS;
}

void PhoneBook::displayContacts() {
	std::cout << "     Index|First Name| Last Name|  Nickname" << std::endl;
	for (uint i = 0; i < this->getContactCount(); i++) {
		Contact contact = this->getContact(i);
		contact.displayContact(i);
	}
}

void PhoneBook::search() {
	this->displayContacts();
	str indexStr = input("Enter the index of the contact to display: ");
	if (indexStr.empty()) {
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
    }
	bool isNumber = true;
	for (str::const_iterator it = indexStr.begin(); it != indexStr.end(); ++it) {
		if (!std::isdigit(*it)) {
			isNumber = false;
			break;
		}
	}
	if (!isNumber) {
		std::cout << "Invalid input. Please enter a number." << std::endl;
		return;
	}
	int index = atoi(indexStr.c_str());
	if (index < 0 || (uint)index >= this->getContactCount()) {
		std::cout << "Invalid index." << std::endl;
	} else {
		Contact contact = this->getContact(index);
		contact.displayContact(index);
	}
}