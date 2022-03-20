/*

Author: Andrew Vinci
Class: CSI-281 - Data Structures and Algorithms
Assignment: PA3 - Part 4
Date Assigned: 02/20/2022
Due Date: 02/28/2022 @ 11:10 a.m.
Description:
This file holds all the logic for my testing algorithms.
Certification of Authenticity:
I certify that this is entirely my own work, except where I have given
fully-documented references to the work of others. I understand the definition and
consequences of plagiarism and acknowledge that the assessor of this assignment
may, for the purpose of assessing this assignment:
- Reproduce this assignment and provide a copy to another member of academic staff;
and/or
- Communicate a copy of this assignment to a plagiarism checking service (which may
then retain a copy of this assignment on its database for the purpose of future
plagiarism checking)

Cite: This code contains code from a former Champlain Student in the form of a
timer system. Each function that uses this timer also cites this work but I'm
also citing it in the header as well.
*/




#include <iostream>
#include <iomanip>
#include <fstream>
#include <time.h>
#include <cstdlib>
#include <stdio.h>
#include "testing.h"

using namespace std;
/* Cite: This is Another Students Timer System that I'm using for this project.*/

/*      Pre:  None
 *     Post:  The private members are initialized
 *  Purpose:  Default constructor for the TimerSystem
******************************************************************************/
TimerSystem::TimerSystem()
{
	start.QuadPart = 0;
	finish.QuadPart = 0;

	//Sets the clock frequency for the system we are running on
	QueryPerformanceFrequency(&freq);
}


/*      Pre:  The stopwatch must be initialized and started
 *     Post:  The elapse time is returned to the caller
 *  Purpose:  Gets time in seconds since the stopwatch has started
 ******************************************************************************/
double TimerSystem::getTime()
{
	QueryPerformanceCounter(&finish);  //get end cpu cycles

   // return the amount of time elapsed
	return static_cast<double>((finish.QuadPart - start.QuadPart) / static_cast<double>(freq.QuadPart));
}


/*      Pre:  The stopwatch must be initialized
 *     Post:  The start private member is reset
 *  Purpose:  To start the stopwatch
 ******************************************************************************/
void TimerSystem::startClock()
{
	//get the top of the frames CPU count
	QueryPerformanceCounter(&start);
}







/*
Pre: Takes in an array of any type and an int.

Post: Performs bubble sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using bubble sort in ascending/alphabetical order.
*/

template <typename T>
void bubbleSort(T list[], int size) {

	bool swapped = true;

	while (swapped == true) {

		swapped = false;

		for (int i = 0; i < size - 1; i++) {
			if (list[i + 1] < list[i]) {
				T temp = list[i + 1];
				list[i + 1] = list[i];
				list[i] = temp;
				swapped = true;
			}
		}
	}
};

/*
Pre: Takes in an array of any type and an int.

Post: Performs insertion sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using insertion sort in ascending/alphabetical order.
*/

template <typename T>
void insertionSort(T list[], int size) {

	int j;

	for (int i = 1; i < size; i++) {
		T value = list[i];
		j = i - 1;

		while (j >= 0 && list[j] > value) {
			list[j + 1] = list[j];
			j -= 1;
		}

		list[j + 1] = value;
	}
}



/*
Pre: Takes in an array of any type and an int.

Post: Performs selection sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using selection sort in ascending/alphabetical order.
*/


template <typename T>
void selectionSort(T list[], int size) {
	int i, j, minIndex;

	for (i = 0; i < size - 1; i++) {
		minIndex = i;

		for (j = i + 1; j < size; j++) {
			if (list[j] < list[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			T temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}


/*
Pre: Takes in an array of any type and an int.

Post: Performs selection sort descending on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using selection sort in descending order.
*/

template <typename T>
void selectionSortDescending(T list[], long int size) {
	long int i, j, minIndex;

	for (i = 0; i < size - 1; i++) {
		minIndex = i;

		for (j = i + 1; j < size; j++) {
			if (list[j] > list[minIndex]) {
				minIndex = j;
			}
		}

		if (minIndex != i) {
			T temp = list[i];
			list[i] = list[minIndex];
			list[minIndex] = temp;
		}
	}
}




/*
Pre: Takes in an array of any type and an int.

Post: Performs shell sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using shell sort in ascending/alphabetical order.
*/


template <typename T>
void shellSort(T list[], int size) {
	int i, j, gap;

	gap = size / 2;

	while (gap > 0) {
		for (i = 0; i < size - gap; i++) {
			if (list[i] > list[i + gap]) {
				T temp = list[i];
				list[i] = list[i + gap];
				list[i + gap] = temp;
			}
		}

		gap = gap / 2;
	}

	bubbleSort(list, size);

}



/*
Pre: Takes in an array of any type and an int.

Post: Performs quick sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using quick sort in ascending/alphabetical order.
*/

template <typename T>
void quickSort(T list[], int lowerBound, int upperBound) {

	int i, j;

	T pivot;

	T temp;

	i = lowerBound;
	j = upperBound;

	pivot = list[(lowerBound + upperBound) / 2];


	while (i <= j) {

		while (list[i] < pivot) {
			i += 1;
		}

		while (list[j] > pivot) {
			j -= 1;
		}

		if (i <= j) {
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i += 1;
			j -= 1;
		}
	}

	if (lowerBound < j) {
		quickSort(list, lowerBound, j);
	}

	if (i < upperBound) {
		quickSort(list, i, upperBound);
	}
}



/*
Pre: Takes in an array of any type and an int.

Post: Performs quick sort descending on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using quick sort in descending order.
*/



template <typename T>
void quickSortDescending(T list[], int lowerBound, int upperBound) {

	long int i, j;

	T pivot;

	T temp;

	i = lowerBound;
	j = upperBound;

	pivot = list[(lowerBound + upperBound) / 2];


	while (i <= j) {

		while (list[i] > pivot) {
			i += 1;
		}

		while (list[j] < pivot) {
			j -= 1;
		}

		if (i <= j) {
			temp = list[i];
			list[i] = list[j];
			list[j] = temp;
			i += 1;
			j -= 1;
		}
	}

	if (lowerBound < j) {
		quickSortDescending(list, lowerBound, j);
	}

	if (i < upperBound) {
		quickSortDescending(list, i, upperBound);
	}
}



/*
Pre: Takes in an array of any type and an int.

Post: Performs a merge operation on the array.

Purpose: This functions purpose is to take an array of any type
and a lower bound, upper bound, and middle elemnt and merge It
assists with the merge sort function.
*/



template <typename T>
void merge(T list[], int lowerBound, int midElement, int upperBound) {

	int i, j, k, size1, size2;

	size1 = midElement - lowerBound + 1;
	size2 = upperBound - midElement;

	T* tmp1 = new T[size1];
	T* tmp2 = new T[size2];

	for (i = 0; i < size1; i++) {
		tmp1[i] = list[lowerBound + i];
	}

	for (j = 0; j < size2; j++) {
		tmp2[j] = list[midElement + j + 1];
	}

	i = 0;
	j = i;

	for (k = lowerBound; k <= upperBound && i < size1 && j < size2; k++) {
		if (tmp1[i] <= tmp2[j]) {
			list[k] = tmp1[i];
			i += 1;
		}
		else {
			list[k] = tmp2[j];
			j += 1;
		}
	}

	while (i < size1) {
		list[k] = tmp1[i];
		i += 1;
		k += 1;
	}

	while (j < size2) {
		list[k] = tmp2[j];
		j += 1;
		k += 1;
	}

	delete[] tmp1;
	delete[] tmp2;
}


/*
Pre: Takes in an array of any type and an int.

Post: Performs merge sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using merge sort in ascending/alphabetical order.
*/

template <typename T>
void mergeSort(T list[], int lowerBound, int upperBound) {

	int mid;

	if (lowerBound < upperBound) {
		mid = (lowerBound + upperBound) / 2;
		mergeSort(list, lowerBound, mid);
		mergeSort(list, mid + 1, upperBound);
		merge(list, lowerBound, mid, upperBound);
	}

}



/*
Pre: Takes in an array of any type and an int.

Post: Performs merge sort descending on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using merge sort in descending order.
*/



template <typename T>
void mergeDescending(T list[], long int lowerBound, long int midElement, long int upperBound) {

	long int i, j, k, size1, size2;

	size1 = midElement - lowerBound + 1;
	size2 = upperBound - midElement;

	T* tmp1 = new T[size1];
	T* tmp2 = new T[size2];

	for (i = 0; i < size1; i++) {
		tmp1[i] = list[lowerBound + i];
	}

	for (j = 0; j < size2; j++) {
		tmp2[j] = list[midElement + j + 1];
	}

	i = 0;
	j = i;

	for (k = lowerBound; k <= upperBound && i < size1 && j < size2; k++) {
		if (tmp1[i] >= tmp2[j]) {
			list[k] = tmp1[i];
			i += 1;
		}
		else {
			list[k] = tmp2[j];
			j += 1;
		}
	}

	while (i < size1) {
		list[k] = tmp1[i];
		i += 1;
		k += 1;
	}

	while (j < size2) {
		list[k] = tmp2[j];
		j += 1;
		k += 1;
	}

	delete[] tmp1;
	delete[] tmp2;
}


/*
Pre: Takes in an array of any type and an int.

Post: Performs merge sort descending on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using merge sort in descending order.
*/

template <typename T>
void mergeSortDescending(T list[], long int lowerBound, long int upperBound) {

	long int mid;

	if (lowerBound < upperBound) {
		mid = (lowerBound + upperBound) / 2;
		mergeSortDescending(list, lowerBound, mid);
		mergeSortDescending(list, mid + 1, upperBound);
		mergeDescending(list, lowerBound, mid, upperBound);
	}

}



/*
Pre: Takes in an array of any type and an int.

Post: Performs cycle sort on the array and sorts them.

Purpose: This functions purpose is to take an array of any type and
sort it using cycle sort in ascending/alphabetical order.
*/

template <typename T>
void cycleSort(T list[], int size) {
	int write = 0;
	int i, j, cycleStart, item, pos;

	for (int cycleStart = 0; cycleStart <= size - 2; cycleStart++) {

		item = list[cycleStart];

		pos = cycleStart;

		for (int i = cycleStart + 1; i < size; i++) {
			if (list[i] < item) {
				pos++;
			}
		}
		if (pos == cycleStart) {
			continue;
		}
		while (item == list[pos]) {
			pos += 1;
		}
		if (pos != cycleStart) {
			T temp = item;
			item = list[pos];
			list[pos] = temp;
			write++;
		}
		while (pos != cycleStart) {
			pos = cycleStart;
			for (int j = cycleStart + 1; j < size; j++) {
				if (list[j] < item) {
					pos += 1;
				}
			}
			while (item == list[pos]) {
				pos += 1;
			}
			if (item != list[pos]) {
				T temp = item;
				item = list[pos];
				list[pos] = temp;
				write++;
			}
		}
	}
}



/*
Pre: None.

Post: Populates one million random numbers for test.

Purpose: This function populates 1,000,000 random numbers for test.
*/

void TestingAlgorithms::populateRanNum() {
	
	srand ((long int)time(NULL));

	long int randomNumber;
	const long int UPPER_BOUND = 10000;
	const long int ONE_MILLION = 999999;

	ofstream fout;

	fout.open("oneMillionNumbers.txt");

	for (int i = 0; i <= ONE_MILLION; i++) {
		randomNumber = rand() % UPPER_BOUND;
		fout << randomNumber << endl;
	}

	fout.close();

}


/*
Pre: none.

Post: Resets the random arrays list for all numbers.

Purpose: The purpose of this function is to reset the random arays list
for all numbers.
*/

void TestingAlgorithms::resetRandom() {

	ifstream fin;
	ifstream fin2;
	ifstream fin3;

	ofstream fout;
	ofstream fout2;
	ofstream fout3;

	long int i, j, k, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;


	cout << "Reseting the Random Arrays. Please wait.\n";

	// Populate 100 Random Numbers

	fin.open("oneMillionNumbers.txt");
	fout.open("100_Random.txt");

	for (i = 0; i <= NUM; i++) {
		fin >> tmp;
		fout << tmp << endl;
	}

	fin.close();
	fout.close();

	cout << "Reseting 100,000 Random Array.\n";

	//Populate 100,000 Random Numbers

	fin2.open("oneMIllionNumbers.txt");
	fout2.open("100,000_Random.txt");

	for (j = 0; j <= NUM2; j++) {
		fin2 >> tmp;
		fout2 << tmp << endl;
	}

	fin2.close();
	fout2.close();

	cout << "100,000 Random Array Reset.\n";

	cout << "Reseting 1,000,000 Random Array.\n";

	//Populate 1,000,000 Random Numbers

	fin3.open("oneMillionNumbers.txt");
	fout3.open("1,000,000_Random.txt");

	for (k = 0; k <= NUM3; k++) {
		fin3 >> tmp;
		fout3 << tmp << endl;
	}

	fin3.close();
	fout3.close();

	cout << "1,000,000 Random Array Reset.\n";

	cout << "Random Arrays Have Been Reset.\n";

}



/*
Pre: none.

Post: Resets the ascending arrays list for all numbers.

Purpose: The purpose of this function is to reset the ascending arays list
for all numbers.
*/


void TestingAlgorithms::resetAscending() {


	ifstream fin;
	ifstream fin2;
	ifstream fin3;

	fstream fout;
	fstream fout2;
	fstream fout3;

	long int i, j, k, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Reseting the Ascending Arrays. Please wait.\n";

	// Populate 100 Ascending Numbers

	fin.open("oneMillionNumbers.txt");
	fout.open("100_Ascending.txt");

	for (i = 0; i <= NUM; i++) {
		fin >> tmp;
		//fout << tmp << endl;
		hundredArray[i] = tmp;
	}

	quickSort(hundredArray, LOWER_BOUND, NUM);

	fout.clear();
	fout.seekg(0);

	for (int j = 0; j <= NUM; j++) {
		fout << hundredArray[j] << endl;
	}

	fin.close();
	fout.close();

	delete[] hundredArray;

	// Populate 100,000 Ascending Numbers


	fin2.open("oneMillionNumbers.txt");
	fout2.open("100,000_Ascending.txt");

	for (i = 0; i <= NUM2; i++) {
		fin2 >> tmp;
		//fout << tmp << endl;
		hundredThousandArray[i] = tmp;
	}

	cout << "Sorting 100,000 Array.\n";

	quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

	fout2.clear();
	fout2.seekg(0);

	for (int j = 0; j <= NUM2; j++) {
		fout2 << hundredThousandArray[j] << endl;
	}

	fin2.close();
	fout2.close();

	delete[] hundredThousandArray;

	cout << "100,000 Array Sorted.\n";

	// Populate 1,000,000 Ascending Numbers


	fin3.open("oneMillionNumbers.txt");
	fout3.open("1,000,000_Ascending.txt");

	for (i = 0; i <= NUM3; i++) {
		fin3 >> tmp;
		//fout << tmp << endl;
		oneMillionArray[i] = tmp;
	}

	cout << "Sorting 1,000,000 Array.\n";

	quickSort(oneMillionArray, LOWER_BOUND, NUM3);

	fout3.clear();
	fout3.seekg(0);

	for (k = 0; k <= NUM3; k++) {
		fout3 << oneMillionArray[k] << endl;
	}

	fin3.close();
	fout3.close();

	delete[] oneMillionArray;

	cout << "1,000,000 Array Sorted.\n";

}



/*
Pre: none.

Post: Resets the descending arrays list for all numbers.

Purpose: The purpose of this function is to reset the descending arays list
for all numbers.
*/


void TestingAlgorithms::resetDescending() {

	ifstream fin;
	ifstream fin2;
	ifstream fin3;

	fstream fout;
	fstream fout2;
	fstream fout3;

	long int i, j, k, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Reseting the Descending Arrays. Please wait.\n";

	// Populate 100 Descending Numbers

	fin.open("oneMillionNumbers.txt");
	fout.open("100_Descending.txt");

	for (i = 0; i <= NUM; i++) {
		fin >> tmp;
		hundredArray[i] = tmp;
	}


	quickSortDescending(hundredArray, LOWER_BOUND, NUM);


	fout.clear();
	fout.seekg(0);

	for (int j = 0; j <= NUM; j++) {
		fout << hundredArray[j] << endl;
	}

	fin.close();
	fout.close();

	delete[] hundredArray;


	// Populate 100,000 Descending Numbers


	fin2.open("oneMillionNumbers.txt");
	fout2.open("100,000_Descending.txt");

	for (i = 0; i <= NUM2; i++) {
		fin2 >> tmp;
		hundredThousandArray[i] = tmp;
	}

	cout << "Sorting 100,000 Descending Array.\n";


	quickSortDescending(hundredThousandArray, LOWER_BOUND, NUM2);


	fout2.clear();
	fout2.seekg(0);

	for (int j = 0; j <= NUM2; j++) {
		fout2 << hundredThousandArray[j] << endl;
	}

	fin2.close();
	fout2.close();

	delete[] hundredThousandArray;

	cout << "100,000 Descending Array Sorted.\n";



	// Populate 1,000,000 escending Numbers


	fin3.open("oneMillionNumbers.txt");
	fout3.open("1,000,000_Descending.txt");

	for (i = 0; i <= NUM3; i++) {
		fin3 >> tmp;
		oneMillionArray[i] = tmp;
	}

	cout << "Sorting 1,000,000 Descending Array.\n";


	quickSortDescending(oneMillionArray, LOWER_BOUND, NUM3);


	fout3.clear();
	fout3.seekg(0);

	for (k = 0; k <= NUM3; k++) {
		fout3 << oneMillionArray[k] << endl;
	}

	fin3.close();
	fout3.close();

	delete[] oneMillionArray;

	cout << "1,000,000 Descending Array Sorted.\n";

}


/*
Pre: none.

Post: Provide menu for test.

Purpose: The purpose of this function is to provide a menu
to call all functions to perform the test.
*/

void TestingAlgorithms::testMenu() {

	int userInput;

	cout << "Enter a Number Correspeonding With a Sorting Test.\n";
	cout << "[1] Bubble Sort.\n";
	cout << "[2] Insertion Sort.\n";
	cout << "[3] Selction Sort.\n";
	cout << "[4] Shell Sort.\n";
	cout << "[5] Quick Sort.\n";
	cout << "[6] Merge Sort.\n";
	cout << "[7] Reset Lists.\n";
	cin >> userInput;

	switch (userInput) {
	case 1:
		testBubble();
		break;
	case 2:
		testInsert();
		break;
	case 3:
		testSelection();
		break;
	case 4:
		testShell();
		break;
	case 5:
		testQuick();
		break;
	case 6:
		testMerge();
		break;
	case 7:
		resetRandom();
		resetAscending();
		resetDescending();
		break;
	}


}



/*
Pre: none.

Post: Tests all arrays for Bubble Sort.

Purpose: The purpose of this function is to test all arrays for 
Bubble Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/




void TestingAlgorithms::testBubble() {



	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With a Bubble Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:

		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		bubbleSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Bubble Sort is: \n";
		cout << timer.getTime() << endl;

		break;


	}


}


/*
Pre: none.

Post: Tests all arrays for Insertion Sort.

Purpose: The purpose of this function is to test all arrays for Insertion Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/



void TestingAlgorithms::testInsert() {



	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With an Insertion Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:

		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		insertionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Insertion Sort is: \n";
		cout << timer.getTime() << endl;

		break;


	}


}




/*
Pre: none.

Post: Tests all arrays for Selection Sort.

Purpose: The purpose of this function is to test all arrays for Selection Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/




void TestingAlgorithms::testSelection() {



	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With an Selection Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:

		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		selectionSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Selection Sort is: \n";
		cout << timer.getTime() << endl;

		break;


	}


}



/*
Pre: none.

Post: Tests all arrays for Shell Sort.

Purpose: The purpose of this function is to test all arrays for Shell Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/


void TestingAlgorithms::testShell() {



	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With a Shell Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:

		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredArray, ONE_HUNDRED);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		shellSort(hundredThousandArray, ONE_HUNDRED_THOUSAND);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		shellSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		shellSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		shellSort(oneMillionArray, ONE_MILLION);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Shell Sort is: \n";
		cout << timer.getTime() << endl;

		break;


	}


}




/*
Pre: none.

Post: Tests all arrays for Quick Sort.

Purpose: The purpose of this function is to test all arrays for Quick Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/



void TestingAlgorithms::testQuick() {

	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With a Quick Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:
		
		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		quickSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		quickSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}
		
		timer.startClock();

		quickSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		quickSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		quickSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Quick Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	}


}



/*
Pre: none.

Post: Tests all arrays for Merge Sort.

Purpose: The purpose of this function is to test all arrays for Merge Sort.

Cite: I received extra code in the form of a timer for this
project from a student at champlain college. The timer
is in the beginning of the code for this array and used throughout.
*/

void TestingAlgorithms::testMerge() {

	const int MAX = 100, RANGE = 1001;

	TimerSystem timer;
	int numbers[MAX];

	cout.setf(ios::fixed | ios::showpoint);
	cout.precision(16);

	srand(unsigned(time(NULL)));





	int userInput;

	fstream fin;

	long int i, j, tmp;
	const long int NUM = 99;
	const long int NUM2 = 99999;
	const long int NUM3 = 999999;

	const long int ONE_HUNDRED = 100;
	const long int ONE_HUNDRED_THOUSAND = 100000;
	const long int ONE_MILLION = 1000000;

	const int LOWER_BOUND = 0;

	unsigned int* hundredArray = new unsigned int[ONE_HUNDRED];
	unsigned int* hundredThousandArray = new unsigned int[ONE_HUNDRED_THOUSAND];
	unsigned int* oneMillionArray = new unsigned int[ONE_MILLION];

	cout << "Enter a Number Corresponding With a Merge Sort Test.\n";
	cout << "[1] - 100 Random Array.\n";
	cout << "[2] - 100 Ascending Array.\n";
	cout << "[3] - 100 Descending Array.\n";
	cout << "[4] - 100,000 Random Array.\n";
	cout << "[5] - 100,000 Ascending Array.\n";
	cout << "[6] - 100,000 Descending Array.\n";
	cout << "[7] - 1,000,000 Random Array.\n";
	cout << "[8] - 1,000,000 Ascending Array.\n";
	cout << "[9] - 1,000,000 Descending Array.\n";
	cin >> userInput;



	switch (userInput) {
	case 1:

		fin.open("100_Random.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Random Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 2:

		fin.open("100_Ascending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Ascending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 3:

		fin.open("100_Descending.txt");

		for (i = 0; i <= NUM; i++) {
			fin >> tmp;
			hundredArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredArray, LOWER_BOUND, NUM);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM; j++) {
			fin << hundredArray[j] << endl;
		}

		fin.close();

		delete[] hundredArray;

		cout << "The Amount of Time Needed to Sort 100 Descending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 4:

		fin.open("100,000_Random.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Random Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 5:

		fin.open("100,000_Ascending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Ascending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 6:

		fin.open("100,000_Descending.txt");

		for (i = 0; i <= NUM2; i++) {
			fin >> tmp;
			hundredThousandArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(hundredThousandArray, LOWER_BOUND, NUM2);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM2; j++) {
			fin << hundredThousandArray[j] << endl;
		}

		fin.close();

		delete[] hundredThousandArray;

		cout << "The Amount of Time Needed to Sort 100,000 Descending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 7:

		fin.open("1,000,000_Random.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Random Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	case 8:

		fin.open("1,000,000_Ascending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Tme Needed to Sort 1,000,000 Ascending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;


		break;
	case 9:


		fin.open("1,000,000_Descending.txt");

		for (i = 0; i <= NUM3; i++) {
			fin >> tmp;
			oneMillionArray[i] = tmp;
		}

		timer.startClock();

		mergeSort(oneMillionArray, LOWER_BOUND, NUM3);

		fin.clear();
		fin.seekg(0);

		for (j = 0; j <= NUM3; j++) {
			fin << oneMillionArray[j] << endl;
		}

		fin.close();

		delete[] oneMillionArray;

		cout << "The Amount of Time Needed to Sort 1,000,000 Descending Numbers Using Merge Sort is: \n";
		cout << timer.getTime() << endl;

		break;
	}


}