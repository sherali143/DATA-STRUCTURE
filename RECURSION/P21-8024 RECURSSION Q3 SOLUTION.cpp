#include<iostream>
using namespace std;

int multiplication(int a, int b){
	if(b==0)
{
	return 0;
}
	return a+multiplication(a,b-1);
}

int main()
{
	int a=3,b=4;
	cout<<multiplication(a,b);
	return 0;
	
}
