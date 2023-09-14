#include<iostream>
using namespace std;

class node{
    public:
        int info;
        node *next;
        node *prev;
        node (int val){
            info = val;
            next = NULL;
            prev = NULL;
        }
};

class DoubleLinkedList{
    private:
        node *head;
        int length;
    public:
        DoubleLinkedList(){
            head = NULL;
            length = 0;
        }

        void insert(int val , int pos)
        {
            if(pos>(length+1) || pos<1 ){
                cout << "Invalid position" << endl;
                return;
            }
            
                node *n = new node(val);
                if(pos==1){

                    n->next = head;
                    if(head!=NULL)
                        head->prev = n;
                        head = n;
                    
                     //head ko new node pe krha kro b/c n is the first new node and head is always at the start
                    
                }
                // else{
                //     node *curr = head;
                //     for (int i = 1 ; i < (pos-1) ; i++)
                //     {
                //         curr = curr->next;
                //     }
                //     n->next = curr->next;
                //     n->prev = curr;
                //     if (curr->next != NULL)
                    
                //         (curr->next)->prev = n;
                    
                //     //curr aik pos pehle krha kiya tha 
                //     curr->next = n;
                // }
                // length++;
            else{
                node *curr = head;
                for (int i=1 ; i<(pos-1) ; i++){
                    curr = curr->next;
                }
                curr->next = n;
                n->prev = curr;
                // n->next = curr>next;
                if(curr->next != NULL){
                    curr = curr->next;
                    curr->prev = n;
                }
            }
            length++;
        }

void sep(){
    node* curr = head;
    DoubleLinkedList d2 , d3;
    int index1 =  1;
    int index2 = 1;
    while (curr->next != NULL){
        if (curr->info %2 == 0){
            d2.insert(curr->info , index1);
            index1++;        
        }
        else{
            d3.insert(curr->info , index2);
            index2++;
        }
        node* head1 = d2.head;
        cout << head1->info << endl;
        node* head2 = d3.head;
    //     while (head1 != NULL){
    //         head1 == head1->next;
    //     }
    //     head1->next = head2;
    //     head2->prev = head1;
    // }
}
}
void remove(int pos){
    if(length == 0 ){
        cout << "List is already empty " << endl;
    }
    else{
        if (pos < 0){
            cout << "Invalid positon " << endl;
        }
        else{
            node *curr = head;
            if(pos==1){
                head = head->next;
                delete curr;
                if(head->next != NULL){
                    head->prev = NULL;
                }
            }
            else{
                node *slow = head;
                for (int i=1 ; i<pos; i++)
                {
                    slow = curr;
                    curr = curr->next;
                }
                slow->next = curr->next;
                if (curr->next != NULL){
                    curr->next->prev = slow;
                    delete curr;
                }             
            }
        }
    }
    length--;
}

void reverse(){
    node *temp =  NULL;
    node *curr = head;
    while (curr != NULL){
        temp = curr->prev;   //curr se aik pehle
        curr->prev = curr->next;    //current->next node ab pehle node k peche
        curr->next = temp;   //current ka new next which is isse pehle wala node.
        curr = curr->prev;
    }
    if (temp != NULL)
    {
        head = temp->prev;  //temp ka prev islye kuke temp ab pehle 
                            //node k sath agy agya tha 
    }
}

void printMe(){
    node* curr = head;
    while (curr != NULL ){
        cout << curr->info << "->";
        curr = curr->next;
    }
}

};

int main(){
    DoubleLinkedList l1;
    l1.insert(10,1);
    l1.insert(20,2);
    l1.insert(30,3);
    l1.insert(40,4);
    // l1.remove(2);
    l1.reverse();
    l1.printMe();

}
