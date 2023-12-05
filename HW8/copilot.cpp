// Author: 洪理川 B113040056
// Date: Dec. 05 2023
// Purpose: Createing compress&uncompress software
#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm> // sort()
#include <utility> // pair<>
#include <unordered_map>
#include <string>
using namespace std;




struct Node 
{
    string ch;
    int freq;
    Node* left; 
    Node* right;

    // Constrcutor

    Node() {;}

    Node (char c, int f)
    {
        ch = c;
        freq = f;
        left = NULL;
        right = NULL;
    }
    Node (string ch, int freq, Node* left = NULL, Node* right = NULL)
    {
        // sort string alphabetical
        sort(ch.begin(), ch.end());

        // Now initialize the member variables
        this->ch = ch;
        this->freq = freq;
        this->left = left;
        this->right = right;

        cout << "udh kena sort" << endl;

        for (const char a: this->ch)
        {
            cout << a << " ";
        }
        cout << endl;
    }
};

class huffman_Tree {
    public: 

    Node* root;
    unordered_map<char, string> huffmanCode;


    void encode(Node* root, string str,
			unordered_map<char, string> &huffmanCode)
    {
        if (root == nullptr)
            return;

        // found a leaf node
        if (!root->left && !root->right) {
            huffmanCode[root->ch] = str;
        }

        encode(root->left, str + "0", huffmanCode);
        encode(root->right, str + "1", huffmanCode);
    }


};

unordered_map<char, int> huffman; 

bool compare(const Node*  a, const Node* b);

int main(int argc, char *argv[])
{

    ifstream inputFile;

    inputFile.open("media/textlong.txt", ios::binary);

    if (inputFile.is_open())
    {
        char c;
        // read every character and put it in the vector using unordered_map 
        // to increment the count of a character in a constant time
        while(inputFile.get(c)) 
        {
            if(c == '\n') continue;
            if(huffman.count(c)) huffman[c]++;
            else huffman[c] = 1;

        }

         // Copy key-value pairs from the map to the vector
        vector<pair<char, int>> huffman_vector(huffman.begin(), huffman.end());
        
        // Now vec is sorted by the map's value
        for (const pair<char, int> &pair : huffman_vector) {
            cout << pair.first << ": " << pair.second << std::endl;
        }

        // Create a vector of pointers to nodes
        std::vector<Node*> node_vector;
        for (const pair<char, int> &pair : huffman) {
            node_vector.push_back(new Node(pair.first, pair.second));
        }

        // Sort the node_vector based on frequency
        std::sort(node_vector.begin(), node_vector.end(), compare);

        Node* root = nullptr;

        // creating huffman tree
        while(node_vector.size() > 1)
        {
            // Take the two nodes with the smallest frequencies
            Node* node1 = node_vector.back(); node_vector.pop_back();
            Node* node2 = node_vector.back(); node_vector.pop_back();

            Node* leftNode; Node *rightNode;
            if (node1->ch.at(0) < node2->ch.at(0))
            {
                leftNode = node1;
                rightNode = node2;
            }
            else
            {
                leftNode = node2;
                rightNode = node1;
            }
            // Create a new node with these two nodes as children
            Node* temp = new Node(node1->ch + node2->ch, node1->freq + node2->freq, leftNode, rightNode); 

            // Insert the new node back into the vector
            node_vector.push_back(temp);

            // Sort the vector again
            std::sort(node_vector.begin(), node_vector.end(), compare);

            for ( Node* v : node_vector) {
                cout << v->ch << " :" << v->freq << endl;
            }
            root = temp;
        }


        // assign every value to every value 

        // encode
        
        // decode 
    }
    else
    {
        cout << "Unable to open the file" << endl;
    }

    return 0;
}

// function to sort based on the frequencty and lexical order
// because I want to pop from back it need to sort 
// high -> low frequency, less -> big lexical order
bool compare(const Node* a,const  Node* b)
{
     
	if (a->freq != b->freq )
    {
        return a->freq > b->freq;
    }
    else   
    {
        // compare for lexical order, biggest to smallest z y .. b a
        return (a->ch.at(0)) > (b->ch.at(0)); 
    }
        
}