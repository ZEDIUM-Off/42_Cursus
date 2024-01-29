/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:46:52 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 11:28:43 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

str	input(str message)
{
	str input;

	std::cout << message;
	if (!std::getline(std::cin, input))
        exit(1);
	return (input);
}

int main() {
    PhoneBook phonebook;
    str command;

    do {
        command = input("Enter command (ADD, SEARCH, EXIT): ");
        if (command == "ADD") {
            Contact new_contact;
            new_contact.askFields();
            phonebook.addContact(new_contact);
        } else if (command == "SEARCH") {
            phonebook.search();
        } else if (command != "EXIT") {
            std::cout << "Invalid command." << std::endl;
        }
    } while (command != "EXIT");

    return 0;
}