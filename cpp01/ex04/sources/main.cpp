/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 19:36:49 by nihamdan          #+#    #+#             */
/*   Updated: 2024/09/11 17:46:35 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

void	ft_replaceinFile(const std::string& filename, const std::string& s1, const std::string& s2)
{
	std::ifstream inputFile(filename.c_str());
	if(!inputFile.is_open())
	{
		std::cerr << "Erreur : impossible d'ouvrir le fichier " << filename << std::endl;
        return;
	}
	std::string fileContent((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
	inputFile.close();
	size_t pos = 0;
	while ((pos = fileContent.find(s1, pos)) != std::string::npos)
	{
		fileContent.erase(pos, s1.length());
		fileContent.insert(pos, s2);
		pos += s2.length();
	}
	std::string newFilename = filename + ".replace";
    std::ofstream outputFile(newFilename.c_str());
    if (!outputFile.is_open()) 
	{
        std::cerr << "Erreur : impossible de créer le fichier " << newFilename << std::endl;
        return;
    }
	outputFile << fileContent;
    outputFile.close();
}

int main(int argc, char **argv)
{
	if (argc != 4) 
	{
        std::cerr << "Usage: " << argv[0] << " <filename> <s1> <s2>" << std::endl;
        return 1;
    }
	std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
	ft_replaceinFile(filename, s1, s2);
	return 0;
}

