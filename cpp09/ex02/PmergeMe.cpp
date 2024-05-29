/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 20:54:43 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./PmergeMe.hpp"

PmergeMe::PmergeMe(int argc, char *argv[])
{
	int	num;

	for (int i = 1; i < argc; i++)
	{
		try
		{
			num = std::stoi(argv[i]);
			if (num <= 0)
			{
				std::cerr << "Invalid input: " << num << " is not a positive number." << std::endl;
				return ;
			}
			arr.push_back(num);
		}
		catch (const std::invalid_argument &e)
		{
			std::cerr << "Invalid input: '" << argv[i] << "' is not a number." << std::endl;
			return ;
		}
		catch (const std::out_of_range &e)
		{
			std::cerr << "Invalid input: '" << argv[i] << "' is out of range." << std::endl;
			return ;
		}
	}
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::FJSort(vector<int> &arr)
{
	FJSortRecursive(arr, 0, arr.size() - 1);
}
void PmergeMe::FJSortRecursive(vector<int> &arr, int left, int right)
{
	int	mid;

	if (right - left < 16)
	{
		insertionSort(arr, left, right);
		return ;
	}
	mid = left + (right - left) / 2;
	FJSortRecursive(arr, left, mid);
	FJSortRecursive(arr, mid + 1, right);
	merge(arr, left, mid, right);
}
void PmergeMe::merge(vector<int> &arr, int left, int mid, int right)
{
	int	n1;
	int	n2;
	int	i;
	int	j;
	int	k;

	n1 = mid - left + 1;
	n2 = right - mid;
	vector<int> L(n1);
	vector<int> R(n2);
	i = 0;
	while (i < n1)
	{
		L[i] = arr[left + i];
		i++;
	}
	j = 0;
	while (j < n2)
	{
		R[j] = arr[mid + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
			arr[k++] = L[i++];
		else
			arr[k++] = R[j++];
	}
	while (i < n1)
		arr[k++] = L[i++];
	while (j < n2)
		arr[k++] = R[j++];
}

void PmergeMe::insertionSort(vector<int> &arr, int left, int right)
{
	int	key;
	int	j;

	for (int i = left + 1; i <= right; i++)
	{
		key = arr[i];
		j = i - 1;
		while (j >= left && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

PmergeMe::PmergeMe(const PmergeMe &source)
{
	*this = source;
}

PmergeMe &PmergeMe::operator=(const PmergeMe &source)
{
	if (this == &source)
		return (*this);
	return (*this);
}
