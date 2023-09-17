// NAME : SHERALI
// ROLL NO : P21-8024

#include<iostream>
using namespace std;

struct node {
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

// INSERTION IN BST AND MAINTAINING IT PROPERLY:

node* insertbst(node* root,int val) 
		{
			
			if(root==NULL)
			{
				return new node(val);
			}
			  if(val < root->data)
			  {
			  	root->left=insertbst(root->left,val);
			  }
			  
			  if(val > root->data)
			  {
			  	root->right=insertbst(root->right,val);
			  }
			  
			  return root;
		}
		
// PRINTING INORDER TRANSVERSAL:

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder(root->left);
	cout<<" ";
	cout<<root->data;
	cout<<" ";
	inorder(root->right);
	cout<<" ";
}

// SIMPLE FUNCTION FOR CHECKING BST IS EMPTY OR NOT :
// IF ROOT ==NULL BST IS EMPTY:

void empty(node* root)
{
	if(root==NULL)
	{
		cout<<"BST is empty ";
		
	}
	else
	{
		cout<<"BST is not empty";
	}
	
}

// SEARCHING ELEMENT IN BST:

node* searchinbst(node* root,int key)
{
	if(root==NULL)
	{
		return NULL;
	}
	
	if(root->data == key)
	{
		return root;
	}
	
	if(root->data > key)
	{
		return searchinbst(root->left,key);
	}
	
	return searchinbst(root->right,key);
}

// DELETION CODE :

node *deletenode(node *root, int val)
    {
        if (root == NULL)
        {
            return root;
        }
        if (val < root->data)
        {
            root->left = deletenode(root->left, val);
        }
        else if (val > root->data)
        {
            root->right = deletenode(root->right, val);
        }
        else
        {
            // Case 1: No child
            if (root->left == NULL && root->right == NULL)
            {
                delete root;
                root = NULL;
            }
            // Case 2: One child
            else if (root->left == NULL)
            {
                node *temp = root;
                root = root->right;
                delete temp;
            }
            else if (root->right == NULL)
            {
                node *temp = root;
                root = root->left;
                delete temp;
            }
            // Case 3: Two children
            else
            {
                node *temp = root->right;
                while (temp->left != NULL)
                {
                    temp = temp->left;
                }
                root->data = temp->data;
                root->right = deletenode(root->right, temp->data);
            }
        }
        return root;
    }

int main()
{
	node* root=NULL;
	root=insertbst(root,50);
	insertbst(root,30);
	insertbst(root,70);
	insertbst(root,20);
	insertbst(root,40);
	insertbst(root,60);
	insertbst(root,80);
	
	deletenode(root,80);
	
	inorder(root);
	
	cout<<endl;
	
	if(searchinbst(root,15)==NULL)
	{
		cout<<"Key does not exist";
	}
	
	else{
		cout<<"Key exists";
	}
	
	cout<<endl;
	
	empty(root);
	
	return 0;
	
}
