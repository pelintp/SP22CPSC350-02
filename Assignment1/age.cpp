#include<iostream>
using namespace std;

int main()
{
	int one_age,two_age,three_age;
	cout<<"Enter first person's age:";
	cin>>one_age;
	cout<<"Enter second person's age:";
	cin>>two_age;
	cout<<"Enter third person's age:";
	cin>>three_age;

	if (one_age<two_age && one_age<three_age)
		cout<<" first person is the youngest ";
	else if(two_age<one_age && two_age<three_age)
		cout<<" second person is the youngest ";
	else
		cout<<" third person is the youngest ";

    if (one_age>two_age && one_age>three_age)
		cout<<" & first person is the oldest ";
	else if(two_age>one_age && two_age>three_age)
		cout<<" & second person is the oldest ";
	else
		cout<<" & third person is the oldest ";
	return 0;
}