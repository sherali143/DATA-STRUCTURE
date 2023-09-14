#include<iostream>
using namespace std;

class node
{
	public:
		int info;
		node *next;
		
	node(int val)
	{
		info=val;
		next=NULL;
	}
};

class linkedlist
	{
	private:
		node* head;
		int length;
	public:
		
	linkedlist()
	{	
		head=NULL;
		length=0;
	}
	
	void insertion(int val,int pos)
	{
			if(pos<1 || pos>length+1)
			{
				return;
			}
			
			node* n=new node(val);

			if(pos==1)
				{
					n->next=head;
					head=n;
					length++;
				}
			else
				{
					node* temp=head;
					
					for(int i=1;i<pos-1;i++)
					{
						temp=temp->next;
					}

					n->next=temp->next;
					temp->next=n;
					length++;
				}

	}
	void deletion(int pos)
		{
			if(pos<1 || pos>length+1)
			{
				return;
			}
		
			if(length==0)
			{
				return;
			}
		
			node *curr=head;
		
			if(pos==1)
				{
					head=head->next;
					delete curr;
				}
		else
			{
				node *slow=NULL;
				for(int i=1;i<pos;i++)
				{
					slow=curr;
					curr=curr->next;
				}
					slow->next=curr->next;
					delete curr;
			}
	
			length--;

		}
		
	void printing()
		{
			node *n=head;
			while(n!=NULL)
			{
				cout<<n->info<<"\t";
				n=n->next;
			}
	
			cout<<endl;
			cout<<"-----------------------------------:"<<endl;
		}
	
		
void concatination(linkedlist a)
{
	node* curr=head;
	while(curr->next!=NULL)
	{
		curr=curr->next;
	}
	curr->next=a.head;
}
	
void summingandaverage()
	{
		float sum;
		float counter=0;
		node *n=head;
		while(n!=NULL){
		
		cout<<n->info<<"\t";
		sum+=n->info;
		counter+=1;
		n=n->next;
	}
	
	cout<<endl;
	cout<<"sum:"<<sum<<endl;
	
	float avg=sum/counter;
	cout<<"avg:"<<avg<<endl;

	}
};

int main()
{
	linkedlist l1,l2;
	l1.insertion(66,1);
	l1.insertion(22,2);
	l1.insertion(33,3);
	l1.insertion(44,4);
	
	l2.insertion(100,1);
	
	l1.printing();
	

	l1.summingandaverage();
	
	l1.concatination(l2);
	
	l1.printing();

}
