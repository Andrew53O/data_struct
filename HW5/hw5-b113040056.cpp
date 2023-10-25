#include <iostream>

using namespace std;

class Poly;
class Node
{
    friend class Poly;

    friend ostream& operator<<(ostream& outputStream, Poly& obj); // Allow operator<< to access private members
    private: 
    int coef;
    int exp;
    Node *next;
};

class Poly
{

    void insert(int coef, int exp);
    // operator overloading input stream
    friend istream& operator>>(istream& inputStream, Poly& obj);

    // operator overloading input stream
    friend ostream& operator<<(ostream& outputStream, Poly& obj);
    private:
    Node *head = NULL; // head of a polynomial linked list
    int polyCount  = 0; // total of monomial in the Polynomial 

};

int main(void)
{
    Poly A;
    cin >> A;
    cout << A;
    return 0;
}

void Poly::insert(int coef, int exp)
{
    cout << "3";
    // fill the data of a newNode 
    Node* newNode = new Node;
    cout << "3.1";
    newNode->coef  = coef;
    cout << "3.2";
    newNode->exp = exp;
    cout << " 1";
    // insert into the linked list
    newNode->next = head;
    head = newNode;
    cout << " 2";
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
            cout << "masuk" << tempCoef << " " << tempExp;
        }
    
        return inputStream;
}

ostream& operator<<(ostream& outputStream, Poly& obj)
{
    cout << "dipslaying inside linked list" << endl;
    Node *tempHead = obj.head;
    while(tempHead)
    {
        cout << tempHead->coef << "x^" << tempHead->exp << " "; 
        tempHead = tempHead->next;
    }

    return outputStream;
}


