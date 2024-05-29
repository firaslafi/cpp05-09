/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:28 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 20:27:42 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./PmergeMe.hpp"

PmergeMe::PmergeMe()
{
}

PmergeMe::~PmergeMe()
{
}

void PmergeMe::FJSort(vector<int>& arr)
{
    FJSortRecursive(arr, 0, arr.size() - 1);
}
void PmergeMe::FJSortRecursive(vector<int>& arr, int left, int right)
{
    if (right - left < 16)
    {
        insertionSort(arr, left, right);
        return;
    }
    int mid = left + (right - left) / 2;
    FJSortRecursive(arr, left, mid);
    FJSortRecursive(arr, mid + 1, right);
    merge(arr, left, mid, right);
}
void PmergeMe::merge(vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    vector<int> L(n1);
    vector<int> R(n2);
    int i = 0;
    while (i < n1) {
        L[i] = arr[left + i];
        i++;
    }
    int j = 0;
    while (j < n2) {
        R[j] = arr[mid + 1 + j];
        j++;
    }
    i = 0;
    j = 0;
    int k = left;
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

void PmergeMe::insertionSort(vector<int>& arr, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int key = arr[i];
        int j = i - 1;
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
