#include <iostream>
#include <iomanip> // To set precision to floats Link: https://en.cppreference.com/w/cpp/io/manip
#include <math.h>  // Basic math ops
#include <stdlib.h>
#include <string>
using namespace std;

void StringTests();
void FloatTests();

template<class T>
void BubbleSort(T arr[], int size);
template<class T>
void InsertionSort(T arr[], int size);
template<class T>
void SelectionSort(T arr[], int size);
template<class T>
void ShellSort(T arr[], int size);
template<class T>
void QuickSort(T arr[], int size);
template<class T>
void RecursiveQuickSort(T arr[], int low, int high);
template<class T>
int GetArrayPivotPos(T arr[], int low, int high);

template<class T>
void PrintArray(T arr[], int size);
template<class T>
void SwapPositions(T& a, T& b);

template<class T>
bool SequentialSearch(T arr[], int size, T find);
template<class T>
bool BinarySearch(T arr[], int size, T find);

struct Author
{
	string name;
	int age;
}
aut = {"Pepe", 38};

struct Song 
{
	Author aut;
	string name;
	float duration;
}
songs[] ={ {aut, "aaaa", 5.0}, { {"Michael", 46}, "bbbb", 3.0 }};


int main()
{
	//StringTests();
	//FloatTests();

	float arrayToSort[] = { 4, 1, 23, 6, 7, 8, 4, 0 };
	int arrayToSort1[] = { 1, 2, 3, 7, 4, 5, 6, 7, 8, 9 };

	QuickSort(arrayToSort, size(arrayToSort));
	PrintArray(arrayToSort, size(arrayToSort));
	if (BinarySearch(arrayToSort, size(arrayToSort), 23.0f))
			cout << "found" << endl;
	system("pause");

	return 0;
}


#pragma region StringTest

void StringTests()
{
	string name = "aaaa";
	cout << "Name: ";
	//std::getline(cin, name);
	string name2 = "bb" + name;
	cout << name2 + " has " << name2.length() << " characters\n";
}

#pragma endregion StringTest

#pragma region FloatTest

void FloatTests()
{
	float fTest = 2.192631923;
	cout << "Float: ";
	//cin >> fTest; // you can read more inputs //cin >> var1 >> var2 >> varN;
	// use fflush(stdin) to empty the buffer in case its overloaded
	cout << fTest << endl;
	cout << setprecision(2) << fixed;
	cout << fTest << endl;
	cout << setprecision(4);
	cout << fTest << endl;
}

#pragma endregion FloatTest

#pragma region Sorts

template<class T>
void BubbleSort(T arr[], int size)
{
	int aux; // Helps with the number swap
	bool ordered = false; // Checks if the loop did any changes in the array

	for (size_t i = 0; i < size && !ordered; i++)
	{
		ordered = true;

		// Every loop iterations orders the last i numbers so we can substract them from future cicles
		for (size_t j = 0 ; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				ordered = false;
				SwapPositions(arr[j+1], arr[j]);

			}
		}
	}
}

template<class T>
void InsertionSort(T arr[], int size)
{
	int aux, pos;
	for (size_t i = 0; i < size; i++)
	{
		pos = i;
		aux = arr[i];

		// Loop while the numbers on the left are greater than the one on i pos
		while (pos > 0 && arr[pos - 1] > aux)
		{
			// change the left number to the current position
			arr[pos] = arr[pos - 1];
			pos--;
		}

		arr[pos] = aux;
	}
}

template<class T>
void SelectionSort(T arr[], int size)
{
	int aux;

	for (int i = 0; i < size - 1; i++)
	{
		int minPos = i;
		// Get the min number on the rest of the array
		for (int j = i + 1; j < size; j++)
			if (arr[j] < arr[minPos])
				minPos = j;

		// Put the min number on the current position
		SwapPositions(arr[minPos], arr[i]);


	}

}

template<class T>
void ShellSort(T arr[], int size)
{
	int aux, gap;
	bool ordered = true;;

	gap = size / 2;
	// Loop while the gap between the compared numbers is greater than 0
	while (gap > 0)
	{
		ordered = true;
		// Loop through the array checking the numbers with the current gap
		for (int i = 0; i < size - gap; i++)
		{
			// If the numbers arent in order swap them
			if (arr[i] > arr[i + gap])
			{
				ordered = false;

				SwapPositions(arr[i+gap], arr[i]);
			}
		}
		// If the array hasnt changed in the last loop reduce the gap
		if (ordered)
			gap /= 2;
	}
}

template<class T>
void QuickSort(T arr[], int size)
{
	RecursiveQuickSort(arr, 0, size - 1);
}

template<class T>
void RecursiveQuickSort(T arr[], int low, int high)
{
	if (low < high)
	{
		int midPos = GetArrayPivotPos(arr, low, high);

		RecursiveQuickSort(arr, low, midPos - 1);
		RecursiveQuickSort(arr, midPos + 1, high);
	}
}

template<class T>
int GetArrayPivotPos(T arr[], int low, int high)
{
	int aux;
	int pivot = arr[high];
	int i = low;

	for (int j = low; j < high; j++)
	{
		if (arr[j] < pivot)
		{
			SwapPositions(arr[j], arr[i]);
			i++;
		}
	}

	SwapPositions(arr[high], arr[i]);


	return i;
}

template<class T>
void PrintArray(T arr[], int size)
{

	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}

template<class T>
void SwapPositions(T& a, T& b)
{
	int t = a;
	a = b;
	b = t;
}

#pragma endregion Sorts


#pragma region Seacrh

template<class T>
bool SequentialSearch(T arr[], int size, T find)
{
	int i = 0;
	for (; i < size && arr[i] != find; i++);
	return i < size;
}

// Requires an ascendening order array
template<class T>
bool BinarySearch(T arr[], int size, T find)
{
	int high = size - 1;
	int low = 0;
	int mid = (high + low) / 2;

	while (high >= low && arr[mid] != find)
	{
		//cout << low << mid << high << endl;
		if (arr[mid] < find)
			low = mid + 1;
		if (arr[mid] > find)
			high = mid - 1;

		mid = (high + low) / 2;
	}

	return high >= low;
}
#pragma endregion Search