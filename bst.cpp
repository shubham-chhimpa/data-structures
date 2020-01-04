
/*

     AUTHOR : SHUBHAM CHHIMPA


*/

#include<bits/stdc++.h>
using namespace std;




// returns max of two numbers
int Max(int a,int b){
	if (a >=b) return a;
	else return b;
}

// Node of binary tree with 
// two childs
// left and right 
// and data
struct Node {
	int data;
	Node* left;
	Node* right;
};

//height of a tree 
// when nodes = 0   h =-1
// when nodes = 1   h = 0
// when nodes = n   h = number of edges in the
// longest path to leaf node
// time complexity = O(n)
int height(Node* root){

	if(root ==NULL){
		return -1;
	}

	int leftheight = height(root->left);
	int rightheight = height(root->right);
	return Max(leftheight,rightheight) + 1;
}


// returns a pointer to new node object
Node* getNewNode(int data){
	Node* newNode  = new Node();
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

// time complexity = O(log (n))
Node* insert(Node* root,int data){
	if(root==NULL){
		root = getNewNode(data);
	}
	else if (data <= root->data){
		root->left = insert(root->left,data);
	}
	else{
		root-> right = insert(root->right,data);
	}
 //cout<<root->data<<"\n";

	return root;

}


// time complexity = O(n)
bool search(Node* root,int data){
	if(root==NULL){
		return false;
	}
	if(root->data ==data) return true;
	else if(data <= root->data){
		return search(root->left,data);
	}
	else{
		return search(root->right,data);
	}
}

// time complexity = O(log(n))
int findMin(Node *root){
	if(root == NULL){
		return -1;
	}
	//base condition
	if(root->left == NULL){
		return root->data;
	}
	//search left subtree
	return findMin(root->left);
}
// time complexity = O(log(n))
int findMax(Node *root){
	if (root == NULL) return -1;
	if (root->right == NULL){
		return root->data;
	}

	return findMax(root->right);
}


/*
Tree Traversal
  1. Breadth First
     1.1 Level Order 
  2. Depth First

  2.1  Preorder   <root> <left> <right>
  2.2  Inoreder   <left> <root> <right>
  2.3  Postorder  <left> <right> <root>
*/


// time complexity = O(log(n))
// space complexity = O(log(n))
void bfs(Node* root){
	if (root == NULL) return;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		Node* current = q.front();
		q.pop();
		cout<<current->data<<"\n";
		if(current->left != NULL) q.push(current->left);
		if(current->right != NULL) q.push(current->right);
	}
}

//time complexity = O(n)
void preorder(Node* root){
	if(root == NULL) return;
	cout << root->data << "\n";
	preorder(root->left);
	preorder(root->right);
}

void inorder(Node *root){
	if(root == NULL) return ;
	inorder(root->left);
	cout << root->data << "\n";
	inorder(root->right);
}

void postorder(Node *root){
	if(root == NULL) return ;
	postorder(root->left);
	postorder(root->right);	
	cout << root->data << "\n";
	
}

int main(){
	
	// init root 
	Node* root = NULL;

	//  GIVEN TREE
	/*
	             5          level 0
		    / \         
		   3   7        level 1
		  / \
		 2   4          level 2
		/
	       1                level 3

	*/

	// HEIGHT  = 3
	// MIN = 1
	// MAX = 7
	// Preorder  Traversal =  5 3 2 1 4 7
	// Inorder   Traversal =  1 2 3 4 5 7
	// Postorder Traversal =  1 2 4 3 7 5

	//insert data
	root = insert(root,5);
	root = insert(root,7);
	root = insert(root,3);
	root = insert(root,2);
	root = insert(root,4);
	root = insert(root,1);
	//find height
	cout<< "height is : " <<height(root) << "\n";
	//find min data in the bst tree
	cout<< "min data is : " << findMin(root) << "\n";
	//find max data in the bst tree
	cout<< "max data is : " <<findMax(root) << "\n";
	// preorder traversal 
	cout<< "preorder traversal : " << "\n";
	preorder(root);
    // inorder traversal 
	cout<< "inorder traversal : " << "\n";
	inorder(root);
	// postorder traversal 
	cout<< "postorder traversal : " << "\n";
	postorder(root);

}
