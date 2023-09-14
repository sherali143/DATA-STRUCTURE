#include<iostream>
using namespace std;
int main()
{
	int temp,ans,ans1;
	
	int arr[5]={1,2,4,5,6};
	
	int length=sizeof(arr)/sizeof(arr[0]);
	
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			if(arr[j]<arr[i])
			{
				temp=arr[i];
				arr[i]=arr[j];
				arr[j]=temp;
			}
		}
	}
	
	for(int i=0;i<5;i++)
	{
		cout<<arr[i];
	}
	cout<<endl;

	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		{
			
			if(arr[j]-arr[i]==1)
			{
				ans=length+1;	
			}	
			
			
			else if(arr[j]-arr[i]>1)
			{
				ans1=arr[i];
			}
			
			else
			{
				cout<<"No check Given ";
			}
			
		}
	}
	
	cout<<ans<<endl;
	
	cout<<ans1+1;
}



			
