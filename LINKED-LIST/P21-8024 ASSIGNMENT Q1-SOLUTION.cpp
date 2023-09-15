// NAME : SHERALI
// ROLL NUMBER : P21-8024
// ASSIGNMENT 1 : QUESTION 1



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
void insertatmiddle(int val){
	node*n=new node(val);
	node*curr=head;
for(int i=1; i<(length/2); i++){
	curr=curr->next;
}
n->next=curr->next;
curr->next=n;
length++;
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
	EvenList e1;
	e1.insert(2,1);
	e1.insert(3,2);
	e1.insert(4,3);
	e1.insert(5,4);
	e1.insert(6,5);
	e1.insert(7,6);

	cout<<"list before insertion in middle"<<endl;
 e1.printinglist();
	cout<<endl;
	e1.insertatmiddle(5);
	cout<<"list after insertion in middle"<<endl;
	e1.printinglist();
}
