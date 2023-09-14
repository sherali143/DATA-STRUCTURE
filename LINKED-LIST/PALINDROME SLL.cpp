#include<iostream>
using namespace std;

class node{
	
	public:
		node* next;
		int data;
		
	node(int val)
	{
		this->data=val;
		next=NULL;
	}
};


	void insertion(node* &head,int val)
	
	{
		node* n=new node(val);
		
		if(head==NULL)
		{
			head=n;
			return;
		}
		
		node* temp=head;
		
		while(temp->next != NULL)
		{
			temp=temp->next;
		}
		temp->next=n;
	}
	
	
	
	void display(node* head)
	{
		node* temp=head;
		
		while(temp != NULL)
		{
			cout<<temp->data<<"\t";
			
			temp=temp->next;
		}
	}
	
	
	
	node* getmid(node* head)
	{ 
		node* slow=head;
		node* fast=head->next;
		
		while(fast != NULL && fast->next != NULL)
		{
			slow=slow->next;
			fast=fast->next->next;
		}
		
		return slow;
	}
	
	node* reverse(node* head)
	{
		node* prev=NULL;
		node* curr=head;
		node* next=NULL;
		
		while(curr != NULL)
		{
			next=curr->next;
			curr->next=prev;
			prev=curr;
			curr=next;	
		}
		return prev;
		
	}
	
	bool is_palindrome(node* head)
	{
		if (head==NULL || head->next== NULL)
		{
			return true;
		}
		
		node* middle=getmid(head);
		
		node* temp=middle->next;
		
		middle->next=reverse(temp);
		
		
		node* head1=head;
		node* head2= middle->next;
		
		while(head2 != NULL)
		{
			if(head1->data != head2->data)
			{
				return false;
			}
			
			head1=head1->next;
			head2=head2->next;
		}
		
		return true;
	}
	
	
	int main()
	{
		
		node* head=NULL;
		insertion(head,4);
		insertion(head,2);
		insertion(head,1);
		insertion(head,2);
		insertion(head,4);
		
		
		display(head);
		
		if(is_palindrome(head))
		{
			cout<<"Yess";
		}
		
		else
		{
			cout<<"Not";
		}
	}
