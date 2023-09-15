#include<iostream>
using namespace std;

class stack{
	
	public:
		int *arr;
		int size;
		int top;
		
	stack(int size)
	{
		this->size=size;
		arr=new int [size];
		top=-1;
	}
	
	void push(int element)
	{
		if(size-top > 1)
		{
			top++;
			arr[top]=element;
		}
		else
		{
			cout<<"Stack is full";
		}
	}
	
	void pop()
	{
		if(top>=0)
		{
			top--;
		}
		else
		{
			cout<<" Stack is empty ";
		}
	}
	
	int peek()
	{
		if(top>=0)
		{
			return arr[top];
		}
		else
		{
			cout<<"Stack is underflow ";
			return -1;
		}
	}
	
	bool is_empty()
	{
		if(top==-1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}	
};

int main()
{
	stack st(10);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	st.push(7);
	st.push(8);
	st.push(9);
	st.push(10);
	cout<<st.peek()<<endl;
	st.pop();
	cout<<st.peek();
}
