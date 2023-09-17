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


void inorder(node* root,int k )
{
	static int count=0;
	
	if(root== NULL)
	{
		return ;
	}
	
	inorder(root->left,k);

	count++;
	
	if(k==count)
	{
		cout<<root->data;
		return;
	}
	


	inorder(root->right,k);

	
	
	
}


int main()
{ 
	// 10 5 2 -1 -1 7 -1 -1 15 12 -1 -1 20 -1 -1
	
	node* root=NULL;
	root=buildtree(root);
	
	cout<<"Kth smallest node:";
	
	inorder(root,6);
	
	
	
}
