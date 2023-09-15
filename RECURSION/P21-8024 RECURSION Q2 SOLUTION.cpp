#include<iostream>
using namespace std;

bool powerfunction(int n)
{
	if(n==0)
	{
		return false;
		
	}
	if(n==1)
	{
		return true;
	}
	
	if(n%4!=0)
	{
		return false;
	}
	
	return powerfunction(n/4);
}
int main()
{
	cout<<powerfunction(64);
	
}
