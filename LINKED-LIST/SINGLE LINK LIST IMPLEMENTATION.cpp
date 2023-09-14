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
        
    void insert (int val , int pos){
        if (pos < 1 ){
            cout << " Invalid position !" << endl;
        }
        else{
            node *n = new node(val);
            if(pos == 1){
                // n is now the first node!!!!!!!!!!!!
                n->next = head; //Value
                head = n; //address
                cout << "IF : node->info = " << n->info << endl;
                
            }
            else{ 
                
                cout << "Else node-> info = " << n->info << endl;
                node *temp = head;
                for (int i = 0 ; i < pos - 1 ; i++){
                    temp = temp ->next; // Gives next block address (temp++)
                }
                // n is now the node before the pos we want to enter
                n->next = temp -> next;  // For info (value)
                temp->next = n;  // For address (next) 

            }
        }
        length++;
    }

    void print()
    {
        node* temp = head ; 
        while(temp!= NULL)
        {
            cout<<temp->info<<" -> " ; 
            temp = temp->next ; 
        }
        cout<<endl;
    }

	void comp_node(LinkedList l1)
	{
		cout<<"hello";
		
	}


};

int main(){

    LinkedList l1;
    l1.insert(10 , 1);
    l1.insert(20 , 2);
    l1.insert(40,3);
    
    cout<<l1.comp_node(l1);
   
    l1.print() ; 
   
    
}
