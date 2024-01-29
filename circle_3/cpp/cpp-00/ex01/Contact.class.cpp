/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 11:09:46 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 11:32:51 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

Contact::Contact(){
	this->first_name = "";
	this->last_name = "";
	this->nickname = "";
	this->phone_number = "";
	this->darkest_secret = "";
};

Contact::Contact(str first_name, str last_name, str nickname, str phone_number, str darkest_secret) {
	this->first_name = first_name;
	this->last_name = last_name;
	this->nickname = nickname;
	this->phone_number = phone_number;
	this->darkest_secret = darkest_secret;
}

void Contact::setFirstName(str first_name) {
	this->first_name = first_name;
}

void Contact::setLastName(str last_name) {
	this->last_name = last_name;
}

void Contact::setNickname(str nickname) {
	this->nickname = nickname;
}

void Contact::setPhoneNumber(str phone_number) {
	this->phone_number = phone_number;
}

void Contact::setDarkestSecret(str darkest_secret) {
	this->darkest_secret = darkest_secret;
}

str Contact::getFirstName() {
	return first_name;
}

str Contact::getLastName() {
	return last_name;
}

str Contact::getNickname() {
	return nickname;
}

str Contact::getPhoneNumber() {
	return phone_number;
}

str Contact::getDarkestSecret() {
	return darkest_secret;
}

void Contact::displayContact(int index) {
	std::cout << "|" << std::setw(10) << index;
	std::cout << "|" << std::setw(10) << formatField(this->first_name);
	std::cout << "|" << std::setw(10) << formatField(this->last_name);
	std::cout << "|" << std::setw(10) << formatField(this->nickname);
	std::cout << "|" << std::endl;
}

str Contact::formatField(str field) {
	if (field.length() > 10) {
			field = field.substr(0, 9) + ".";
	}
	return field;
}

void Contact::askFields() {
	do {
		this->first_name = input("Enter first name (requis): ");
		if (this->first_name.empty())
        	std::cout << "Erreur : aucune entrée fournie." << std::endl;
	} while (this->first_name.empty());

	do {
		this->last_name = input("Enter last name (requis): ");
		if (this->last_name.empty())
		    std::cout << "Erreur : aucune entrée fournie." << std::endl;
	} while (this->last_name.empty());
	this->nickname = input("Enter nickname: ");
	do {
		this->phone_number = input("Enter phone number (requis): ");
		if (this->phone_number.empty())
		    std::cout << "Erreur : aucune entrée fournie." << std::endl;
	} while (this->phone_number.empty());
	this->darkest_secret = input("Enter darkest secret: ");
}
