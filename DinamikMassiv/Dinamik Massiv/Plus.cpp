#include<iostream>
#include "Plus.h"
#include <ctime>

using namespace std;

void Plus(int*&arr, int &size, int const value)
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
}