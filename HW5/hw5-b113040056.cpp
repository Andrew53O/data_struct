// Author: 洪理川 B113040056
// Date: Oct. 26 2023
// Purpose: Implement the addition and multiplication of two polynomials (linked list)

#include <iostream>
#include <algorithm>
using namespace std;

class Poly; // forward declaration of class Poly

// A node class
class Node
{
    public:
    friend class Poly; // Poly can access it's private elements

    friend ostream& operator<<(ostream& outputStream, Poly& obj); // Allow operator<< to access private members
    friend Poly operator+(Poly& a, Poly& b); // Allow this function to access operator + 
    friend Poly operator*(Poly&a, Poly& b); // Allow this * works in this class
    
    int getExp() {return exp;} // getter member function

    private: 
    int coef; // the coeffcient 
    int exp; // the exponent
    Node *next; // next node address
};

class Poly
{
    public:

    // Insert a monomial with operation of same exponent 
    void insert(int coef, int exp); 

    // Find the node with certain exponent
    Node* findNodewithExp(int exp);

    // Formatting the polynomial by removing the '0' coefficent and sorting based on the exponent (DESC)
    void formatPoly(Poly& obj);

    // overloaded operator that can operate + and * operation as usual polynomial
    friend Poly operator+(Poly& a, Poly& b);
    friend Poly operator*(Poly&a, Poly& b);

    // have input stream that fill up the polynomial
    friend istream& operator>>(istream& inputStream, Poly& obj);

    // output the pair coef - exp pair of the polynomial
    friend ostream& operator<<(ostream& outputStream, Poly& obj);

    // check the condition of the polynomial
    bool empty() {return (head == NULL) ? true : false;}
    
    private:
    Node *head = NULL; // head of a polynomial linked list (leftmost)
    Node *tail = NULL; // tail of a polynomial linked list (rightmost)
    int exponent[10000] = {0}; // for mapping exponent
    int polyCount  = 0; // total of monomial in the Polynomial 

};

int main(void)
{
    int num = 1; // for the # Case
    while(true)
    {
        // Polynomal class for input1, input2, ADD, MULTIPLY
        Poly A, B, C, D;
        cin >> A;
        cin >> B;

        // terminate the program if empty or input 0 0 
        if (A.empty() == true && B.empty() == true)
            return 0;

        // Output format
        cout << "Case" << num++<< ":" << endl; 
        cout << "ADD" << endl;
        C = A + B;
        cout << C;
        
        cout << "MULTIPLY" << endl;
        D = A * B;
        cout << D;
    }
    return 0;
}

// Insert a monomial with operation of same exponent 
void Poly::insert(int coef, int exp)
{
    // zero coefficient case
    if (coef == 0)
        return;

    // Check if already have the exponent n in the polynomial to not create a new node in a polynomial
    if (exponent[exp] == 1)
    {
        findNodewithExp(exp)->coef += coef;
        return;
    }
    else
    {
        exponent[exp] = 1;
    }
    
    // Fill the data of a newNode 
    Node* newNode = new Node;
    newNode->coef  = coef;
    newNode->exp = exp;
    newNode->next = NULL;
    
    // check if the first time input a Node
    if (head == NULL)
    {   // both head and tail point to newNode
        head = tail = newNode;
    }
    else // other operation
    {   
        // input from tail 
        tail->next = newNode;
        tail = newNode;
    }

}   

// Find the node pointer with certain exponent, 
// Must be used with linked list has the Exp  
Node* Poly::findNodewithExp(int exp)
{
    Node* tempFind = head; // temporary head
    while(true)
    {   
        // keep finding
        if(tempFind->exp == exp)
            break;
        
        // move to next node
        tempFind = tempFind->next;
    }
    return tempFind;
}

// Formatting the polynomial by removing the '0' coefficent and sorting based on the exponent (DESC)
void Poly::formatPoly(Poly& obj)
{
    // check if Poly is empty
    if (obj.head == NULL)
        return;
    
    // remove the 0 coeffient from the second to last
    Node *checkZeroNode = obj.head; // init Node from the first node

    while(checkZeroNode)
    {   
        Node *nextNode = checkZeroNode->next; // the node after the checkZeroNode
        if (nextNode)
        {
            // remove A node
            if(nextNode->coef == 0)
            {
                Node * freeNode = nextNode;
                nextNode = nextNode->next;
                delete freeNode;

                // connect the nodes
                checkZeroNode->next = nextNode;
            }
        }
        // move to next node
        checkZeroNode = checkZeroNode->next;
    }

    // check if the first node is 0 coeficient, since the second to last 0 coefficient is already filtered
    if(obj.head->coef == 0)
    {
        Node * freeNode = obj.head;
        obj.head = obj.head->next;
        delete freeNode;
    }

    // check if the polynomial have at least 2 elements
    if (obj.head != NULL && obj.head->next != NULL)
    {
        // sort based on the exponent using bubble sort
        for (Node* tempHead = obj.head; tempHead != NULL; tempHead = tempHead->next)
        {
            for (Node* tempHead2 = tempHead->next; tempHead2 != NULL; tempHead2 = tempHead2->next)
            {   
                // swap values of Node
                if (tempHead->exp < tempHead2->exp)
                {
                    int tempCoef = tempHead->coef;
                    int tempExp = tempHead->exp;

                    tempHead->coef = tempHead2->coef;
                    tempHead->exp = tempHead2->exp;

                    tempHead2->coef = tempCoef;
                    tempHead2->exp = tempExp;
                }
            }   
        }
    }
}

// adding polynomial in math
Poly operator+(Poly& a, Poly& b)
{   
    Poly C;

    // Merge 1 polynomial to 1
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

// multiplying polynomial in math
Poly operator*(Poly&a, Poly& b)
{
    Poly D;

    // check if whether one of the poly is zero or only contain 
    if (a.head == NULL || b.head == NULL)
    {
        return D;
    }

    Node * tempA = a.head;

    // Multiply polynomial like in math
    while(tempA)
    {
        Node * tempB = b.head;
        while(tempB)
        {
            D.insert(tempA->coef * tempB->coef, tempA->exp + tempB->exp);
            tempB = tempB->next;
        }
        tempA = tempA->next;
    }
    return D;   
} 

// have input stream that fill up the polynomial
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

// output the pair coef - exp pair of the polynomial
ostream& operator<<(ostream& outputStream, Poly& obj)
{
    // correctly format polynomial 
    obj.formatPoly(obj);

    // output the result if not an empty polynomial
    if (obj.head != NULL) 
    {
        Node *tempHead = obj.head;
        while(tempHead)
        {
            cout << tempHead->coef << " " << tempHead->exp << endl; 
            tempHead = tempHead->next;
        }
    }
    else
        cout << "0 0" << endl;

    return outputStream;
}


