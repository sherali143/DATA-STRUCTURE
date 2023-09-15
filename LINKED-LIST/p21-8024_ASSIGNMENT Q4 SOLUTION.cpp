// NAME : SHERALI
// ROLL NUMBER : P21-8024
// ASSIGNMENT 1 : QUESTION 4


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
void swapnodes(){
	node*curr=head;

while(curr->next!=NULL){
	node *first = curr->next;
        node *second = curr->next->next;
        first->next = second->next;
        curr->next = second;
        curr->next->next = first;
        curr = curr->next->next;
//	curr=curr->next;
//	temp->next=curr->next;
//	curr->next=temp;
//	temp=curr; 	
	
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
	e1.insert(1,1);
	e1.insert(2,2);
	e1.insert(3,3);
	e1.insert(4,4);
	e1.insert(5,5);


	cout<<"list before swapping nodes"<<endl;
 e1.printinglist();
	cout<<endl;
e1.swapnodes();
	cout<<"list after swapping nodes"<<endl;
 e1.printinglist();

}
