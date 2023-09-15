#include<iostream>
using namespace std;
class node{
	public:
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

int sum(struct node *root)
{
    if (root == NULL)
        return 0;
     
    return sum(root->left) , sum(root->right);
}

bool final_function(node* node,int key)
{
    int ls, rs;
 
 
    if (node == NULL ||
       (node->left == NULL &&
        node->right == NULL))
        return 1;
 
   ls = sum(node->left);
   rs = sum(node->right);
 
  
  
    if ((key == ls * rs) &&
          final_function(node->left,key) &&
          final_function(node->right,key))
        return 1;
 
   return 0;
}

int main()
{ 
// use this full line as input 
// 50 40 30 -1 -1 45 -1 -1 60 55 -1 -1 65 -1 -1

	node* root=NULL;
	root=buildtree(root);
//	inorder(root);
	final_function(root,1200);

}


