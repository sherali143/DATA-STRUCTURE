#include <iostream>
using namespace std;
int main()

{
	int t;
	cout<<"Enter the target ";
	cin>>t;
	
	int arr[4]={1,2,3,4};
	
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		
		{
			if(arr[i]+arr[j]==t)
			
			{
				cout<<i<<endl;
				cout<<j<<endl;
			}
		}
	}
}
