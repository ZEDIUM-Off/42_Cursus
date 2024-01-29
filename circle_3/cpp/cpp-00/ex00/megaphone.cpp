/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 10:35:27 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/23 13:50:41 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <iostream>

int main(int argc, char **argv) {

	if (argc == 1)
		return (std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl, 0);
	else
	{
		for (int i = 1; i < argc; i++)
		{
			for (int j = 0; argv[i][j]; j++)
				std::cout << (char)std::toupper(argv[i][j]);
			if (i < argc - 1)
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}
