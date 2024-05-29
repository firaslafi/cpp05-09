/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 22:13:16 by flafi            ###   ########.fr       */
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
			arrdeque.push_back(num);
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
void PmergeMe::merge(vector<int> &array, int left_index, int middle_index, int right_index)
{
    int left_size;
    int right_size;
    int i;
    int j;
    int k;

    left_size = middle_index - left_index + 1;
    right_size = right_index - middle_index;
    vector<int> left_array(left_size);
    vector<int> right_array(right_size);
    i = 0;
    while (i < left_size)
    {
        left_array[i] = array[left_index + i];
        i++;
    }
    j = 0;
    while (j < right_size)
    {
        right_array[j] = array[middle_index + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    k = left_index;
    while (i < left_size && j < right_size)
    {
        if (left_array[i] <= right_array[j])
            array[k++] = left_array[i++];
        else
            array[k++] = right_array[j++];
    }
    while (i < left_size)
        array[k++] = left_array[i++];
    while (j < right_size)
        array[k++] = right_array[j++];
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

void PmergeMe::printVectorFormat(vector<int> &vec)
{
    cout << YELLOW << "Before: " << RESET;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
	
	std::clock_t start = std::clock();
    FJSort(vec);
	std::clock_t end = std::clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
    cout << GREEN << "After: " << RESET;
    for (int i = 0; i < vec.size(); i++)
        cout << vec[i] << " ";
    cout << endl;
    cout << "Time to process a range of " << vec.size() << " elements with std::vector: " << YELLOW << std::fixed << std::setprecision(6) << duration << RESET << " micro seconds" << endl;
}
// deque version
void PmergeMe::FJSortdeque(deque<int> &arr)
{
	FJSortRecursivedeque(arr, 0, arr.size() - 1);
}

void PmergeMe::FJSortRecursivedeque(deque<int>& arr, int left, int right)
{
	int	mid;

	if (right - left < 16)
	{
		insertionSortdeque(arr, left, right);
		return ;
	}
	mid = left + (right - left) / 2;
	FJSortRecursivedeque(arr, left, mid);
	FJSortRecursivedeque(arr, mid + 1, right);
	mergedeque(arr, left, mid, right);
}

void PmergeMe::mergedeque(deque<int> &array, int left_index, int middle_index, int right_index)
{
	int left_size;
	int right_size;
	int i;
	int j;
	int k;

	left_size = middle_index - left_index + 1;
	right_size = right_index - middle_index;
	deque<int> left_array(left_size);
	deque<int> right_array(right_size);
	i = 0;
	while (i < left_size)
	{
		left_array[i] = array[left_index + i];
		i++;
	}
	j = 0;
	while (j < right_size)
	{
		right_array[j] = array[middle_index + 1 + j];
		j++;
	}
	i = 0;
	j = 0;
	k = left_index;
	while (i < left_size && j < right_size)
	{
		if (left_array[i] <= right_array[j])
			array[k++] = left_array[i++];
		else
			array[k++] = right_array[j++];
	}
	while (i < left_size)
		array[k++] = left_array[i++];
	while (j < right_size)
		array[k++] = right_array[j++];
}

void	PmergeMe::insertionSortdeque(deque<int> &arr, int left, int right)
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

void PmergeMe::printFormatdeque(deque<int> &deq)
{
	cout << YELLOW << "Before: " << RESET;
	for (int i = 0; i < deq.size(); i++)
		cout << deq[i] << " ";
	cout << endl;
	
	std::clock_t start = std::clock();
	FJSortdeque(deq);
	std::clock_t end = std::clock();
	double duration = (double)(end - start) / CLOCKS_PER_SEC;
	cout << GREEN << "After: " << RESET;
	for (int i = 0; i < deq.size(); i++)
		cout << deq[i] << " ";
	cout << endl;
	cout << "Time to process a range of " << deq.size() << " elements with std::deque: " << YELLOW << std::fixed << std::setprecision(6) << duration << RESET << " micro seconds" << endl;
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
