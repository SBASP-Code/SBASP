#ifndef avgminmax02
#define avgminmax02

int mathround(double n)
{
	double a = n - floor(n);
	double b = ceil(n) - n;
	int c;
	if (a < b) { c = floor(n); }
	else { c = ceil(n); }
	return c;
}

int mathmax(int* arr, int size)
{
	int max = arr[0];
	for (int i = 0;i < size;++i)
		if (max < arr[i])max = arr[i];
	return max;
}
int* mathmax02(int* arr, int size)
{
	int mathmax = arr[0];
	int index = 0;
	for (int i = 0;i < size;++i)
		if (mathmax < arr[i]) {
			mathmax = arr[i];
			index = i;
		}
	int result[2] = { mathmax,index };
	return result;
}

double mathmin(int* arr, int size)
{
	double min = arr[0];
	for (int i = 0;i < size;++i)
		if (min > arr[i])min = arr[i];
	return min;
}
int* mathmin02(int* arr, int size)
{
	int mathmin = arr[0];
	int index = 0;
	for (int i = 0;i < size;++i)
		if (mathmin > arr[i]) {
			mathmin = arr[i];
			index = i;
		}
	int result[2] = { mathmin,index };
	return result;
}



int mathsum(int* arr, int size)
{
	int avg = 0;
	for (int i = 0;i < size;++i)
		avg += arr[i];
	return avg;
}
long dpow(int a, int b) {
	long result = pow(double(a), double(b));
	return result;
}

int* InsertionSort(double* a, int* seq, int len)
{
	for (int j = 1; j < len; j++)
	{
		double key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key)
		{
			a[i + 1] = a[i];
			int temp = seq[i + 1];
			seq[i + 1] = seq[i];
			seq[i] = temp;
			i--;
		}
		a[i + 1] = key;
	}
	return seq;
}

#endif#pragma once
