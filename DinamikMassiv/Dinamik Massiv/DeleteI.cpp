#include<iostream>
#include "DeleteI.h"
#include <ctime>
using namespace std;
void DeleteI(int*&arr, int &size, int index)
{
	int *newarr = new int[size - 1];
	for (int i = 0; i < size; i++)
	{
		if (i < index) {
			newarr[i] = arr[i];
		}
		else if (i == index) {

		}
		else if (i > index) {
			newarr[i - 1] = arr[i];
		}
	}
	delete[] arr;
	arr = newarr;
	size--;
}
