#include<iostream>
using namespace std;

void* add(void* array, int size, int add_value){
	int* intarray = static_cast<int*>(array);
	int i;
	for(i=0; i<size; i++)
	{
		intarray[i] += add_value;
	}
	return static_cast<void*>(intarray);
}

int main()
{
	int size;
	int add_value;
	int i;
	cout<< "Enter the number of elements in an array: ";
	cin>> size;
	int* array = new int[size];
	cout<< "Enter " << size << "elements: ";
	for(i=0; i<size; i++)
	{
		cin>> array[i];
	}
	cout<< "Enter the number to add in elements in an array: ";
	cin>> add_value;
	cout<< "An array: ";
	for(i=0; i<size; i++)
	{
		cout<< array[i] << " ";
	}
	cout<< endl;
	void* operated_array = add(static_cast<void*>(array),size,add_value);
	int* final_array = static_cast<int*>(operated_array);
	cout<< "Modified array: ";
	for(i=0; i<size; i++)
	{
		cout<< final_array[i] << " ";
	}
	cout<< endl;
}
