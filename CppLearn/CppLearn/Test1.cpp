#include <iostream>
#include <iomanip> // To set precision to floats Link: https://en.cppreference.com/w/cpp/io/manip
#include <math.h>  // Basic math ops
#include <stdlib.h>
#include <string>
using namespace std;

void StringTests();
void FloatTests();

void BubbleSort(int arr[], int size);
void InsertionSort(int arr[], int size);
void SelectionSort(int arr[], int size);
void ShellSort(int arr[], int size);
void QuickSort(int arr[], int size);
void PrintArray(int arr[], int size);

int main()
{
	//StringTests();
	//FloatTests();

#pragma region SortTests

	int arrayToSort[] = { 4,1,23,6,7,8,4,0,3 };
	int arrayToSort1[] = { 1,2,3,7,4,5,6,7,8,9 };

#pragma region BubbleSort

	BubbleSort(arrayToSort, size(arrayToSort));
	PrintArray(arrayToSort, size(arrayToSort));

	BubbleSort(arrayToSort1, size(arrayToSort1));
	PrintArray(arrayToSort1, size(arrayToSort1));

#pragma endregion BubbleSort

#pragma endregion SortTests



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
	cout << fTest << endl;
	cout << setprecision(2) << fixed;
	cout << fTest << endl;
	cout << setprecision(4);
	cout << fTest << endl;
}

#pragma endregion FloatTest

#pragma region Sorts

void BubbleSort(int arr[], int size)
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
				aux = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = aux;
			}
		}
	}
}

void InsertionSort(int arr[], int size)
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

void SelectionSort(int arr[], int size)
{
	int aux;

	for (size_t i = 0; i < size - 1; i++)
	{
		int minPos = i;
		// Get the min number on the rest of the array
		for (size_t j = i + 1; j < size; j++)
			if (arr[j] < arr[minPos])
				minPos = j;

		// Put the min number on the current position
		aux = arr[minPos];
		arr[minPos] = arr[i];
		arr[i] = aux;

	}

}

void ShellSort(int arr[], int size)
{
	int aux, gap;
	bool ordered = true;;

	gap = size / 2;
	// Loop while the gap between the compared numbers is greater than 0
	while (gap > 0)
	{
		ordered = true;
		// Loop through the array checking the numbers with the current gap
		for (size_t i = 0; i < size - gap; i++)
		{
			// If the numbers arent in order swap them
			if (arr[i] > arr[i + gap])
			{
				ordered = false;
				aux = arr[i];
				arr[i] = arr[i + gap];
				arr[i + gap] = aux;
			}
		}
		// If the array hasnt changed in the last loop reduce the gap
		if (ordered)
			gap /= 2;
	}
}

void QuickSort(int arr[], int size)
{

}

void PrintArray(int arr[], int size)
{

	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << ", ";
	}
	cout << endl;
}
#pragma endregion Sorts
