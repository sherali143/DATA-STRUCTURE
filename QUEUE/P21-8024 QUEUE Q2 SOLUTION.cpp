#include<iostream>
using namespace std;

class node{
	public:
		string name;
		int employee;
		int salary;
		node* next;
	node(int employee,string name,int salary)
	{
		this->employee=employee;
		this->name=name;
		this->salary=salary;
		this->next=NULL;
	}
};

class queue{
	public:
		node* front;
		node* back;
		
	queue()
	{
		front=NULL;
		back=NULL;
	}
	
	void enqueue(int e,string n,int s)
	{
		node *t=new node(e,n,s);
		if(front==NULL)
		{
			back=t;
			front=t;
			return;
		}
		
		back->next=t;
		back=t;
			
		
		
	}
	
	void display()
	{
		node* temp=front;
		
		while(temp != NULL )
		{
			cout<<"Employee id : "<<temp->employee<<" "<<"Employee salary :"<<temp->salary<<" "<<"Employee name :"<<temp->name<<" "<<endl;
			temp=temp->next;
		}
		
		
	}
};

int main()
{
	queue q1;
	q1.enqueue(1,"sherali",5000);
	q1.enqueue(2,"samad",3000);
	q1.enqueue(3,"mubeen",2000);
	
	q1.display();
}
