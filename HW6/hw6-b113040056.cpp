#include <iostream>
using namespace std;

class Tree;

class TreeNode 
{   
    friend class Tree; // to make TreeNode class can access Tree 
    public:

    // constructor
    TreeNode()
    {
        // intentionaly empty ;
    }

    TreeNode(int n)
    {
        data  = n;
        leftChild = NULL;
        rightChild = NULL;
    }       
    

    private:

    int data;
    TreeNode *leftChild = NULL;
    TreeNode *rightChild = NULL;
};

class Tree 
{   
    public:

    void insert(int n) {
        // using root member variable as default
        insertHelper(n, root);
    }

    TreeNode* Delete(int n, TreeNode* root);

    TreeNode* getRoot() {return root;}

    int getRootData() {
        
        if (root == NULL)
        {
            cout << "why the root is still null" << endl;
            return -1;
        }
        
        return root->data;}
    int getRootLeftData() {return root->leftChild->data;}
    int getRootRightData() {return root->rightChild->data;}
    int getTemp() {return root->leftChild->rightChild->data;}
    private: 
    TreeNode *root = NULL;

    // helper for insert function 
    void insertHelper(int n, TreeNode*& node);
};

int main(void)
{
    // while masi jalan
        // while ga null ? 
    Tree A;
    A.insert(3);
     
    A.insert(3);

    A.insert(5);

   
    A.insert(9);
    A.insert(5);
    A.insert(3);
    A.insert(4);
    A.insert(8);
    A.insert(5);
    A.insert(3);
    A.insert(10);
    A.insert(10);
    A.insert(8);

    cout << A.getRootData() << endl;
    cout << A.getRootLeftData() << endl;
    cout << A.getTemp() << endl;
    return 0;
}

void Tree::insertHelper(int n,  TreeNode*& root)
{
    // terminate condition
    if (n == -1)
        return;
    
    // initialization of root
    if (root == NULL)
    {
        TreeNode * newNode = new TreeNode(n);
        root = newNode;
        return;
    }
    else if (root->data > n)
    {
        insertHelper(n, root->leftChild);
    }
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
    else if (root->data > n) root->leftChild = Delete(n, root->leftChild); 
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

            // Finding inorder successor algorithm
            while(temp->leftChild != NULL)
            {
                temp = temp->leftChild;
            }

            // change the root data with the inorder success data
            root->data = temp->data;

            // delete the inorder successor node
            root->rightChild = Delete(temp->data, root->rightChild);
        }

       
    }

    return root;
}