#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node* next;
};

class mystack{
	
	node* head;
	public:
		
		mystack()
		{
			head=NULL;
			
		}
		void push(int element)
		{
			node* temp=new node();
			temp->data=element;
			temp->next=head;
			head=temp;	
		}
		
		void pop()
		{
			if(head==NULL)
			{
				cout<<"linked list is empty :";
				return;
			}
			node* temp=head;
			head=temp->next;
			temp->next=NULL;
			delete temp;
			
		}
		
		int peek()
		{
			if(head==NULL)
			{
				cout<<"linked list is empty :";
				return -1;
			}
			
			return head->data;
		}
		
		
};

int main()
{
	mystack st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.pop();
	
	cout<<st.peek();
}

