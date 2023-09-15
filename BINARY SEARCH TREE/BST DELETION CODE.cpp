#include<iostream>
#include<queue>
using namespace std;
class node{
    public:
        int info;
        node* left;
        node* right;
        node(int val){
            info=val;
            left=NULL;
            right=NULL;
        }     
};

void inorder(node* root)
{
	if(root==NULL)
	{
		return;
	}
	
	inorder(root->left);
	cout<<root->info<<"\t";
	inorder(root->right);
}
	
	
node *deletenode(node *root, int val)
    {
        if (root == NULL)
        {
            return root;
        }
        if (val < root->info)
        {
            root->left = deletenode(root->left, val);
        }
        else if (val > root->info)
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
                root->info = temp->info;
                root->right = deletenode(root->right, temp->info);
            }
        }
        return root;
    }
    
int main(){
	
 	node *root = new node(15);
    root->left = new node(10);
    root->right = new node(20);
    root->right->left = new node(16);
    root->right->right = new node(25);
    root->left->left = new node(8);
    root->left->right = new node(12);
     
    
	deletenode(root,8);
	
	inorder(root);
    
}
