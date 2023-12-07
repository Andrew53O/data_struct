// Author: 洪理川 B113040056
// Date: Dec. 05 2023
// Purpose: Implementation of a compression software with Huffman algorithm
#include <iostream>
#include <fstream> 
#include <vector>
#include <algorithm> // sort()
#include <utility> // pair<>
#include <unordered_map> // unordered_map
#include <string>
#include <map>
#include <string>
#include <sstream>
using namespace std;

struct Node 
{
    string ch;
    int freq;
    Node* left; 
    Node* right;

    // Constructor
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
    }
};

class huffman_Tree {
    public: 
    Node* root;
    unordered_map<string, string> huffmanCode;
    string originalString = "";

    void encode(const Node* root, string str, unordered_map<string, string> &huffmanCode)
    {
        if (root == nullptr)
            return;

        // found a leaf node
        if (root->left == NULL && root->right == NULL) {
            huffmanCode[root->ch] = str;
        }

        encode(root->left, str + "0", huffmanCode);
        encode(root->right, str + "1", huffmanCode);
    }

    void decode(Node* root, int &index, string str, ofstream& outputFile)
    {
        if (root == nullptr) {
            return;
        }

        // found a leaf node
        if (root->left == NULL && root->right == NULL)
        {
            outputFile << root->ch;
            return;
        }

        index++;

        if (str[index] =='0')
            decode(root->left, index, str, outputFile);
        else
            decode(root->right, index, str, outputFile);
    }


};

unordered_map<char, int> huffman; 

void encodeAFile(ifstream& inputFile, ofstream& outputFile);
void decodeAFile(ifstream& inputFile, ofstream& outputFile);
bool compare(const Node*  a, const Node* b);

int main(int argc, char *argv[])
{
    ifstream inputFile;
    ofstream outputFile;
    string name, filename, extension;
    // checking argument line 
    if (argc != 6)
    {
        cout << "Please input 6 arguments command line, Ex: huffman –c –i infile.txt –o outfile.txt" << endl;
        return -1;
    }
    else
    {   
        // check for the first parameter
        if (string(argv[1]) != "-c" && string(argv[1]) != "-u")
        {
            cout << "Please input correct first parameter"<< endl;
           
            return -1;
        }
        else
        {
            if (string(argv[2]) != "-i" || string(argv[4]) != "-o")
            {
                cout << "Please input correct second & fourth parameter" << endl;
                return -1;
            }
            else
            {

                inputFile.open(argv[3], ios::binary);
                if (!inputFile.is_open())
                {
                    cout << "Cannot open the input file" << endl;
                    return -1;
                }

                // huffman –c –i infile –o outfile
                outputFile.open(argv[5], ios::binary);
                if(!outputFile.is_open())
                {
                    cout << "Cannot open the output file" << endl;
                    return -1;
                }
                filename = string(argv[5]);
                name = filename.substr(0, filename.find_last_of("."));
                extension = filename.substr(filename.find_last_of(".") + 1);    
            }
        }
    }

    if (string(argv[1]) == "-c")
    {
        encodeAFile(inputFile, outputFile);
    }
    else if (string(argv[1]) == "-u")
    {
        decodeAFile(inputFile, outputFile);
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

void encodeAFile(ifstream& inputFile, ofstream& outputFile)
{
    
    huffman_Tree HF;
    char c;
    int totalBits = 0;
    // read every character and put it in the vector using unordered_map 
    // to increment the count of a character in a constant time
    while(inputFile.get(c)) 
    {   
        if(c == '\n') continue;
        if(huffman.count(c)) 
        {
            huffman[c]++;
            HF.originalString += c;
        }
        else 
        {
            huffman[c] = 1;
            HF.originalString += c;
        }
        totalBits++;
       
    }

    // Create a vector of pointers to nodes
    std::vector<Node*> node_vector;
    for (const pair<char, int> &pair : huffman) {
        node_vector.push_back(new Node(pair.first, pair.second));
    }

    // Sort the node_vector based on frequency
    std::sort(node_vector.begin(), node_vector.end(), compare);

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
        sort(node_vector.begin(), node_vector.end(), compare);

        // for ( Node* v : node_vector) {
        //     cout << v->ch << " :" << v->freq << endl;
        // }
        HF.root = temp;
    }

    // encode the inputFile
    HF.encode(HF.root, "", HF.huffmanCode);

    // make the map ordered alphabetical 
    map<string, string> sorted_huffmanCode(HF.huffmanCode.begin(), HF.huffmanCode.end());

    // Encoded the string
    string str = "";
    for (char ch: HF.originalString ) {
        str += HF.huffmanCode[string(1, ch)];
    }

    // Output 
    long long int beforeSize;
    double afterSize, ratio; 
    beforeSize = totalBits;
    totalBits *= 8;
    afterSize = str.size() / 8.0;

    cout << "----------ENCODING A FILE----------" << endl;
    cout << "Before Compressing Size : " << totalBits << " bits  " << beforeSize <<  "bytes" << endl;
    cout << "After Compressing Size  : "<< str.size() << " bits  "<< afterSize << " bytes" << endl;
    cout << "Compression Ratio : " << (afterSize/beforeSize) * 100 << "%" << endl;
    cout  << "Encoding table: " << endl;


    outputFile << "Before Compressing Size : " << totalBits << " bits  " << beforeSize <<  "bytes" << endl;
    outputFile << "After Compressing Size  : "<< str.size() << " bits  "<< afterSize << " bytes" << endl;
    outputFile << "Compression Ratio : " << (afterSize/beforeSize) * 100 << "%" << endl;
    outputFile << "Encoding table: "<< endl;
    
    // output the table
    for (const auto &pair : sorted_huffmanCode) {
        cout << pair.first << "=" << pair.second << '\n';
        outputFile << pair.first << "=" << pair.second << '\n';
    }

    //string DataOnlyFileName = name + "DataOnly." + extension;  
    //ofstream compressedDataOnly(DataOnlyFileName, ios::binary);
    outputFile <<"Compressed File: "<< endl;
    outputFile << str << endl; // only print for the output file
    //compressedDataOnly << str;     
}

void decodeAFile(ifstream& inputFile, ofstream& outputFile)
{
    // hashing for encoding table
    unordered_map<string, string> encodingTable;

    string line;
    string comData;
    bool startReadTable = false;
    bool startReadData = false;
    while(getline(inputFile, line))
    {   
        if (line == "Encoding table: ")
        {
            startReadTable = true;
            continue;
        }

        if (line == "Compressed File: ")
        {
            startReadData = true;
            continue;
        }

        if(startReadTable&& startReadData == false)
        {
            // fill the encoding table
            istringstream iss(line);
            string character, zeroOne;
            getline(iss, character, '=');
            getline(iss, zeroOne);
            
            // insert the pair into map
            encodingTable.insert({zeroOne, character});
        }

        if (startReadData == true) // Found the compress data
        {
            comData = line;
        }
    }

    string Res_decompressData = "";
    string temp = "";
    for (int i = 0; i < comData.length(); i++)
    {
        temp += comData.at(i);
        if (encodingTable.find(temp) != encodingTable.end()) // Found the key
        { 
            Res_decompressData += (encodingTable.find(temp))->second;

            temp = "";
        }

    }

    cout << Res_decompressData << endl;
    outputFile << Res_decompressData << endl;
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