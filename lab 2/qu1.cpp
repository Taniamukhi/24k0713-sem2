#include<iostream>
using namespace std;

int main()
{
	int array[5];
	int sum = 0;
	int i;
	int *ptr;
	cout<< "Enter the elements of array: ";
	for(i=0; i<5; i++)
	{
		cin>> array[i];
	}
	ptr=array;
	for(i=0; i<5; i++)
	{
		sum = sum + *(ptr+i);
	}
	cout<< "Sum of the array is: "<< sum;
}
