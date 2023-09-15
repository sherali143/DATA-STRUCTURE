#include<iostream>
using namespace std;

class node{
	public:
		int data;
		node *next;
		
	node(int val)
	{
		this->data=val;
		next=NULL;
	}
};

class queue{
	public:
		node* front;
		node* back;
		
	queue( )
	{
		front=NULL;
		back=NULL;
	}
	
	void enqueue(int x)
	{
		node* n=new node(x);
		
		if(front==NULL)
		{
			back=n;
			front=n;
			return;
		}
		
		back->next=n;
		back=n;
	}
	
	void dequeue()
	{
		if(front==NULL)
		{
			cout<<"Queue overflow"<<endl;
			return;
			
		}
		
		node* todelete=front;
		front=front->next;
		
		delete todelete;
		
	}
	
	bool empty()
	{
		if(front==NULL)
		{
			return true;
			
		}
		
		return false;
	}
	
	void display()
	{
		node *curr = front;
		while(curr != NULL)
		{
			cout<<curr->data<<"    ";
			curr= curr->next;
		}
	}
	
	int peek()
	{
		if(front==NULL)
		{
			cout<<"No element in queue "<<endl;
			return 0;
		}
		
		return front->data;
	}
	
	
	void duplicate(queue &q1)
	{
		node* temp=front;
		
		while(temp != NULL)
		{
			for(int i=0;i<temp->data;i++)
			{
				q1.enqueue(temp->data);
			}
			
			temp=temp->next;
			
		}
	}
	
};

int main()
{
	queue q,q1;
	q.enqueue(1);
	q.enqueue(2);
	q.enqueue(3);
	
	q.duplicate(q1);
	q1.display();
	cout<<endl;
	
	
	cout<<"Element in queue:";
	q.display();
	cout<<endl;
	
	cout<<"Peak element in queue:";
	cout<<q.peek();
	cout<<endl;
	
	cout<<"Dequeue:";
	q.dequeue();
	cout<<q.peek();
}
