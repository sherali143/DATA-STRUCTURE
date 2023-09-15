// NAME : SHERALI
// ROLL NUMBER : P21-8024
// ASSIGNMENT 1 : QUESTION 3



#include<iostream>
using namespace std;
class node{
	public:
		node*next;
		int info;
		node(int val){
			info=val;
			next=NULL;
			
			
		}
};
class EvenList{
	private:
	node*head;
	int length;
	int pos;
	
	public:
		EvenList(){
			head=NULL;
			length=0;
			pos=0;
		
			
		}
	
	void insert(int val,int pos){
		node*n=new node(val);
	if(pos==1){
				n->next=head;
				head=n;
				
			}
			else{
			
			node*temp=head;
			
			for(int i=1; i<pos-1; i++){
				temp=temp->next;
				
			}
			n->next=temp->next;
				temp->next=n;
		
		
	}
	length++;
}
//
//void deleteduplicate(EvenList a, EvenList b){
//	
//	node*curr=a.head;
//	node*curr1=NULL;
//	 while(curr!=NULL)
//    {
//        node *n=new node(curr->info);
//        n->next=b.head;
//        b.head=n;
//        curr=curr->next;
//    }
//  
//    
//}
void deleteduplicate(){
	
	node*curr=head;
node*temp=NULL;
	while(curr->next!=NULL){

	
		if(curr->info==curr->next->info){
			temp=curr->next;
			curr->next=curr->next->next;
			
			delete temp;
			
		
		}
	else{
	
		curr=curr->next;
	}	
	}
	
	
}
	void printinglist(){
		node*temp=head;
while(temp!=NULL){
			cout<<temp->info;
			temp=temp->next;
			
		}
}
		
};
int main(){
	EvenList e1,e2;
	e1.insert(2,1);
	e1.insert(3,2);
	e1.insert(3,3);
	e1.insert(5,4);
	e1.insert(5,5);
	e1.insert(7,6);

	cout<<"list before removing duplicate"<<endl;
 e1.printinglist();
	cout<<endl;

cout<<endl;
e1.deleteduplicate();
cout<<"list after removing duplicate"<<endl;
e1.printinglist();
}
