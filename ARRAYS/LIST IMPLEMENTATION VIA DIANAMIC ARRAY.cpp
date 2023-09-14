#include <iostream>
#include <string>
using namespace std;
class arrylisted
{
private:
    int *arr=0,capacity,tem,length,*current;
public:
    arrylisted(int capacity)
    {
        arr=new int[capacity];
        this->capacity=capacity;
        length=0;
    }
        ~arrylisted()
        {
            delete arr;
        }
    void start()
    {
        current=arr;
    }
    void next()
    {
        current++;
    }
    void back()
    {
        current--;
    }
    void tail()
    {
        current=arr+length-1;
    }
   
    void insert(int val,int pos)
    {
        if (length==capacity)
        {
            return;
        }
        
        if (pos<1 || pos>length+1)
        {
            return;
        }
        tail();
        for (int i = length; i >= pos; i--)
        {
            back();
        }
        *(current+1)=val;
        length++;
        start();
    }
     void Insert(int val)
    {   
        start();
       if (length==capacity)
       {
        cout<<"lisst is full";
           
       }
       else
       {
        current+=length;
        *current=val;
        length++;
       }
       
        }
   void remove(int pos)
    {
    	pos-=1;
        if (length==0)
        {
            cout<<"list is not valid!";
            return;
        }
        if (pos < 1 || pos > length)
        {
            return;
        }
        start();
        current=arr + pos - 1;
        for (int i = pos; i <= length ; i++)
        {if (pos == length)
           {
           	*current=0;
             length--;}
           else
           {
            
            (current)=(current+1);
            
            next();
           }   
        } 
        length--;
        start();
    }

    void find(int val)
    {
        if (length==0)
        {
            cout<<"List is not valid";
            return ;
        }
        start();
        for (int i = 1; i <= length; i++)
        {
            if (*current==val)
            {   
                
                cout<<"yes"<<endl;
                return;
                
            }
            next();
        }
                start();
                cout<<"no"<<endl;
                return;
    }
    
     void printArr()
    {
        start();
        for(int i =0; i<length; i++)
        {
        cout<<*current<<" ";
        current++;
        }
    }
   void reverse(){
    	int *start=arr;
    	int *end=arr+length-1;
    	int temp;
    	
    	while(start!=end){
    		temp=*start;
    		*start=*end;
    		*end=temp;
    		start++;
    		end--;
		}
		cout<<"The reversed array is::"<<endl;
		int *n=arr;
		for(int i=0; i<length; i++){
			cout<<*n<<"\t";
			n++;
		}
	}
    
    void sort()
    
    {
	start();
        for (int i = 0; i < capacity; i++)
{
    for (int j = i; j < capacity; j++)
    {
        if (*(current + j) < *(current + i)) { 
  
                tem = *(current+ i); 
                *(current + i) = *(current + j); 
                *(current + j) = tem; 
    } 
}

}
    }

    bool isEmpty()
    {
        if (length ==0)
        {
          return true;
        }
        else
        {
            return false;
        }
        
    }
    bool isFull()
    {
        if (length == capacity)
        {
           return true;
        }
        else
        {
            return false;
        }
        
    }
    void emptyList()
    {
        if(isEmpty())
        {
            return;
        }
        else
        {
            return;
        }

    }
};

int main()
{

 arrylisted al(4);
al.printArr();
cout<<"1) print array:"<<endl;
 al.insert(3,1);
 al.insert(5,2);
 al.insert(70,3);
 al.insert(17,4);
 al.printArr();

cout<<endl;
cout<<"2) remove  value:"<<endl;
  al.remove(2);

 al.printArr();
  cout<<endl;
  cout<<"5) find value:"<<endl;
 al.find(17);
  al.printArr();
cout<<endl;
cout<<"6) find sorting:"<<endl;
  al.sort();
  al.printArr();
  cout<<endl;
  cout<<"7) find emptyness:"<<endl;
  cout<<al.isEmpty()<<endl;

cout<<"8) find isFull:"<<endl;
  cout<<al.isFull()<<endl;

  cout<<"9) find listEmpty:"<<endl;
  al.emptyList();
 al.printArr();
   cout<<"9) find reverse:"<<endl;
   al.reverse();
   
}
