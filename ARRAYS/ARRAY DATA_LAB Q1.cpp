#include <iostream>
using namespace std;
int main()
{
	int max;
	int temp;
	
	int *ptr;
	
	int arr[5]={5,3,2,1,4};
	
	for(int i=0;i<5;i++)
	{
		for(int j=i+1;j<5;j++)
		
		{
			if (*(arr+j) < *(arr+i))
			{
				temp=*(arr+i);
				*(arr+i)=*(arr+j);
				*(arr+j)=temp;
			}
		
		}
	}
	
	for(int i=0; i<5;i++)
	{
		cout<<arr[i];
	}
	
	cout<<endl;
	
	int *p1,*p2;
	
	p1=&arr[0];
	cout<<"Minimum Number is "<<*p1<<endl;
	
	p2=&arr[4];
	cout<<"Maximum number is "<<*p2<<endl;
}
