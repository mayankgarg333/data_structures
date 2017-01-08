#include<iostream>
#include<queue>

using namespace std;

struct TreeNode{
	int data;
	struct TreeNode* left;
	struct TreeNode* right;	
	TreeNode(int x=0): data(x), left(NULL), right(NULL){}
};


void print_inorder(TreeNode* root){
	if(root==NULL)
		return;
	print_inorder(root->left);
	cout << root->data << " ";
	print_inorder(root->right);
	return;
}


void print_preorder(TreeNode* root){
	if(root==NULL)
		return;
	cout << root->data << " ";
	print_preorder(root->left);
	print_preorder(root->right);
	return;
}

void print_postorder(TreeNode* root){
	if(root==NULL)
		return;
	print_postorder(root->left);
	print_postorder(root->right);
	cout << root->data << " ";
	return;
}

int main()
{
	queue <TreeNode**> myqueue; 	// we basically need address of the pointer
	int num[]={1,2,4,5,6,8,9};
	TreeNode* root, **a;
	myqueue.push(&root);
	/*
	a =myqueue.front();
	cout << tmp << " " << a << " " << &tmp << endl;
	*a = new TreeNode(1);
	cout << *a << " " << (*a)->data << " " << &(*a)->left << endl;
	myqueue.push(&(*a)->left);
	myqueue.push(&(*a)->right);*/
	
	for(int i=0;i<sizeof(num)/sizeof(num[0]);i++){
		a =myqueue.front();
		*a = new TreeNode(num[i]);
		myqueue.push(&(*a)->left);
		myqueue.push(&(*a)->right);
		myqueue.pop();
	}
	
	print_inorder(root);
	cout<<endl;
	print_preorder(root);
	cout<<endl;
	print_postorder(root);
	cout<<endl;
	return 0;

}


