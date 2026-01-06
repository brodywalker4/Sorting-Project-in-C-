/******************************************************************
	To compile: 	g++ -Wall -fopenmp prog2_solution.cpp -o prog2
	Filename: 		program2.cpp
	Author: 		Eddie Gannod & April Crockett & Brody Walker
	Last Updated:	10/4/2025
	Purpose: 		Practice with sort algorithms and compare time
					efficiency when running the algorithms
					sequentially and in parallel

******************************************************************/
#include <iostream>
#include <vector> // used to create and use vectors
#include <fstream>
#include <parallel/algorithm> // used for sort function
#include <omp.h>			  // used for OpenMP directives
#include <ctime>			  // used for seeding randome number generator
#include <thread>			  //used for calculating number of logical processors on computer
#include <cstdlib>			  // used for random number generation
#include <chrono>			  //used for measuring elapsed time
#include "program2.h"

using namespace std;

int main()
{
	// create two vectors
	vector<int> nums;
	vector<string> words;
	string filename;
	bool success;

	// determine number of logical processors on your computer
	const auto processor_count = thread::hardware_concurrency();

	// Number of threads OpenMP will use.
	int num_threads;

	// ask the user for the number of threads
	cout << "\nHow many threads do you want OpenMP to use? (Enter 1-500) ";
	cin >> num_threads;

	while (cin.fail() || num_threads < 1 || num_threads > 500)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\nYou entered something other than an integer. \nEnter a number 1 through 500: ";
			cin >> num_threads;
		}
		else
		{
			cout << "\nThe number you entered was not between 1 and 500. \nEnter a number 1 through 500: ";
			cin >> num_threads;
		}
	}

	//*********************LOOK!************************************************
	// add in the code to validate the user's input
	// make sure the user entered in an integer 1 through 500 (and that they actually entered in an integer)

	omp_set_dynamic(false);
	omp_set_num_threads(num_threads);
	cout << "\nNumber of Threads Used: " << num_threads << endl;
	cout << "Number of Processors: " << processor_count << endl;

	// read from files & place in vectors
	do
	{
		cout << "\nWhat is the name of the string (word) text file?\n(wordsSmall.txt or wordsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(words, filename);
	} while (!success);
	do
	{
		cout << "\nWhat is the name of the string (word) text file?\n(numsSmall.txt or numsLarge.txt)\nFILENAME: ";
		cin >> filename;
		success = readFromFile(nums, filename);
	} while (!success);
	cout << "SIZE of words: " << words.size() << endl;
	cout << "SIZE of nums: " << nums.size() << endl;

	// prior to calling any of the sort algorithms, you need to scramble (unsort) the vectors
	scramble(nums);
	scramble(words);
	/*************************************************************************Parallel Sort in Algorithm Library*****************************

	 * For more information about this algorithm in particular, take a look at
	 * https://www.geeksforgeeks.org/internal-details-of-stdsort-in-c/
	 * It uses the IntroSort algorithm, which is a hybrid between Quicksort, Heapsort,
	 * and Insertion Sort.
	 *********************************************************************************/

	//****************************Parallel Sort in Algorithm Library*****************************/
	auto start = chrono::high_resolution_clock::now();
	__gnu_parallel::sort(nums.begin(), nums.end());
	auto end = chrono::high_resolution_clock::now();
	cout << "\n<parallel/algorithm> library sort(int): "
		 << chrono::duration<double>(end - start).count() << " seconds" << endl;

	start = chrono::high_resolution_clock::now();
	__gnu_parallel::sort(words.begin(), words.end());
	end = chrono::high_resolution_clock::now();
	cout << "<parallel/algorithm> library sort(words): "
		 << chrono::duration<double>(end - start).count() << " seconds" << endl;

	/*********************************************************************************
		BUBBLE SORT

		First, scramble the two vectors (call the scramble function)
		Start the clock
		Call the bubbleSort function here for nums vector
		Stop the clock
		Compute the runtime (see example above)
		Print out result to screen

		Start the clock
		Call the bubbleSort function for the words vector
		Stop the clock
		Compute the runtime
		Print out result to screen.

	 *********************************************************************************/

	scramble(nums);
	scramble(words);

	start = chrono::high_resolution_clock::now();
	bubbleSort(nums);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Bubble Sort(int): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	start = chrono::high_resolution_clock::now();
	bubbleSort(words);
	end = chrono::high_resolution_clock::now();
	cout << "Bubble sort(string): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	/*********************************************************************************
		PARALLEL BUBBLE SORT

		do all the same stuff described in bubble sort except call the
		parallelBubbleSort function
	 *********************************************************************************/

	scramble(nums);
	scramble(words);

	start = chrono::high_resolution_clock::now();
	parallelBubbleSort(nums);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Parallel bubble sort(int): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	start = chrono::high_resolution_clock::now();
	parallelBubbleSort(words);
	end = chrono::high_resolution_clock::now();
	cout << "Parallel bubble sort(strings): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	/*********************************************************************************
		MERGE SORT

		do all the same stuff described in bubble sort except call the
		mergeSort function
	 *********************************************************************************/

	scramble(nums);
	scramble(words);

	start = chrono::high_resolution_clock::now();
	mergeSort(nums, 0, nums.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Merge sort(int): ";
	cout << chrono::duration<double>(end - start).count() << " seconds";

	start = chrono::high_resolution_clock::now();
	mergeSort(words, 0, words.size() - 1);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Merge sort(strings): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	/*********************************************************************************
		PARALLEL MERGE SORT

		do all the same stuff described in bubble sort except call the
		parallelMergeSort function
	 *********************************************************************************/

	scramble(nums);
	scramble(words);

	start = chrono::high_resolution_clock::now();
	parallelMergeSort(nums, 0, nums.size() - 1, 0);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Parallel merge sort(ints): ";
	cout << chrono::duration<double>(end - start).count() << " seconds";

	start = chrono::high_resolution_clock::now();
	parallelMergeSort(words, 0, words.size() - 1, 0);
	end = chrono::high_resolution_clock::now();
	cout << endl
		 << "Parallel merge sort(strings): ";
	cout << chrono::duration<double>(end - start).count() << " seconds" << endl;

	return 0;
}

/*********************************************************
 * HELPER FUNCTIONS
 * These functions help read in the data from the files
 * scramble the data, and print the data to the console.
 * You should not have to touch these.
 **********************************************************/

/*
	Function: readFromFile()
	Purpose:
		readFromFile reads values from a file into a vector<T>.
		It returns true if the file was successfully opened and
		read, and false otherwise.
*/
template <typename T>
bool readFromFile(vector<T> &v, string filename)
{
	ifstream file;
	T tmp;

	file.open(filename);
	if (file.is_open())
	{
		// place file contents into vector
		while (file >> tmp)
		{
			v.push_back(tmp);
		}
		file.close();
		return true;
	}
	return false;
}

/*
	Function: printVector()
	Purpose:
		printVector prints each element of the vector to the screen
*/
template <typename T>
void printVector(vector<T> &v)
{
	for (int i = 0; i < 20; i++)
	{
		cout << v[i] << endl;
	}
}

/*
	Function: scramble()
	Purpose:
		scramble will randomly scramble the vector contents to
		make the vector unsorted
*/
template <typename T>
void scramble(vector<T> &v)
{
	srand(time(0));
	int randomIndex;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		randomIndex = rand() % v.size();
		swap(v[i], v[randomIndex]);
	}
}

/*************************************************
 * SORTING FUNCTIONS
 * These functions implement the sorting algorithms
 *************************************************/

// Implement all the sort algorithms below that were described in the assignment
template <typename T>
void bubbleSort(vector<T> &v)
{
	T tempForSwap;
	bool swapped;
	for (int i = 0; i < static_cast<int>(v.size()); i++)
	{
		swapped = false;
		for (int j = 0; j < static_cast<int>(v.size()) - i - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				tempForSwap = v[j];
				v[j] = v[j + 1];
				v[j + 1] = tempForSwap;
				swapped = true;
			}
		}
		if (!swapped)
		{
			break;
		}
	}
}

template <typename T>
void parallelBubbleSort(vector<T> &v)
{
	bool swapped = true;
	int size = static_cast<int>(v.size());

	while (swapped)
	{
		swapped = false;

		// parallel//v/size

#pragma omp parallel
		{
// even//
#pragma omp for reduction(|| : swapped)
			for (int i = 0; i < size - 2; i += 2)
			{
				if (v[i] > v[i + 1])
				{
					swap(v[i], v[i + 1]);
					swapped = true;
				}
			}

// odd
#pragma omp for reduction(|| : swapped)
			for (int i = 1; i < size - 2; i += 2)
			{
				if (v[i] > v[i + 1])
				{
					swap(v[i], v[i + 1]);
					swapped = true;
				}
			}
		}
	}
}

template <typename T>
void mergeSort(vector<T> &v, int i, int k)
{
	int j = 0;
	if (i < k)
	{
		j = (i + k) / 2;
		mergeSort(v, i, j);
		mergeSort(v, j + 1, k);

		merge(v, i, j, k);
	}
}

template <typename T>
void parallelMergeSort(vector<T> &v, int left, int right, int depth)
{
	int mid = 0;

	if (left < right)
	{
		mid = (left + right) / 2;

		if (depth < 4)
		{

#pragma omp parallel sections
			{
#pragma omp section
				{
					parallelMergeSort(v, left, mid, depth + 1);
				}

#pragma omp section
				{
					parallelMergeSort(v, mid + 1, right, depth + 1);
				}
			}
		}
		else
		{
			parallelMergeSort(v, left, mid, depth + 1);
			parallelMergeSort(v, mid + 1, mid, depth + 1);
		}

		merge(v, left, mid, right);
	}
}

template <typename T>
void merge(vector<T> &v, int left, int mid, int right)
{
	int n1 = mid - left + 1;
	int n2 = right - mid;

	vector<T> L(n1);
	vector<T> R(n2);

	for (int i = 0; i < n1; ++i)
	{
		L[i] = v[left + i];
	}
	for (int j = 0; j < n2; ++j)
	{
		R[j] = v[mid + 1 + j];
	}

	int i = 0, j = 0, k = left;
	while (i < n1 && j < n2)
	{
		if (L[i] <= R[j])
		{
			v[k++] = L[i++];
		}
		else
		{
			v[k++] = R[j++];
		}
	}

	while (i < n1)
	{
		v[k++] = L[i++];
	}
	while (j < n2)
	{
		v[k++] = R[j++];
	}
}
