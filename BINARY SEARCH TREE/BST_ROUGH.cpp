#include<iostream>
using namespace std;
class node{
	public:
		int* arr;
		int index=0;
		int data;
		node* left;
		node* right;
		
	node(int val)
	{
		this->data=val;
		left=NULL;
		right=NULL;
	}
};

node* buildtree(node* root)
{
	cout<<"Enter the data ";
	int data;
	cin>>data;
	root=new node(data);
	
	if(data==-1)
	{
		return NULL;
	}
	
	cout<<"Enter the data for inserting in Left of "<<data<<endl;
	root->left=buildtree(root->left);
	
	cout<<"Enter the data for inserting in right of "<<data<<endl;
	root->right=buildtree(root->right);

	return root;
}

//void inorder(node* root,int k )
//{
//	static int count=0;
//	
//	if(root== NULL)
//	{
//		return ;
//	}
//	
//	inorder(root->left,k);
//
//	count++;
//	
//	if(k==count)
//	{
//		cout<<root->data;
//		return;
//	}
//	
//
//
//	inorder(root->right,k);
//
//}

void largest_value(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	if(root->left==NULL and root->right==NULL)
	{
		cout<<"The largest value of root is :"<<root->data;
	}
	
	while(root->right != NULL)
	{
		root=root->right;
	}
	
	cout<<"largest value:"<<root->data;
}

void smallest_value(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	while(root->left != NULL)
	{
		root=root->left;
	}
	
	cout<<"Smallest value is :"<<root->data;
}



void leaf_node(node* root)
{
	int count=0;
	if(root==NULL)
	{
		return ;
	}
	
	if(root!=NULL)
	{
		leaf_node(root->left);
		
		if(root->left == NULL and root->right ==NULL)
		{
			count=count+1;
		}
		
		leaf_node(root->right);
		
		
		cout<<count;
	}	
}

node* finding_value(node* root,int val)
{

	if(root==NULL)
	{
		return 0;
	}
	
	if(val==root->data)
	{
		cout<<"Yes Exist 1";
	}
	else
	{
		cout<<"Does not exist ";
		return 0;
	}
	
	if(val < root->data)
	{
		return finding_value(root->left,val);
		
	}
	
	if(val > root->data)
	{
		return finding_value(root->right,val);
	}
	
}

node* returning_root(node* root,int key)
{
	if(root==NULL)
	{
		return 0;
	}
	
	if(key==root->data)
	{
		cout<<root->data<<"\t";
		cout<<root->left->data<<"\t";
		cout<<root->right->data;
	}
	
	if(key>root->data)
	{
		return returning_root(root->right,key);
	}
	
	if(key<root->data)
	{
		return returning_root(root->left,key);
	}
	
	
}

void print_even_nodes( node* root)
{
    if (root == NULL)
        return;
        
    //print_even_nodes(root->left);
    if (root->data % 2 == 0)
        cout << root->data << " ";
        
    print_even_nodes(root->left);
    print_even_nodes(root->right);
}

int calculateSum (node* root)
{
  int sum, sumLeft, sumRight;
  sum = sumRight = sumLeft = 0;

  if (root == NULL)
    {
      printf ("Tree is empty\n");
      return 0;
    }
  else
    {
      if (root->left != NULL)
	sumLeft = calculateSum (root->left);
      if (root->right != NULL)
	sumRight = calculateSum (root->right);

      sum = root->data + sumLeft + sumRight;
      return sum;
    }
}

int sum(struct node *root)
{
    if (root == NULL)
        return 0;
     
    return sum(root->left) + root->data +
           sum(root->right);
}
 
// Returns 1 if sum property holds for
// the given node and both of its children
int isSumTree(struct node* node)
{
    int ls, rs;
 
    // If node is NULL or it's a leaf
    // node then return true
    if (node == NULL ||
       (node->left == NULL &&
        node->right == NULL))
        return 1;
 
   // Get sum of nodes in left and
   // right subtrees
   ls = sum(node->left);
   rs = sum(node->right);
 
   // If the node and both of its
   // children satisfy the property
   // return 1 else 0
    if ((node->data == ls + rs) &&
          isSumTree(node->left) &&
          isSumTree(node->right))
        return 1;
 
   return 0;
}

void sum_replace(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	sum_replace(root->left);
	sum_replace(root->right);
	
	if(root->left != NULL)
	{
		root->data=root->left->data;
		
	}

	if(root->right != NULL)
	{
		root->data=root->right->data;
		
	}
}


int main()
{ 
// use this full line as input 
// 50 40 30 -1 -1 45 -1 -1 60 55 -1 -1 65 -1 -1
	node* root=NULL;
	root=buildtree(root);
//	inorder(root);
//	int arr[7];
//	smallest_value(root);
//	cout<<endl;
//	largest_value(root);
	
//	leaf_node(root);

//	cout<<endl;
	
//	if(finding_value(root,2))
//	{
//		cout<<"Yes exist";
//		}
//		
//	else
//	{
//		cout<<"Doesnot exist";
//		}	
	
//	finding_value(root,155);
//	cout<<endl;
//	returning_root(root,4);
	
//	store_inorder(root);
//	printing_array(arr);

//	print_even_nodes(root);

//	cout<<calculateSum (root);
	
//	cout<<calculating_sum(root);

//if (isSumTree(root))
//        cout << "The given tree is a SumTree ";
//    else
//        cout << "The given tree is not a SumTree ";
// 



		
}





