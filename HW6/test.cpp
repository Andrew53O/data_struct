/*
	Author: Steven Rhenaldy
	Date: Des. 10 2021
	Purpose: An application of tree searching (Assignment #6)
*/
#include <iostream>

using namespace std;

// 	Using template class
template <class T> class Tree;

//	Tree Node class
template <class T>
class TreeNode{
//	Friend class with Tree so Tree class can access private properties of TreeNode
	friend class Tree <T>;
	private:
//		Store the data
		T data;
//		Store the left child pointer
		TreeNode <T> *leftChild;
//		Store the right child pointer
		TreeNode <T> *rightChild;
	public:
//		Class constructor
		TreeNode(T d){
//			Save the passed data to class' data
			data = d;
//			Set both child pointers to NULL
			leftChild = NULL;
			rightChild = NULL;
		}
};

//	Tree class
template <class T>
class Tree{
	private:
//		Store the location of the root node
		TreeNode <T> *root;
	public:
//		Class constructor
		Tree(){
//			Set the root location to NULL
			root = NULL;
		}
		
//		Get the inorder successor number (the far left node of the right child)
		T inorderSuccessorNum(TreeNode<T>* root){
//			Set the root as current location
			TreeNode<T>* current = root;
//			Get the far left node of the tree
			while(current && current->leftChild){
//				If the tree still have a left child, then move the pointer to the left child
				current = current->leftChild;
			}
//			Return the data of the far-left child
			return current->data;
		}
		
//		Delete the node
		TreeNode<T>* deleteNode(TreeNode<T>* curr, T d, bool &deleted){
			if(curr == NULL){
//				If the current node is NULL, then return null
				return NULL;
			}else if(curr->data > d){
//				If the data is smaller then the data inside the current tree, recursively pass the left child pointer of the tree
				curr->leftChild = deleteNode(curr->leftChild, d, deleted);
			}else if(curr->data < d){
//				If the data is larger then the data inside the current tree, recursively pass the right child pointer of the tree
				curr->rightChild = deleteNode(curr->rightChild, d, deleted);
			}else{
//				If the data is equal to the data inside the tree
				if(!curr->leftChild && !curr->rightChild){
//					If the tree has no left and right child
//					Delete the current node
					delete curr;
//					Set the pointer of the parrent to NULL
					curr = NULL;
//					Set the deleted boolean to true
					deleted = true;
				}else if(!curr->leftChild){
//					If the tree has only left child
//					Set the temp to the current pointer
					TreeNode<T>* temp = curr;
//					Set the current pointer to the right child of the tree
					curr = curr->rightChild;
//					Delete the temp node
					delete temp;
//					Set the deleted boolean to true
					deleted = true;
				}else if(!curr->rightChild){
//					If the tree has only right child
//					Set the temp to the current pointer					
					TreeNode<T>* temp = curr;
//					Set the current pointer to the left child of the tree
					curr = curr->leftChild;
//					Delete the temp node					
					delete temp;
//					Set the deleted boolean to true		
					deleted = true;
				}else{
//					If the tree has two child-pointers
//					Get the value of the inorder successor number for that tree
					T min = inorderSuccessorNum(curr->rightChild);
//					Delete the inorder successor number of the right child tree
					curr->rightChild = deleteNode(curr->rightChild, min, deleted);
//					Set the current tree data to the number from the inorder successor
					curr->data = min;
				}
						
			}
//			Return current pointer
			return curr;
		}
		
//		Inserting Recursive function
		void insert_rec(TreeNode<T>* curr, T d){
//			Create a new node pointer
			TreeNode <T> *newNode = new TreeNode<T>(d);
//			If the root pointer value is NULL (The tree is empty)
			if(!root){
//				Place the new node into root
				root = newNode;
				return;
			}
//			If current tree data is higher than the passed data
			if((int)curr->data > d){
//				If the tree has no left child
				if(!curr->leftChild){
//					set the new node after the tree's left child pointer
					curr->leftChild = newNode;
					return;
				}
//				Else, recursively move to the next left child
				insert_rec(curr->leftChild, d);
			}else{
//			If current tree data is lower than the passed data				
				if(!curr->rightChild){
//					set the new node after the tree's right child pointer
					curr->rightChild = newNode;
					return;
				}
//				Else, recursively move to the next right child
				insert_rec(curr->rightChild, d);
			}
			return;
		}
		
//		Inserting (processor) number function
		void insert(T data){
//			Create a boolean variable called deleted to check wether the delete function can find the node with the same value
			bool deleted = false;
//			Try to delete the node
			root = deleteNode(root, data, deleted);
			
			if(!deleted){
//				If nothing has deleted,
//				Insert the number to the tree 
				insert_rec(root, data);
			}
			
			return;
		}
	
//		In Order recursive function
		void inOrder(TreeNode<T>* curr, char setting){
//			Set the setting to 'l' to get the left child value,
//			Set the setting to 'n' to get the (now/current) root value, 
//			Set the setting to 'r' to get the right child value

//			if the current pointer is equal to NULL, return the function
			if(!curr){
				return;
			}
			
//			Recursively call the left child 
			inOrder(curr->leftChild, setting);
			
			if(setting == 'n'){
//				Print the current tree data if the setting is equal to 'n'
				cout<<curr->data<<" ";
			}else if(setting == 'l'){
				if(curr->leftChild){
//				Print the left child data of the tree if it is exist
					cout<<curr->leftChild->data<<" ";
				}else{
//					Print 0 if not exist
					cout<<0<<" ";
				}
			}else if(setting == 'r'){
//				Print the left child data of the tree if it is exist
				if(curr->rightChild){
					cout<<curr->rightChild->data<<" ";
				}else{
//					Print 0 if not exist
					cout<<0<<" ";
				}
			}
//			Recursively call the right child 
			inOrder(curr->rightChild, setting);
		}
		
//		Print function
		void print(){
//			Print the node
			cout<<"Node: ";
			inOrder(root, 'n');
			cout<<endl;
//			Print the left child
			cout<<"Left: ";
			inOrder(root, 'l');
			cout<<endl;
//			Print the right child
			cout<<"Right: ";
			inOrder(root, 'r');
			
			return;
		}
		
//		Recursively destruct the class
		void destruct(TreeNode<T>* curr){
//			Implement postfix algorithm to delete every nodes
			if(!curr){
				return;
			}
			destruct(curr->leftChild);
			destruct(curr->rightChild);
			delete curr;
		}
		
//		Class destructor
		~Tree(){
//			Call the destruct function
			destruct(root);
		}
};

//	Main Function
int main(void){
//	Create an input number variable
	int num;
//	Create a tree pointer
	Tree <int>* tree = NULL;
//	While the input is not EOF, recieve the input
	while(cin>>num){
//		If the tree is equal to NULL, create a new Tree class
		if(tree == NULL){
			tree = new Tree<int>;
		}
//		While the input is not -1, insert the number into the tree
		if(num != -1){
				tree->insert(num);
				continue;
		}
//		If the input is equal to -1, 
//		print the tree
		tree->print();
		cout<<endl;
		
//		Delete the tree class and set the pointer to NULL
		delete tree;
		tree = NULL;
		num = 0;
	}
	
	return 0;
}
