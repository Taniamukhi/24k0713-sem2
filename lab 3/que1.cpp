#include<iostream>
using namespace std;

class user{
	public:
		int age;
		string name;
};

int main()
{
	user info;
	info.name = "Teo";
	info.age = 24;
	cout<< "Iam "<< info.age << " years old.";
}
