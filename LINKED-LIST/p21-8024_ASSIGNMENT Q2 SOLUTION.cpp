// NAME : SHERALI
// ROLL NUMBER : P21-8024
// ASSIGNMENT 1 : QUESTION 2




#include<iostream>
using namespace std;
class node{
	public:
	node*next;
	int info;
	node(int val){
		next=NULL;
		info=val;
	}
	
};
class palindrome{
	private:
		node*head;
		int length;
		int pos;
		public:
	palindrome(){
		head=NULL;
		length=0;
		pos=0;
	}	
	void insert(int val,int pos){
		if(pos<1|| pos>(length+1)){
			cout<<"invalid position"<<endl;
			return;
		}
		else{
			node*n=new node(val);
			if(head==NULL){
				n->next=head;
				head=n;
				
			}
		else{
			node*curr;
			curr=head;
			for(int i=1; i<(pos-1); i++){
				curr=curr->next;
				
			}	
			curr->next=n->next;
		curr->next=n;
			
			
		}	
			length++;
		}
	}	
void checkpalindrome(palindrome a, palindrome b){
	node*curr=a.head;
	node*curr1=NULL;
	 while(curr!=NULL)
    {
        node *n=new node(curr->info);
        n->next=b.head;
        b.head=n;
        curr=curr->next;
    }
    node *cp1=b.head;
    node *cp=a.head;

    while(cp!=NULL)
    {
        if(cp->info!=cp1->info) 
        {
            cout<<"list is not a palindrome."<<endl;
            
            return;
        }

        cp=cp->next;
        cp1=cp1->next;
    }

    
    cout<<"list palindrome."<<endl;
}



void printlist(){
	node*curr;
	curr=head;
	while(curr!=NULL){
		cout<<curr->info<<"--->";
		curr=curr->next;
	}
}	

	
};
int main(){
	palindrome p,p1;
	p.insert(1,1);
	p.insert(2,2);
	p.insert(3,3);
	p.insert(3,4);
	p.insert(2,5);
	p.insert(5,6);
	cout<<"list is"<<endl;
	p.printlist();
	cout<<endl;
	
	p.checkpalindrome(p,p1);

}
