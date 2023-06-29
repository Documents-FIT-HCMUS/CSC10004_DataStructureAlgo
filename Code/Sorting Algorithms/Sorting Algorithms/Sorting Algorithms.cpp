#include "Sorting Algorithms.h"


void HoanVi(int& a, int& b)
{
	int x = a;
	a = b;
	b = x;
}
void printToFile(string text)
{
	fstream fo;
	fo.open("data_out.txt", ios::app);
	if (fo.fail())
	{
		cout << "FAILED TO OPEN FILE.\n";
		return;
	}
	fo << text;
	fo.close();
}
void printToFile(int n)
{
	fstream fo;
	fo.open("data_out.txt", ios::app);
	if (fo.fail())
	{
		cout << "FAILED TO OPEN FILE.\n";
		return;
	}
	fo << n;
	fo.close();
}
void printExecutionTime(string text, long long int duration)
{
	fstream fo;
	fo.open("data_out.txt", ios::app);
	if (fo.fail())
	{
		cout << "FAILED TO OPEN FILE.\n";
		return;
	}
	fo << text << ":  " << duration << " ms." << endl;
	fo.close();
}

//-------------------------------------------------
void printArray(int a[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
void GenerateRandomData(int a[], int n)
{
	srand((unsigned int)time(NULL));

	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}
}
void GenerateSortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
}
void GenerateReverseData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = n - 1 - i;
	}
}
void GenerateNearlySortedData(int a[], int n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = i;
	}
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int r1 = rand() % n;
		int r2 = rand() % n;
		HoanVi(a[r1], a[r2]);
	}
}
void GenerateData(int a[], int n, int dataType)
{
	switch (dataType)
	{
	case 0:	//random
		GenerateRandomData(a, n);
		break;
	case 1:	//sorted
		GenerateSortedData(a, n);
		break;
	case 2:	//reversed
		GenerateReverseData(a, n);
		break;
	case 3:	//nearly sorted
		GenerateNearlySortedData(a, n);
		break;
	default:
		printf("Error: unknown data type!\n");
	}
}

//SORTING ALGORITHMS

//Selection Sort
int findMinIndex(int a[], int n, int i)
{
	int result = i;
	for (int j = i + 1; j < n; ++j)
		if (a[j] < a[result]) result = j;
	return result;
}
void selectionSort(int a[], int n)
{
	int min;
	for (int i = 0; i < n - 1; ++i)
	{
		min = findMinIndex(a, n, i);
		HoanVi(a[i],a[min]);
	}
}

//Bubble Sort
void bubbleSort(int a[], int n)
{
	for (int i = 0; i < n - 1; ++i)
		for (int j = 0; j < n - i - 1; ++j)
			if (a[j] > a[j + 1])
				HoanVi(a[j], a[j + 1]);
}

//Insertion Sort
void insertionSort(int a[], int n)
{
	int i, k, j;
	for ( i = 1; i < n; ++i)
	{
		 k = a[i];
		 j = i - 1;
		while (j >= 0 && a[j] > k)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

//Merge Sort
int* newArray(int a[], int left, int right) 
{
	int n = right - left + 1;
	int j = 0;
	int* result = new int[n];
	for (int i = left; i <= right; ++i)
	{
		result[j] = a[i];
		j++;
	}
	return result;
}
void merge(int*& a, int* a1, int n1, int* a2, int n2) 
{
	int i1 = 0, i2 = 0, j = 0;
	//Merge two arrays from position left, while keeping their orders
	while (i1 < n1 && i2 < n2)
	{
		if (a1[i1] <= a2[i2])
		{
			a[j] = a1[i1];
			j++;
			i1++;
		}
		else
		{
			a[j] = a2[i2];
			j++;
			i2++;
		}
	}

	//Copy the remaining elements into the source array, if there is any
	while (i1 < n1)
	{
		a[j] = a1[i1];
		j++;
		i1++;

	}
	while (i2 < n2)
	{
		a[j] = a2[i2];
		j++;
		i2++;
	}
}
void mergeSort(int a[], int left, int right) 
{
	if (right <= left) return;
	int mid = (left + right) / 2;
	//Make new subarrays to store data
	int* a1 = newArray(a, left, mid);
	int* a2 = newArray(a, mid + 1, right);
	mergeSort(a1, 0, mid - left);
	mergeSort(a2, 0, right - mid - 1);

	//Merge array1 of n1-size with array2 of n2-size into a from "left" position
	merge(a, a1, mid - left + 1, a2, right - mid);
	delete[]a1;
	delete[]a2;
}

//Quick Sort
int partition(int a[], int left, int right)
{
	int temp = left + (rand() % (right - left + 1));
	HoanVi(a[temp], a[right]);
	int pivot = right;
	int low = left;
	int high = right - 1;
	while (true) 
	{
		while (low <= high && a[low] > a[pivot]) low++;
		while (high >= low && a[high] < a[pivot]) high--;
		if (low >= high) break;
		HoanVi(a[low], a[high]);
		low++;
		high--;
	}
	HoanVi(a[low], a[right]);
	return low;
}
void quickSort(int a[], int left, int right)
{
	if (right <= left) return;
	int p = partition(a, left, right);
	quickSort(a, left, p - 1);
	quickSort(a, p + 1, right);
}

//Heap Sort
void heapify(int a[], int n, int i)
{
	int k = i;
	int left = 2 * i + 1; 
	int right = 2 * i + 2; 
	if (left < n && a[left] < a[k])
		k = left;
	if (right < n && a[right] < a[k])
		k = right;
	if (k != i) 
	{
		HoanVi(a[i], a[k]);
		heapify(a, n, k);
	}
}
void heapSort(int a[], int n)
{
	for (int i = n / 2 - 1; i >= 0; --i)
		heapify(a, n, i);
	for (int i = n - 1; i > 0; --i) 
	{
		HoanVi(a[0], a[i]);
		heapify(a, i, 0);
	}
}

//Binary Insertion Sort
int binarySearch(int a[], int x, int left, int right)
{
	int mid;
	while (left <= right) 
	{
		mid = (left + right) / 2;
		if (x == a[mid]) return mid;
		if (x < a[mid])
			right = mid - 1;
		else 
			left = mid + 1;
	}
	return left;
}
void binaryInsertionSort(int a[], int n)
{
	for (int i = 1; i < n; ++i)
	{
		int j = i - 1;
		int k = a[i];
		int insertLocation  = binarySearch(a, k, 0, j);
		while (j >= insertLocation)
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = k;
	}
}

//Sort Run
void runSelectionSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nSELECTION SORT\n";
	printToFile("\nSELECTION SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				selectionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				selectionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				selectionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				selectionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runBubbleSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nBUBBLE SORT\n";
	printToFile("\nBUBBLE SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				bubbleSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				bubbleSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				bubbleSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				bubbleSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runInsertionSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nINSERTION SORT\n";
	printToFile("\nINSERTION SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				insertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				insertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				insertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				insertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runMergeSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nMERGE SORT\n";
	printToFile("\nMERGE SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				mergeSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				mergeSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				mergeSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				mergeSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runQuickSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nQUICK SORT\n";
	printToFile("\nQUICK SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				srand((unsigned int)time(0));
				quickSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				srand((unsigned int)time(0));
				quickSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				srand((unsigned int)time(0));
				quickSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				srand((unsigned int)time(0));
				quickSort(a, 0, size[i] - 1);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}

void runHeapSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nHEAP SORT\n";
	printToFile("\nHEAP SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				heapSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				heapSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				heapSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				heapSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runBinaryInsertionSort()
{
	int size[5] = { 3000, 10000, 30000, 100000, 300000 };
	cout << "\nBINARY-INSERTION SORT\n";
	printToFile("\nBINARY-INSERTION SORT\n");
	for (int i = 0; i < 5; ++i)
	{
		if (i > 0)
		{
			cout << endl;
			printToFile("\n");
		}
		cout << "Size: " << size[i] << endl;
		printToFile("Size: ");
		printToFile(size[i]);
		printToFile("\n");
		for (int j = 0; j < 4; ++j)
		{
			switch (j)
			{
			case 0:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				binaryInsertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Random:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Random\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 1:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				binaryInsertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Sorted:\t\t" << duration.count() << " ms." << endl;
				printExecutionTime("Sorted\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 2:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				binaryInsertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Reverse:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Reverse\t\t\t", duration.count());
				delete[]a;
				break;
			}
			case 3:
			{
				int* a = new int[size[i]];
				GenerateData(a, size[i], j);
				auto start = high_resolution_clock::now();
				binaryInsertionSort(a, size[i]);
				auto stop = high_resolution_clock::now();
				auto duration = duration_cast<milliseconds>(stop - start);
				cout << "Nearly Sorted:\t" << duration.count() << " ms." << endl;
				printExecutionTime("Nearly Sorted\t", duration.count());
				delete[]a;
				break;
			}
			default:
				break;
			}
		}

	}
}
void runAllSortTypes()
{
	runSelectionSort();
	runBubbleSort();
	runInsertionSort();
	runMergeSort();
	runQuickSort();
	runHeapSort();
	runBinaryInsertionSort();
}
