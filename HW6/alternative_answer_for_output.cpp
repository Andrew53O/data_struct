// Author: 洪理川 B113040056
// Date: Nov. 11 2023
// Purpose: Using tree to determine number that appear 2n+1 times
#include <iostream>
#include <vector>
using namespace std;

// forward declaration of tree class
class Tree;

class TreeNode 
{   
    friend class Tree; // to make TreeNode class can access Tree 
    public:

    // constructor
    TreeNode()
    {
        // intentionaly empty 
    }

    // constructor initialization
    TreeNode(int n) : data(n) {}
    private:

    int data; // data in the node
    TreeNode *leftChild = NULL; // leftchild pointer
    TreeNode *rightChild = NULL; // righchild pointer
};

class Tree 
{   
    public:

    // insert node into tree
    void insert(int n) {
        // using root member variable as default
        insertHelper(n, root);
    }

    // delete a n value of node
    TreeNode* Delete(int n, TreeNode* root);

    // Traversal that gives values of nodes in sorted order
    void inorderTraversal()
    {
        // formatted output
        cout << "node: "; 
        // function to keep root private 
        inorderTraversalHelper(root);
        cout << endl;

        cout << "left: ";
        for (int i = 0; i < left.size(); i++)
            cout << left[i] << " ";

        cout << endl;

        cout << "right: ";
        for (int i = 0; i < right.size(); i++)
            cout << right[i] << " ";
    }
    private: 

    TreeNode *root = NULL; // root node 
    vector<int> left, right;  // vector to save left and right node

    // helper for insert function to use root member variable
    void insertHelper(int n, TreeNode*& root);

    // helper for Traversal using root member variable
    void inorderTraversalHelper(TreeNode* root);
};

int main(void)
{
    int n; // n value for node
    bool firstTime = true; 
    while (true)
    {
        Tree A;
        while (cin >> n)
        {
            // terminate condition
            if (n == -1)
                break;

            A.insert(n);
        }

        // terminate program (eof)
        if (cin.eof())
            break;
        else
        {
            // only output the space between cases (exclude first and last case)
            if(!firstTime)
                cout << endl;
        }
        
        // output node: right: left: 
        A.inorderTraversal();

        firstTime = false; // for detecting the first time
        cout << endl;
    } 
    return 0;
}

void Tree::insertHelper(int n,  TreeNode*& root)
{
    // terminate condition
    if (n == -1)
        return;

    // Inseerting a Node to the tree
    if (root == NULL)
    {
        TreeNode * newNode = new TreeNode(n);
        root = newNode;
        return;
    }
    // if the root data is bigger than inserted node, find position in the left subtree
    else if (root->data > n)
    {
        insertHelper(n, root->leftChild);
    }
    // if the root data is bigger than inserted node, find position in the right subtree
    else if (root->data < n)
    {
        insertHelper(n, root->rightChild);
    }
    else // inserted data same as root 
    {
        // delete the node
        root = Delete(n, root);
    }
    return;
}

TreeNode* Tree::Delete(int n, TreeNode* root)
{
    // corner case
    if (root == NULL) return root; 
    // find in left subtree
    else if (root->data > n) root->leftChild = Delete(n, root->leftChild); 
    // find in the right subtree
    else if (root->data < n) root->rightChild = Delete(n, root->rightChild);
    else 
    {
        // Found the node
        // case 1: leaf node
        if (root->leftChild == NULL && root->rightChild == NULL)
        {
            delete root;
            root = NULL;
        }
        // case 2.1 right child 
        else if (root->leftChild == NULL)
        {
            TreeNode * temp = root;
            root = root->rightChild;
            delete temp;

        }
        // case 2.2 left child
        else if (root->rightChild == NULL)
        {
            TreeNode* temp = root;
            root = root->leftChild;
            delete temp;
        }
        // case 3: two child
        else
        {   
            // Find the inorder successor (smallest in the right subtree)
            TreeNode * temp = root->rightChild; // first go to the right subtree

            // Finding inorder successor 
            while(temp->leftChild != NULL)
            {
                // keep going left until doesn't have left child
                temp = temp->leftChild;
            }

            // change the root data with the inorder success data
            root->data = temp->data;

            // delete the inorder successor node
            root->rightChild = Delete(temp->data, root->rightChild);
        }
    }

    return root; // return current node value to be assign (cause using recursive)
}

void Tree::inorderTraversalHelper(TreeNode* root)
{
    if (root == NULL)
        return;
    
    // keep going to the right until reach the end
    inorderTraversalHelper(root->leftChild);

    // output the node 
    cout << root->data << " ";
    
    // save the value of left child 
    if (root->leftChild == NULL) left.push_back(0);
    else left.push_back(root->leftChild->data);

    // save the value of right child
    if (root->rightChild == NULL) right.push_back(0);
    else right.push_back(root->rightChild->data);

    // go to the right of it's node (bigger)
    inorderTraversalHelper(root->rightChild);
}   