#include<iostream>
using namespace std;

class heap{
	
	public:	
		int arr[100];
		int size;
		
	heap()
	{
		arr[0]=-1;
		size=0;
	}
		
	void insertion(int val)
	{
		size=size+1;
		int index=size;
		arr[index]=val;
		
		while(index > 1)
		{
			int parent=index/2;	
			if(arr[parent] > arr[index])
			{
				swap(arr[parent],arr[index]);
				index=parent;
			}
			else
			{
				return ;
			}
		}
	}
	
	void display()
	{
		for(int i=1;i<=size;i++)
		{
			cout<<arr[i]<<" \t ";
			
			
		}
	}
	
	void deletion()
	{
		if(size==0)
		{
			cout<<"Nothing will be deleted ";
		}
		
		arr[1]=arr[size];
		size--;
		int i=1;
		
		while(i<size)
		{
			int leftindex=2*i;
			int rightindex=2*i+1;
			
			if(leftindex < size && arr[i]<arr[leftindex])
			{
				swap(arr[i],arr[leftindex]);
				i=leftindex;	
			}
			
			else if(rightindex < size && arr[i]<arr[rightindex])
			{
				swap(arr[i],arr[rightindex]);
				i=rightindex;	
			}
			
			else
			{
				return;
			}
		}
		
	}
};

int main()
{
	heap h1;
	h1.insertion(1);
	h1.insertion(4);
	h1.insertion(3);
	h1.insertion(5);
	h1.insertion(10);	
//	h1.deletion();
	h1.display();
	
}
