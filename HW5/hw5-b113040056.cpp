#include <iostream>

using namespace std;

class Poly;
class Node
{
    friend class Poly;

    friend ostream& operator<<(ostream& outputStream, Poly& obj); // Allow operator<< to access private members
    friend Poly operator+(Poly& a, Poly& b); // Allow this function to access operator + 
    private: 
    int coef;
    int exp;
    Node *next;
};

class Poly
{
    // insert a monomial
    void insert(int coef, int exp); 

    // find the node with certain exponent
    Node* findNodewithExp(int exp);

    void formatPoly(Poly& obj);

    // opearator overloading + 
    friend Poly operator+(Poly& a, Poly& b);

    // operator overloading input stream
    friend istream& operator>>(istream& inputStream, Poly& obj);

    // operator overloading input stream
    friend ostream& operator<<(ostream& outputStream, Poly& obj);


    private:
    Node *head = NULL; // head of a polynomial linked list (leftmost)
    Node *tail = NULL; // tail of a polynomial linked list (rightmost)
    int exponent[10000] = {0}; // for mapping exponent
    int polyCount  = 0; // total of monomial in the Polynomial 

};

int main(void)
{
    Poly A, B, C, D;
    cin >> A;
    cin >> B;

    cout << "OUTPUT \n"; 
    cout << A;
    cout << B;

    cout << "ADD" << endl;
    C = A + B;
    cout << C << endl;
    
    cout << "MULTIPLY" << endl;
    D = A * B;
    cout << D << endl;
    return 0;
}

void Poly::insert(int coef, int exp)
{
    // check if already have the exponent n in the polynomial
    // to not create a new node in a polynomial
    if (exponent[exp] == 1)
    {
        findNodewithExp(exp)->coef += coef;
        return;
    }
    else
    {
        exponent[exp] = 1;
        
    }
    
    
    // fill the data of a newNode 
    Node* newNode = new Node;
    newNode->coef  = coef;
    newNode->exp = exp;
    newNode->next = NULL;

    exponent[exp] = 1;

    // 2 cases, empty or not empty
    // empty
    if (head == NULL)
    {   // both head and tail point to newNode
        head = tail = newNode;
    }
    else
    {   // insert from tail
        tail->next = newNode;
        tail = newNode;
    }
    // insert into the linked list

}   

Node * Poly::findNodewithExp(int exp)
{
    Node* tempFind = head;
    while(true)
    {
        if(tempFind->exp == exp)
            break;
        tempFind = tempFind->next;
    }
    return tempFind;
}

void Poly::formatPoly(Poly& obj)
{
    // check if Poly is empty
    if (obj.head == NULL)
        return;
    
    // remove node with coefficent of 0 
    Node *checkZeroNode = obj.head;

    // remove the 0 coeffient from the second to last
    while(checkZeroNode)
    {   
        //cout << "zero 1" << endl;
        Node *nextNode = checkZeroNode->next;
        if (nextNode)
        {
            //cout << "zero 2" << endl;
            // remove a node 
            if(nextNode->coef == 0)
            {
                Node * freeNode = nextNode;
                nextNode = nextNode->next;
                delete freeNode;

                // connect the left node with the right node
                checkZeroNode->next = nextNode;
            }

        }

        checkZeroNode = checkZeroNode->next;
        //cout << "checkZero Loop"<< endl;
    }

    // check if the first node is 0 coeficient
    if(obj.head->coef == 0)
    {
        Node * freeNode = obj.head;
        obj.head = obj.head->next;
        delete freeNode;
    }

    // sort based on the exponent


}


Poly operator+(Poly& a, Poly& b)
{   
    Poly C;

    // insert all monomial in poly a and b into 1 poly
    Node* tempA = a.head;
    Node* tempB = b.head;
    while(tempA)
    {
        C.insert(tempA->coef, tempA->exp);
        tempA = tempA->next;
    }
    while(tempB)
    {
        C.insert(tempB->coef, tempB->exp);
        tempB = tempB->next;
    }


    return C;
}

istream& operator >> (istream& inputStream, Poly& obj)
{   
        cin >> obj.polyCount;
    
        while(obj.polyCount--)
        {
            int tempCoef, tempExp;
            cin >> tempCoef >>tempExp;

            // insert into the head linked list
            obj.insert(tempCoef, tempExp);
            //cout << "masuk" << tempCoef << " " << tempExp;
        }
    
        return inputStream;
}

ostream& operator<<(ostream& outputStream, Poly& obj)
{

    obj.formatPoly(obj);

    // check the result
    if (obj.head == NULL) // empty polynomial
    {
        cout << "0\n0" << endl;

    }
    else
    {
        Node *tempHead = obj.head;
        while(tempHead)
        {
            cout << tempHead->coef << " " << tempHead->exp << endl; 
            tempHead = tempHead->next;
        }
    }

    

    return outputStream;
}


