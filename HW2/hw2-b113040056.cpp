#include <iostream>
#include <string>
using namespace std;

// global prototypes
int countFilledLength(char arr[]);
void removeDuplicateCharacter(char arr[]);

class Set 
{   
    public:

    // input output operator overloading
    friend istream& operator >>(istream& inputStream, Set& ASet);

    // formatted output sorting with ASCII included
    friend ostream& operator <<(ostream& outputStream, Set& ASet);


    friend const Set operator +(const Set& ASet, const Set& BSet); 


    // = operator


    private:
    char arr[256];
    char findChar;

};



int main(void)
{

    int testCases;

    cin >> testCases;
    
    while (testCases--)
    {
        // clearing the input buffer
        fflush(stdin);
        Set A, B;
        int aCharacter;

        // input for set A and B
        cin >> A;
        cin >> B;

        // input for a single charater tested in set A or set B
        cin >> aCharacter;

        // all operations
        cout << A;
        cout << B;

    }
}

const Set operator +(const Set& ASet, const Set& BSet)
{

    return ASet;
}

istream& operator >>(istream& inputStream, Set& ASet)
{
    inputStream.getline(ASet.arr, sizeof(ASet.arr));

    cout << "arrnya " << ASet.arr << endl;

    // remove duplicate
    removeDuplicateCharacter(ASet.arr);

    return inputStream;
}

ostream& operator <<(ostream& outputStream, Set& ASet)
{
    cout << "arraynya adalah" << ASet.arr << endl;

    cout << sizeof(ASet.arr);
    // using bubble sort to sort based on ASCII values
    for (int i = 0; i < countFilledLength(ASet.arr); i++)
    {
        for (int j = i + 1; j < countFilledLength(ASet.arr); j++)
        {
            if (ASet.arr[i] > ASet.arr[j])
            {
                char temp = ASet.arr[i];
                ASet.arr[i] = ASet.arr[j];
                ASet.arr[j] = temp; 
            }
        }

    }
    ASet.arr[sizeof(ASet.arr) - 1] = '\0';
    cout << "{" << ASet.arr << "}" << endl;
    return outputStream;
}


int countFilledLength(char arr[])
{
    int length = 0;

    while(arr[length] != '\0')
    {
        length++;
    }

    return length;
}

vi

void removeDuplicateCharacter(char arr[])
{
    int arrayLength = countFilledLength(arr);

    int tempArray[arrayLength];

    for (int i = 0; i < arrayLength - 1; i++)
    {
        if (arr[])
    }

}


// to do 
// remove duplicate charater
// 1. create '=' operator
// 2. test the + operator
// 3. continue finish all of the operator