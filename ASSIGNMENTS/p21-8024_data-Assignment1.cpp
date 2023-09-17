// NAME : SHERALI
// ROLL NUMBER : P21-8024
// ASSIGNMENT 1.

// THIS CODE INCLUDE ALL THE FUNCTIONS STARTING FROM INSERTING IN NODE REMOVING NODE BY POSITION AND SWAPING VALUE BY POSITION .
#include<iostream>
using namespace std;
class node{
    public:
        int info;
        node *next;
        node (int val){
            info = val;
            next = NULL;
        }
};
class LinkedList{
    private:
        node *head;
        int length;
    public:
        LinkedList(){
            head = NULL;
            length = 0;
        }
        
    // INSERT FUNCTION JUST TO INSERT  NODES IN LINKED LIST.
    
    void insert (int val , int pos){
        if (pos < 1 || pos>length+1){
            cout << " Invalid position !" << endl;
        }
        else{
            node *n = new node(val);
            if(pos == 1){
                n->next = head; 
                head = n; 
                length++;
            }
            else
			{ 
                node *temp = head;
                for (int i = 1 ; i < pos - 1 ; i++)
				{
                    temp = temp ->next;
            	}
                temp->next = n->next;
                temp->next = n; 
                length++;
            }
        }
        
    }
    
// REMOVE FUNCTION JUST TO REMOVE A SPECIFIC NODE FROM LINKED LIST.
// DELETE NODE BY POSITION.
 
void remove(int pos){
    if(length==0){
        cout << "List is already empty !" << endl;
    }
    else{
        node *curr = head;
        if (pos < 0 || pos > length){
            cout << "Invalid position ! " << endl;
        }
        else{
            
            if (pos == 1){
               curr = head;
                head = head->next;
                delete curr;
                length--;
            }
            else{
                node *slow = NULL;
                for (int i = 1 ; i < pos ; i++)
                {
                    slow = curr;
                    curr = curr->next; 
                }
                slow->next = curr->next;
                delete curr;
                length--;
            }
            
        }
    }
}

// ADD FUNCTION TO FIND SUM OF ALL VALUES PRESENT IN NODES OF LNIKED LIST.
// LAB TASK .

void add(){
    node *temp = head;
    int count = 0 ;
    int sum = 0;
    while (temp != NULL){
        sum+= temp->info;
        count ++;
        temp = temp->next;
    }
    cout << "Sum is " << sum << endl;
    cout << "Average is " << sum / count << endl;
}

// CONCATINATION FUNCTION TO CONCATINATE TWO LINKED LIST.
// LAB TASK CODE.

void concatination(LinkedList x)
{
    node *temp = this->head;
    node *temp1 = x.head;
    while (temp->next != NULL){
        temp = temp->next;
    }
    temp->next = temp1;
}

// PRINT FUNCTION JUST TO PRINT A NODES THAT IS PRESENT IN LINKED LIST.

void printList(){
    node* curr = head;
    while (curr != NULL){
        cout << curr->info << "\t";
        curr = curr->next;
    }
    cout<<endl ; 
}

// SWAPING FUNCTION TO SWAP VALUE BY POSIITION.

  void swapnode (int lpos , int rpos){
  if (lpos==rpos)
  {
  return ; 
  }
  	node* emptyptr;
    node* node1 = emptyptr ; 
    node* temp1 = this->head ;
    node* node2 = emptyptr ; 
    node* temp2 = this->head ;
    for (int i = 1 ; i < lpos -1 ; i++)
    {
    temp1 = temp1->next ; 
    }
    node1 = temp1 ; 
    temp1 = temp1->next; 
    for (int i = 1 ; i < rpos -1 ; i++)
    {
    temp2 = temp2->next;
    }
    node2 = temp2 ; 
    temp2 = temp2->next ; 
    
    if(temp1 == emptyptr || temp2 ==emptyptr)
    {
    return ; 
    }
    if(node1 !=emptyptr)
    {
    node1->next= temp2 ; 
    }
    else
    {
    this->head = temp2 ; 
    }
    if(node2 !=emptyptr)
    {
    node2->next= temp1 ; 
    }
    else
    {
    this->head = temp1 ; 
    }
    
    
    node* temp3 = temp2 ->next ; 
    temp2->next = temp1->next ;
    temp1->next = temp3 ; 

}
};


int main()
{
    LinkedList l1,l2;
    l1.insert(5 , 1);
    l1.insert(10 , 2);
    l1.insert(15,3);
    l1.insert(20 , 4);
    l1.insert(25 , 5);
    l1.insert(30,6);
    l1.insert(35 , 7);
    l1.insert(40 , 8);
    l1.printList() ; 
    l1.swapnode(2,5);
    l1.printList();
    return 0 ; 
}
