/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pmergeme.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 03:04:45 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/14 03:47:50 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <vector>
# include <deque>
# include <string>
# include <cstddef>
# include <iostream>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe();

		void sortAndMeasure(char **argv);

	private:
		// Génération de la séquence de Jacobsthal
		static std::vector<size_t> generateJacobsthalSequence(size_t n);

		// Insertion selon l’ordre défini par Jacobsthal
		template <typename Container>
		static void insertAccordingToJacobsthal(Container &sorted, const Container &toInsert);

		// Tri principal (merge-insert sort)
		template <typename Container>
		static void mergeInsertSort(Container &c);

		// Affichage générique du contenu d’un conteneur
		template <typename Container>
		static void printContainer(const Container &c, const std::string &label);
};

#endif
