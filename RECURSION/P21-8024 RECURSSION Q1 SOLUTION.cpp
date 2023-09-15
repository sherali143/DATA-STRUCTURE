#include<iostream>
#include<math.h>
using namespace std;

int main()

{
	int n;
	cout<<"ENTER THE number :";
	cin>>n;
	
	for(int i=1;i<n;i++)
	{
		if(pow(4,i)==n)
		{
			cout<<"True";
			return 0;
			
		}	
	}
	cout<<"False";
}
