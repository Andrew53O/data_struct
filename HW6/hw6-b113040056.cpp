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

    TreeNode* getRoot() {return root;}

    int getRootData() {
        
        if (root == NULL)
        {
            cout << "why the root is still null" << endl;
            return -1;
        }
        
        return root->data;}
    int getRootLeftData() {return root->leftChild->leftChild->data;}
    int getRootRightData() {return root->rightChild->rightChild->rightChild->data;}

    private: 
    TreeNode *root = NULL;

    // helper for 
    void insertHelper(int n, TreeNode*& node);
};

int main(void)
{
    // while masi jalan
        // while ga null ? 

    Tree A;
    A.insert(6);
    A.insert(7);
    A.insert(5);
    A.insert(10);
    A.insert(11);
    A.insert(1);

    cout << A.getRootData() << endl;
    cout << A.getRootLeftData() << endl;
    cout << A.getRootRightData() << endl;
    
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

    // find place in the right subtree
    if (root->data < n)
    {
        if (root->rightChild == NULL)
        {
            TreeNode * newNode = new TreeNode(n);
    
            root->rightChild= newNode;

            return;
        }
 
        insertHelper(n, root->rightChild);
    }

     // find place in the left subtree
    if (root->data > n)
    {
        if (root->leftChild == NULL)
        {
            TreeNode * newNode = new TreeNode(n);
            
            root->leftChild = newNode;
            return;
        }
        insertHelper(n, root->leftChild);
    }
    
    return;
}
