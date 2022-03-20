
/*

Author: Andrew Vinci
Class: CSI-281 - Data Structures and Algorithms
Assignment: PA3 - Part 4
Date Assigned: 02/20/2022
Due Date: 02/28/2022 @ 11:10 a.m.
Description:
This file is the header file with all function declaration for my
testing algorithms.
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
#include <windows.h>

using namespace std;

/*Cite: This is ANother Students Timer System that I'm Using for This Project.*/

#ifndef TIMER_SYSTEM_H
#define TIMER_SYSTEM_H

class TimerSystem
{
private:
	LARGE_INTEGER start, finish, freq;  //For frequency and high speed timers

public:
	TimerSystem();

	double getTime();  //gets current time since top of frame
	void   startClock();  //Starts the frame counter
};

#endif

template <typename T>
void bubbleSort(T list[], int size);

template <typename T>
void insertionSort(T list[], int size);

template <typename T>
void selectionSort(T list[], int size);

template <typename T>
void selectionSortDescending(T list[], long int size);

template <typename T>
void shellSort(T list[], int size);

template <typename T>
void cycleSort(T list[], int size);

template <typename T>
void quickSort(T list[], int lowerBound, int upperBound);

template <typename T>
void quickSortDescending(T list[], int lowerBound, int upperBound);

template <typename T>
void mergeSort(T list[], int lowerBound, int upperBound);

template <typename T>
void merge(T list[], int lowerBound, int midElement, int upperBound);

template <typename T>
void mergeSortDescending(T list[], long int lowerBound, long int upperBound);

template <typename T>
void mergeDescending(T list[], long int lowerBound, long int midElement, long int upperBound);

class TestingAlgorithms {
private:

public:

	void populateRanNum();

	void testMenu();

	void resetRandom();
	void resetAscending();
	void resetDescending();

	void testBubble();
	void testInsert();
	void testSelection();
	void testShell();
	void testQuick();
	void testMerge();

};