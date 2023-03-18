#include <iostream>
using namespace std;

struct Node
{
    int key;
    Node* left,*right;
    Node(int x)
    {
        key=x;
        left=right=nullptr;
    }
};

Node* insert(Node* root,int x) 
{
    if(root==NULL) 
    {
        root=new Node(x);
        return root;
    }
    if(root->key < x)   /
        root->right=insert(root->right,x);
    else if(root->key > x) 
        root->left=insert(root->left,x);
    return root;
}

void search(Node* root,int val)
{
    while(root)
    {
        if(root->key==val) 
        {
            cout<<val<<" is found in BST!\n";
            return;
        }
        if(root->key < val) root=root->right;
        else root=root->left;
    }
    cout<<val<<" is not found in BST!\n";
}

void displayInorder(Node* root)
{
    if(root==NULL) return;
    displayInorder(root->left);
    cout<<root->key<<" ";
    displayInorder(root->right);
}

int main() {
	Node *root=NULL;
	root=insert(root,15);
	root=insert(root,12);
	root=insert(root,21);
	
	displayInorder(root);
    cout<<"\n";
    search(root,5);
    search(root,21);
	return 0;
}
