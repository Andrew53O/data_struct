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
    Node (string ch, int freq, Node*left = NULL, Node* right = NULL)
        : ch(ch), freq(freq), left(left), right(right) {}

};

class huffman_Tree {
    public: 
    
    Node *insertTwoNode(string c1, int f1, string c2, int f2)
    {
        Node* subRoot = new Node; // sub root pointer

        // create a new node for c1 f1
        Node* left = new Node;
        left->ch = c2;
        left->freq = f2;
        left->left = NULL;
        left->right = NULL;

        // create a new node for c2 f2
        Node* right = new Node;
        right->ch = c1;
        right->freq = f1;
        right->left = NULL;
        right->right = NULL;

        // connect left and right node

        // get the less lexical order in the front
        if (c1 > c2)
        {
            subRoot->ch = c2 + c1;
        }
        else   
            subRoot->ch = c1 + c2;
        
        subRoot->freq = f1 + f2;
        subRoot->left = left;
        subRoot->right = right;

        return subRoot;
    }

    Node* root;

};

unordered_map<char, int> huffman; 

bool compare (const pair<char, int>&  a, const pair<char, int>& b);

int main(int argc, char *argv[])
{

    ifstream inputFile;

    inputFile.open("media/text.txt", ios::binary);

    if (inputFile.is_open())
    {
        // how to print all of the data from a file
        // std::string data((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
        // std::cout << data;

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


        cout << endl; 
        // created the tree
        huffman_Tree hf;
        Node* root;
        while(huffman_vector.size() > 1)
        {
            // sort based on the frequencry and lexical order
            sort(huffman_vector.begin(), huffman_vector.end(), compare);

            for (const pair<char, int> &pair : huffman_vector) {
                cout << pair.first << ": " << pair.second << std::endl;
            }
            

            Node* temp;
            pair <char,int> test1 = huffman_vector.back(); huffman_vector.pop_back();
            pair <char,int> test2 = huffman_vector.back();  huffman_vector.pop_back();
            
            temp = hf.insertTwoNode(string(1, test1.first), test1.second, string(1, test2.first), test2.second);

                // insert the temp data and value
            huffman_vector.push_back(make_pair((temp->ch).at(0),temp->freq));

            cout << "temp " << temp->ch << endl;
            cout << "left" << temp->left->ch << endl;
            cout << "right" << temp->right->ch << endl;

            root = temp;
        }

        for (const pair<char, int> &pair : huffman_vector) {
                cout << pair.first << ": " << pair.second << std::endl;
            }
        cout << "berhasil kah?" << endl;
        cout << root->ch << endl;

        cout << root->left->ch << endl;
        cout << root->right->ch << endl;
        
        // assign every value to every value 
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
bool compare(const pair<char, int>&  a, const pair<char, int>& b)
{
	if (a.second != b.second)
    {
        return a.second > b.second;
    }
    else   
        return a.first > b.first;
}