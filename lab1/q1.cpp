#include<iostream>
using namespace std;

int main()
{
	float array[20];
	int i;
	cout<<"Enter array elements: "<<endl;
	for(i=0; i<=20; i++)
	{
		cin >> array[i];
	}
	float *second_highest = &array[1];
	float *highest =&array[0];
	
	if(*second_highest > *highest)
	{
		swap(highest, second_highest);
	}
	
	for(i=1; i<=20; i++)
	{
		if(*(array+i)> *highest)
		{
			*second_highest = *highest;
			*highest = *(array+i);
		}
		
		else if(*(array+i) > *second_highest && *(array+i)!=*highest)
		{
			*second_highest = *(array+i);
		}
	}
	cout<<"Second highest number="<<*second_highest<<endl;
}
