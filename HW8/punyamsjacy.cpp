//Jacyline Danielle
//B093040062
//10th December 2023
//Purpose : Use the Huffman algorithm to develop a software tool for data compression and decompression

#include <iostream>
#include <vector>
#include <cstring>
#include <fstream>
#include <bitset>
#include <algorithm>
#include <cstdio>

using namespace std;

template <class T>
class CharFreq;
template <class T>
class CharFreqNode;
template <class T>
class Huffman;
template <class T>
class HuffmanNode;

template <class T>  
class HuffmanNode{ //  
	private:
	    HuffmanNode<T> *left;  
	    HuffmanNode<T> *right; 
	    int weight;
	    int lexical;
	    T data;
	public:
		friend Huffman<T>;
		
		
	    HuffmanNode(HuffmanNode<T>* l, HuffmanNode<T>* r){
			left = l;
			right = r;
			data = NULL;
			weight = l->weight + r->weight;
			if(l->lexical < r->lexical){
				lexical = l->lexical; 
			}else{
				lexical = r->lexical;
			} 
			return;
		}
		
		HuffmanNode(T d, int w){
			left = NULL;
			right = NULL;
			data = d;
			weight = w;
			lexical = (int)d;
			return;
		}
		
		int compareTo(HuffmanNode<T>* node){
			if(weight < node->weight)
				return -1;
			if(weight == node->weight)
				return 0;
			if(weight > node->weight)
				return 1;
		}
		
		static bool compareFreq(HuffmanNode* a, HuffmanNode* b){
			return (a->weight<b->weight);
		}
		
		HuffmanNode* operator = (HuffmanNode node){
			HuffmanNode* n= new HuffmanNode;
			n->left = node.left;
			n->right = node.right;
			n->weight = node.weight;
			n->data = node.data;
			return n;
		}
};



template <class T>
class HuffmanDecode{
	private:
		class HuffmanCodeDecode{
			private:
				T data;
				string code;
			public:
				friend HuffmanDecode;
				 HuffmanCodeDecode(T d, string c){
				 	data = d;
				 	code = c;
				 }
		};
		vector < HuffmanCodeDecode > table;
	public:
		char getReal(string code){
			for(int i=0; i<table.size(); i++){
				if(code == table[i].code)
					return table[i].data;
			}
			return NULL;
		}
		HuffmanDecode(ifstream& stream, ofstream& streamout){
			string del;
			int fileSize;
		    getline(stream, del);
		    stream>>del;
		    stream>>fileSize;
		    getline(stream, del);
			string n;
			while(getline(stream, n)){
				
				if(n==""){
					break;
				}
				string afterEqual="";
				bool startCopy = 0;
				for(int i=0; i<n.length(); i++){
					if(n[i]== '='){
						startCopy = 1;
					}else if(startCopy)
						afterEqual+=n[i];
				}
//				cout<<n[0]<<" "<<afterEqual<<endl;
				table.push_back(HuffmanCodeDecode(n[0], afterEqual));
			
			}
			char getCode;
			
			char ch, counter = 7, x;
			int size = 0;
			unsigned char temp = 0;
			string subCode;
			int usable = fileSize/8;
			int leftover = fileSize%8-1;
//			cout<<leftover<<endl;
			int run=0;
			while(stream.get(ch)) {
				if(run==usable) counter = leftover;
//				cout<<(int)counter<<endl;
				while(counter > -1) {
//					
					subCode += (char)(( ch & (1<<counter) ) >> counter) + '0';
					ch ^= (1<<counter);
					--counter;
					char find = getReal(subCode);
					if(find) {
						streamout<<find;
						subCode = "";
					}
					
				}
				counter = 7;
				run++;
				
			}
		    stream.close();
		    streamout.close();
		}
		void output(ostream& out){
			
			for(int i=0; i<table.size(); i++){
				out<<table[i].data<<"="<<table[i].code<<endl; 
			}
			return;
		} 
};

template <class T>
class Huffman{
	private:
		class HuffmanCode{
			private:
				T data;
				string code;
			public:
				friend Huffman;
				 HuffmanCode(T d, string c){
				 	data = d;
				 	code = c;
				 }
		};
		HuffmanNode<T>* root;
		vector<HuffmanCode> table;
	public:
		
		void generateHuffmanCodes(HuffmanNode<T>* node, string code){
			
			if((!node->left && !node->right)  || node->data != NULL){
				table.push_back(HuffmanCode(node->data, code));
				return;
			}
			generateHuffmanCodes(node->left, code+'0');
			generateHuffmanCodes(node->right, code+'1');
			
		}
		
		Huffman(CharFreq<T> freq){
			vector< HuffmanNode<T>* > queue;
			
			for(int i=0; i<freq.list.size(); i++){
				queue.push_back(new HuffmanNode<T>(freq.list[i].data, freq.list[i].freq));
			}
			sort(queue.begin(), queue.end(), HuffmanNode<T>::compareFreq);
			
			while(queue.size()>1){
				HuffmanNode<T>* n1 = queue.front();
				queue.erase(queue.begin());
				HuffmanNode<T>* n2 = queue.front();
				queue.erase(queue.begin());
				if(n1->lexical < n2->lexical){
					queue.push_back(new HuffmanNode<T>(n1, n2));	
					
				}else{
					queue.push_back(new HuffmanNode<T>(n2, n1));
				}
								
				sort(queue.begin(), queue.end(), HuffmanNode<T>::compareFreq);
			}
			HuffmanNode<T>* root = queue.front();
			
			generateHuffmanCodes(root, "");
		}
		
		void output(ostream& out){
			
			for(int i=0; i<table.size(); i++){
				out<<table[i].data<<"="<<table[i].code<<endl; 
			}
			return;
		} 
		
		int getSize(string data){
			
			string bin;
			
			for(int i=0; i<data.length(); i++){
				for(int j = 0; j<table.size(); j++){
					if(data[i]==table[j].data){
						bin+=table[j].code;
						break;
					}
				}
			}
			
			return bin.length();
		}
		
		void toBinary(ostream& outputStream, string data){
			string bin;
			for(int i=0; i<data.length(); i++){
				for(int j = 0; j<table.size(); j++){
					if(data[i]==table[j].data){
						bin+=table[j].code;
						break;
					}
				}
			}
//			cout<<bin;
			int index = 0;
			unsigned char inch = 0;
			int length = data.length();
			for(int i=0; i<bin.length();i++){
				
				if(index == 8){
					outputStream<<inch;
					index = 0;
					inch = 0;
					
				}
				
				inch<<= 1;
				if(bin[i] == '1'){
					inch |= 1;
				}
				
				index++;
			} 
			if(inch){
				outputStream<<inch;
			}
			
			return;
		}
};

template <class T>
class CharFreqNode{
private:
    T data;
    int freq;

public:
	friend Huffman <T>;
    friend CharFreq<T>;
    CharFreqNode(T d, int freq){
        this->data = d;
        this->freq = freq;
        return;
    }
    
    bool compareFreq(CharFreqNode a, CharFreqNode b){
    	return (a.freq < b.freq);
	}
};

template <class T>
class CharFreq{
private:
    vector< CharFreqNode<T> > list;

public:
	friend Huffman<T>;
    void push(T data){
        int index = -1;
        for (int i = 0; i < list.size(); i++){
            if (list[i].data == data){
                index = i;
                break;;
            }
        }

        if (index != -1){
//            cout << data << " found, add by 1" << endl;
            list[index].freq++;
        }else{
//            cout << std::bitset<8>(data) << " Not found, create a new node" << endl;
            CharFreqNode<T> newNode(data, 1);
            list.push_back(newNode);
        }
        return;
    }
    void showFreq(){
        for (int i = 0; i < list.size(); i++){
        	cout<<list[i].data<<" "<<list[i].freq<<endl;
        }
    }
    
    
};


void compress(string inputFileName, string outputFileName){
    ifstream inputFile(inputFileName.c_str(), ios::binary);

    if (!inputFile){
        cout << "File not found!" << endl;
        return;
    }
    char *buffer;
    cout<<"File Found"<<endl;
	cout<<"Start compressing..."<<endl;

    inputFile.seekg(0, ios::end);
    int length = inputFile.tellg();
    inputFile.seekg(0, ios::beg);
    // allocate memory:
    buffer = new char[length];
    // read data as a block:
    inputFile.read(buffer, length);
    inputFile.close();
//    cout << length << endl;
    CharFreq<char> list;
    for (int i = 0; i < length; i++){
        list.push(buffer[i]);
    }
	Huffman<char> huff(list);
    
	
//	list.showFreq();
//	huff.output(cout);
	ofstream outputFile(outputFileName.c_str(), ios::out|ios::binary);
	if (!outputFile){
        cout << "Fail to create a new file!" << endl;
        return;
    }
    outputFile<<"Original: "<<length*8<<endl;
    outputFile<<"Compressed: "<<huff.getSize(buffer)<<endl;
    outputFile<<"Ratio: "<<(float)huff.getSize(buffer)/(float)length*8<<endl;
    huff.output(outputFile);
    outputFile<<endl;
	huff.toBinary(outputFile, buffer);
	outputFile.close();
	cout<<"Finish"<<endl;
	
    return;
}

void uncompress(string inputFileName, string outputFileName){
	ifstream inputFile(inputFileName.c_str(), ios::binary);

    if (!inputFile){
        cout << "File not found!" << endl;
        return;
    }
    cout<<"File Found"<<endl;
	cout<<"Start Uncompressing..."<<endl;
	ofstream outputFile(outputFileName.c_str(), ios::binary);
	if (!outputFile){
        cout << "Fail to create a new file!" << endl;
        return;
    }
	HuffmanDecode<char> decode(inputFile, outputFile);
	
	outputFile.close();
	cout<<"Finish"<<endl;
    return;
}

int main(int argc, char *argv[]){
	cout << "Jacyline Danielle" << endl;
			cout <<"B093040062"<<endl;
			cout << "10th December 2023" << endl;
			cout << "Purpose : Use the Huffman algorithm to develop a software tool for data compression and decompression" << endl<<endl;
    if (argc < 5){
        //if (argc == 2 && !strcmp(argv[1], "-h")){
        	if (argc == 2){
        	
			
            cout << "Arguments: " << endl;
            cout << "-c -i <input file> -o <output file>\tCompress" << endl;
            cout << "-u -i <input file> -o <output file> \tUncompress" << endl;
        }
        else{
            cout << "Input Error!" << endl;
        }
        return 0;
    }

    // op 0 compress
    // op 1 uncompress
    int op = -1;
    string inputFileName;
    string outputFileName;
    size_t found;

    for (int i = 0; i < argc; i++){
        if (!strcmp(argv[i], "-c"))
            op = 0;
        else if (!strcmp(argv[i], "-u"))
            op = 1;
        else if (!strcmp(argv[i], "-i")){
            inputFileName = argv[i + 1];
           
        }
        else if (!strcmp(argv[i], "-o")){
            outputFileName = argv[i + 1];
        }
    }

    switch (op){
    case 0:
        compress(inputFileName, outputFileName);
        break;
    case 1:
    	uncompress(inputFileName, outputFileName);
        break;
    default:
    	cout<<"Input Error!"<<endl;
    	break;
    }
		 
    
    return 0;
}
