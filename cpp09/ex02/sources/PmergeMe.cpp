/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nihamdan <nihamdan@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 03:04:11 by nihamdan          #+#    #+#             */
/*   Updated: 2025/11/14 03:58:06 by nihamdan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iostream>
#include <algorithm>
#include <iterator>
#include <ctime>
#include <stdexcept>
#include <cstdlib>

// --- Constructeurs / opérateurs / destructeur ---

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other)
{
	(void)other;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	(void)other;
	return *this;
}

PmergeMe::~PmergeMe() {}

// --- Génération de la séquence de Jacobsthal ---

std::vector<size_t> PmergeMe::generateJacobsthalSequence(size_t n)
{
	std::vector<size_t> seq;
	seq.push_back(1);
	seq.push_back(3);

	while (seq.back() < n)
		seq.push_back(seq[seq.size() - 1] + 2 * seq[seq.size() - 2]);

	for (size_t i = 0; i < seq.size(); ++i)
	{
		if (seq[i] > n)
		{
			seq.resize(i);
			break;
		}
	}
	return seq;
}

// --- Insertion selon la séquence de Jacobsthal (corrigée) ---

template <typename Container>
void PmergeMe::insertAccordingToJacobsthal(Container &sorted, const Container &toInsert)
{
	const size_t n = toInsert.size();
	if (n == 0)
		return;

	// 1) Jacobsthal “jalons”
	std::vector<size_t> jacob = generateJacobsthalSequence(n);

	// 2) Construire l’ordre complet d’insertion
	std::vector<size_t> order;
	order.reserve(n);
	std::vector<bool> used(n, false);

	// 2a) pour chaque jalon, on insère les indices en ordre décroissant
	for (size_t i = 0; i < jacob.size(); ++i)
	{
		size_t start = (i == 0) ? 1 : jacob[i - 1] + 1;
		size_t end = jacob[i];

		if (end > n)
			end = n;
		if (start > end)
			continue;

		for (size_t j = end; j >= start; --j)
		{
			size_t idx = j - 1;
			if (!used[idx])
			{
				order.push_back(idx);
				used[idx] = true;
			}
			if (j == start)
				break; // éviter underflow
		}
	}

	// 2b) ajouter les indices restants non visités
	for (size_t i = 0; i < n; ++i)
	{
		if (!used[i])
		{
			order.push_back(i);
			used[i] = true;
		}
	}

	// 3) Insertion effective selon l’ordre
	for (size_t k = 0; k < order.size(); ++k)
	{
		typename Container::value_type value = toInsert[order[k]];
		typename Container::iterator pos = std::lower_bound(sorted.begin(), sorted.end(), value);
		sorted.insert(pos, value);
	}
}

// --- Merge-insert sort (Ford-Johnson simplifié) ---

template <typename Container>
void PmergeMe::mergeInsertSort(Container &c)
{
	if (c.size() <= 1)
		return;

	typedef typename Container::iterator It;
	Container small, large;
	typename Container::value_type leftover;
	bool hasLeftover = false;

	// --- Étape 1 : création des paires
	It it = c.begin();
	while (it != c.end())
	{
		It first = it++;
		if (it == c.end())
		{
			leftover = *first;
			hasLeftover = true;
			break;
		}

		It second = it++;
		if (*first < *second)
		{
			small.push_back(*first);
			large.push_back(*second);
		}
		else
		{
			small.push_back(*second);
			large.push_back(*first);
		}
	}

	// --- Étape 2 : tri récursif des plus grands
	mergeInsertSort(large);

	// --- Étape 3 : insertion des petits selon Jacobsthal
	insertAccordingToJacobsthal(large, small);

	// --- Étape 4 : ajout du leftover si nécessaire
	if (hasLeftover)
	{
		typename Container::iterator pos = std::lower_bound(large.begin(), large.end(), leftover);
		large.insert(pos, leftover);
	}

	// --- Étape 5 : on remplace le contenu d'origine
	c.swap(large);
}

// --- Affichage du conteneur ---

template <typename Container>
void PmergeMe::printContainer(const Container &c, const std::string &label)
{
	std::cout << label;
	for (typename Container::const_iterator it = c.begin(); it != c.end(); ++it)
		std::cout << *it << " ";
	std::cout << std::endl;
}

// --- Fonction principale : mesure et tri ---

void PmergeMe::sortAndMeasure(char **argv)
{
	std::vector<int> vec;
	std::deque<int> deq;

	for (int i = 1; argv[i]; ++i)
	{
		int n = std::atoi(argv[i]);
		if (n < 0)
			throw std::runtime_error("Error: negative number");
		vec.push_back(n);
		deq.push_back(n);
	}

	printContainer(vec, "Before: ");

	clock_t startVec = clock();
	mergeInsertSort(vec);
	clock_t endVec = clock();

	clock_t startDeq = clock();
	mergeInsertSort(deq);
	clock_t endDeq = clock();

	printContainer(vec, "After:  ");

	double vecTime = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1e6;
	double deqTime = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1e6;

	std::cout << "Time to process a range of " << vec.size()
			  << " elements with std::vector : " << vecTime << " µs" << std::endl;
	std::cout << "Time to process a range of " << deq.size()
			  << " elements with std::deque  : " << deqTime << " µs" << std::endl;
}

// --- Instanciations explicites ---
template void PmergeMe::mergeInsertSort<std::vector<int> >(std::vector<int> &);
template void PmergeMe::mergeInsertSort<std::deque<int> >(std::deque<int> &);
