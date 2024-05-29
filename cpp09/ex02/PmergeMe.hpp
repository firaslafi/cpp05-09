/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flafi <flafi@student.42heilbronn.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:11:31 by flafi             #+#    #+#             */
/*   Updated: 2024/05/29 22:09:49 by flafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */ // for ANIMAL
#define YELLOW  "\033[33m"      /* Yellow */ // for CAT
#define BLUE    "\033[34m"      /* Blue */ 
#define MAGENTA "\033[35m"      /* Magenta */ // for brain
#define CYAN    "\033[36m"      /* Cyan */ // for DOG
#define WHITE   "\033[37m"      /* White */
#define RESET   "\033[0m"       /* Reset color */

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <iomanip>
#include <deque>
using std::vector;
using std::cout;
using std::endl;
using std::cerr;
using std::string;
using std::deque;

class PmergeMe
{
    private:
    public:
        vector<int> arr;
        deque<int> arrdeque;
        PmergeMe(int argc, char* argv[]);
        ~PmergeMe();
        PmergeMe(const PmergeMe &source);
        PmergeMe &operator=(const PmergeMe &source);

        // void merge(std::vector<int> &v1, std::vector<int> &v2);
        // void printVector(const std::vector<int> &v);
        void FJSort(vector<int>& arr);
        void FJSortRecursive(vector<int>& arr, int left, int right);
        void merge(vector<int>& arr, int left, int mid, int right);
        void insertionSort(vector<int>& arr, int left, int right);
        void printVectorFormat(vector<int> &vec);

        void FJSortdeque(deque<int>& arr);
        void FJSortRecursivedeque(deque<int>& arr, int left, int right);
        void mergedeque(deque<int>& arr, int left, int mid, int right);
        void insertionSortdeque(deque<int>& arr, int left, int right);
        void printFormatdeque(deque<int> &vec);
}; 
#endif