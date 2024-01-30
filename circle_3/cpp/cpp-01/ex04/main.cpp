/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchenava <mchenava@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:24:04 by  mchenava         #+#    #+#             */
/*   Updated: 2024/01/30 13:45:57 by mchenava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

typedef std::string str;

int main(int argc, char* argv[])
{
	if (argc != 4) {
		std::cerr << "Usage: ./replace filename s1 s2" << std::endl;
		return 1;
	}

	str	filename = argv[1];
	str	s1 = argv[2];
	str	s2 = argv[3];

	if (s1.empty() || s2.empty()) {
		std::cerr << "Error: s1 and s2 cannot be empty" << std::endl;
		return 1;
	}

	std::ifstream input(filename.c_str());
	if (!input.is_open()) {
		std::cerr << "Error: Could not open file " << filename << std::endl;
		return 1;
	}

	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open()) {
		std::cerr << "Error: Could not create file " << filename + ".replace" << std::endl;
		return 1;
	}

	bool found = false;
	str	line;
	while (std::getline(input, line))
	{
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != str::npos)
		{
			line.erase(pos, s1.length());
			line.insert(pos, s2);
			pos += s2.length();
			found = true;
		}
		if (!line.empty() && line[line.size() - 1] == '\n')
			output << line << '\n';
		else
			output << line;
	}

	if (!found) {
		std::cerr << "Warning: s1 was not found in the file" << std::endl;
	}

	input.close();
	output.close();

	return 0;
}