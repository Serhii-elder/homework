#include<iostream>
#include "Plus.h"
#include "DeleteI.h"
#include <ctime>
using namespace std;
void Print(int *arr, int size)
{
	cout << "========================================" << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Arr [" << i << "] = " << arr[i] << "\t" << arr + i << endl;
	}
	cout << "========================================" << endl;
}
void Create(int *arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 68 - 12;
	}
}
void Plus1(int*&arr, int &size, int const value)
{
	int *newarr = new int[size + 1];
	for (int i = size; i > 0; i--)
	{
		newarr[i] = arr[i - 1];
	}
	newarr[0] = value;
	delete[] arr;
	arr = newarr;
	size++;
}/*void Plus(int*&arr, int &size, int const value)
{
	int *newarr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	newarr[size] = value;
	delete[] arr;
	arr = newarr;
	size++;
}*/
void Index(int*&arr, int &size, int const value, int index)
{
	int *newarr = new int[size + 1];
	for (int i = 0; i < size; i++)
	{
		if (i < index)
		{
			newarr[i] = arr[i];
		}
		else if (i == index)
		{
			newarr[index] = value;
		}
		else if (i > index) {
			newarr[i] = arr[i - 1];
		}
	}
	delete[] arr;
	arr = newarr;
	size++;
}
//void DeleteI(int*&arr, int &size, int index)
//{
//	int *newarr = new int[size - 1];
//	for (int i = 0; i < size; i++)
//	{
//		if (i < index) {
//			newarr[i] = arr[i];
//		}
//		else if (i == index) {
//
//		}
//		else if (i > index) {
//			newarr[i - 1] = arr[i];
//		}
//	}
//	delete[] arr;
//	arr = newarr;
//	size--;
//}
void DeleteF(int*&arr, int &size)
{
	int *newarr = new int[size - 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i + 1];
	}
	delete[] arr;
	arr = newarr;
	size--;
}
void DeleteL(int*&arr, int &size)
{
	int *newarr = new int[size - 1];
	for (int i = 0; i < size; i++)
	{
		newarr[i] = arr[i];
	}
	delete[] arr;
	arr = newarr;
	size--;
}void PlusM(int*&arr, int &size, int *&tmp, int &number)
{
	int *newarr = new int[size + number];
	for (int i = 0; i < size + number; i++)
	{
		if (i < number) {
			newarr[i] = tmp[i];
		}
		else if (i >= number) {
			newarr[i] = arr[i - number];
		}

	}
	delete[] arr;
	arr = newarr;
	size + number;
}
int main()
{
	srand(unsigned(time(NULL)));
	//+++++++++++++++++++++SIZE1+++++++++++++++++++
	int size = 0;
	int index = 0;
	int v = 0;
	int number = 0;
	int tm;
	int *tmp = new int[number];
	int t = 0;
	int value = 0;
	bool exit = true;
	int *arr = new int[size];



	while (exit == true)
	{
		cout << "=============================================================================" << endl;
		cout << "\t1 - Create a new Arr!\n\t2 - Display the array on the screen\n\t";
		cout << "3 - Plus last element\n\t4 - Plas first element\n\t5 - Index element";
		cout << "\n\t6 - Delete index element\n\t7 - Delete first element";
		cout << "\n\t8 - Delete last element\n\t9 - Add some numbers to the podium\n\t0 - EXIT!";
		cin >> v;
		if (v == 1)
		{
			cout << "Create Arr array - 1 " << endl;

			cout << "Enter size ";
			cin >> size;
			arr = new int[size];
			Create(arr, size);

			cout << "You create a new array" << endl;



		}
		else if (v == 2)
		{


			Print(arr, size);


		}
		else if (v == 3)
		{
			cout << "Enter value ";
			cin >> value;

			Plus(arr, size, value);
		}
		else if (v == 4)
		{
			cout << "Enter value ";
			cin >> value;

			Plus1(arr, size, value);
		}
		else if (v == 5)
		{
			cout << "Enter value ";
			cin >> value;
			cout << "Index ";
			cin >> index;
			Index(arr, size, value, index);
		}
		else if (v == 6)
		{
			cout << "Enter index ";
			cin >> index;

			DeleteI(arr, size, index);
		}
		else if (v == 7)
		{
			DeleteF(arr, size);
		}
		else if (v == 8)
		{
			DeleteL(arr, size);
		}
		else if (v == 9)
		{
			cout << "Number of numbers ";
			cin >> number;
			for (int i = 0; i < number; i++) {
				cout << i << " = ";
				cin >> tm;
				tmp[i] = tm;
			}

			PlusM(arr, size, tmp, number);

		}
		else if (v == 0) {
			exit = false;
		}

	}
	system("pause");
	return 0;
}