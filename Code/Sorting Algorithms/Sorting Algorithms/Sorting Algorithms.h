#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
#include <time.h>
#include <chrono>
#include <string>

using namespace std;
using namespace std::chrono;

void HoanVi(int&, int&);
void printToFile(string);
void printToFile(int);
void printExecutionTime(string, long long int);

//-------------------------------------------------
void printArray(int[], int);
void GenerateRandomData(int[], int);
void GenerateSortedData(int[], int);
void GenerateReverseData(int[], int);
void GenerateNearlySortedData(int[], int);
void GenerateData(int[], int, int);

//SORTING ALGORITHMS

//Selection Sort
int findMinIndex(int[], int, int);
void selectionSort(int[], int);
//Bubble Sort
void bubbleSort(int[], int);
//Insertion Sort
void insertionSort(int[], int);
//Merge Sort
int* newArray(int[], int, int);
void merge(int*&, int*, int, int*, int);
void mergeSort(int[], int, int);
//Quick Sort
int partition(int[], int, int);
void quickSort(int[], int, int);
//Heap Sort
void heapify(int[], int, int);
void heapSort(int[], int);
//Binary Insertion Sort
int binarySearch(int[], int, int, int);
void binaryInsertionSort(int[], int);

//RUN
void runSelectionSort();
void runBubbleSort();
void runInsertionSort();
void runMergeSort();
void runQuickSort();

void runHeapSort();
void runBinaryInsertionSort();
void runAllSortTypes();