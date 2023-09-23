#include <iostream>
#include <string.h>
using namespace std;

// global prototypes
int countFilledLength(const char arr[]);
void sortArrayBasedOnASCII(char arr[]);
void removeDuplicateCharacter(char arr[]);

class Set 
{   
    public:

    Set();

    // input output operator overloading
    friend istream& operator >>(istream& inputStream, Set& ASet);

    // formatted output sorting with ASCII included
    friend ostream& operator <<(ostream& outputStream, Set& ASet);
    
    // using member function copy only arr[256]
    Set& operator=(const Set& ASet);
    
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
        Set C;

        C = A;

        cout << "cout C = " << C;
    }
}



Set::Set()
{
    for (int i = 0; i < 256; i++)
    {
        arr[i] = '\0';
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
    
    sortArrayBasedOnASCII(ASet.arr);
    cout << countFilledLength(ASet.arr) << "??" << strlen(ASet.arr);
    // remove duplicate
    removeDuplicateCharacter(ASet.arr);
    cout << countFilledLength(ASet.arr) << "??" << strlen(ASet.arr);

    return inputStream;
}

ostream& operator <<(ostream& outputStream, Set& ASet)
{
    cout << "{";
    
    for (int i = 0; i < countFilledLength(ASet.arr); i++)
    {
        cout << ASet.arr[i]; 
    }
    cout << "}";
    return outputStream;
}


Set& Set::operator=(const Set& ASet)
{
    int arrayLength = countFilledLength(ASet.arr);
    cout << "lengthnya adalah" << arrayLength << endl;

    for (int i = 0; i < arrayLength; i++)
    {
        this->arr[i] = ASet.arr[i];
    }
    this->arr[arrayLength] = '\0';

    return *this;
}


int countFilledLength(const char arr[])
{
    int length = 0;

    while(arr[length] != '\0')
    {
        length++;
    }

    return length;
}

void sortArrayBasedOnASCII(char arr[])
{
    // using bubble sort to sort based on ASCII values
    for (int i = 0; i < countFilledLength(arr); i++)
    {
        for (int j = i + 1; j < countFilledLength(arr); j++)
        {
            if (arr[i] > arr[j])
            {
                char temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp; 
            }
        }

    }
    arr[countFilledLength(arr)] = '\0';
}

void removeDuplicateCharacter(char arr[])
{
    int arrayLength = countFilledLength(arr);

    char *tempArray = new char[arrayLength];
    if (tempArray == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        return; // Handle memory allocation failure
    }


    // initialize tempArray
    for (int i = 0; i < arrayLength; i++)
    {
        tempArray[i] = '\0';
    }

    int tempArrayIndex = 0;
    bool isDuplicate = false;

    for (int i = 0; i < arrayLength; i++)
    {   
        isDuplicate = false;

        // because it is sorted we can assign j = i + 1
        for (int j = i + 1; j < arrayLength - 1; j++)
        {
            if (arr[i] == arr[j])
            {
                isDuplicate = true;
                break;
            }   
        }

        if (isDuplicate == false)
        {
            tempArray[tempArrayIndex] = arr[i];
            tempArrayIndex++;
        }
    }

    // copy the temporary to the array
    for (int i = 0; i < tempArrayIndex; i++)
    {
        arr[i] = tempArray[i];

    }
    // add null terminator
    arr[tempArrayIndex] = '\0';

    delete[] tempArray;
}


// to do 
// 1. create '=' operator
// 2. test the + operator
// 3. continue finish all of the operator