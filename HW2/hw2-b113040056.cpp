// Author: 洪理川 B113040056
// Date: Sept. 23 2023
// Purpose: Using C++ to implement a Set class which provides some basic operations

#include <iostream>
#include <string.h>
using namespace std;

// global prototypes

// sort an array of based on it's ASCII values
void sortArrayBasedOnASCII(char arr[]);

// remove duplicate elements from an Array
void removeDuplicateCharacter(char arr[]);

// swap values using reference
void swap (char& a, char& b);

// defined a class called Set
class Set 
{   
    public:

    // constructor
    Set();

    // get a line from input and sort & remove duplicate
    friend istream& operator >>(istream& inputStream, Set& ASet);

    // formatted output sorting with ASCII included and removed duplicate
    friend ostream& operator <<(ostream& outputStream, Set& ASet);
    
    // copy arr[256]
    Set& operator=(const Set& ASet);
    
    // union of Set A and Set B
    friend const Set operator +( Set& ASet,  Set& BSet); 

    // intersection of Set A and Set B
    friend const Set operator *(Set& ASet, Set& BSet);

    // The difference of A and B
    friend const Set operator -(Set& ASet, Set& BSet);

    // find out if ASet contains BSet
    friend void operator >=(Set& ASet, Set& BSet);
    
    // find a character belongs to this Set
    void in(char x);

    private:
    // array for saving the set elements limit to 256 elements
    char arr[256];
};

int main(void)
{
    // variable for how much test Cases
    int testCases;

    // read input
    cin >> testCases;
    
    // looping testCases times
    while (testCases--)
    {
        // clearing the input buffer
        fflush(stdin);

        // declaring 2 sets
        Set A, B;
        // variable for finded charater
        char aCharacter;

        // input for set A and B
        cin >> A;
        cin >> B;

        // input for a single charater tested in set A or set B
        cin.get(aCharacter);

        // output value Set A and B
        cout <<"A: " << A;
        cout <<"B: " << B;

        // Declare Set C for assign it
        Set C;

        // The union of A and B
        C = A + B;
        cout << "A+B: " << C;

        // The intersection of A and B
        C = A * B;
        cout << "A*B: " << C;

        // what elements that B doesn't have (in A)
        C = A - B;
        cout << "A-B: " << C;

        // what elements that A doesn't have (in B)
        C = B - A;
        cout << "B-A: " << C;

        // check if A contains B or B contains A or not either
        cout << "A "; A >= B; cout << " B" << endl;
        cout << "B "; B >= A; cout << " A" << endl;

        // find if a character belongs to A or B set or not either
        A.in(aCharacter); cout << " A" << endl;
        B.in(aCharacter); cout << " B" << endl;
        
        // a blank between test cases
        cout << endl;
    }
}


// constructor definition
Set::Set()
{
    // initialize value with NULL
    for (int i = 0; i < 256; i++)
    {
        arr[i] = '\0';
    }
}

// input definition 
istream& operator >>(istream& inputStream, Set& ASet)
{
    // read input by reading a line
    inputStream.getline(ASet.arr, sizeof(ASet.arr));

    // sort array by it's ASCII values
    sortArrayBasedOnASCII(ASet.arr);
    
    // remove duplicate
    removeDuplicateCharacter(ASet.arr);

    return inputStream;
}

// output definition
ostream& operator <<(ostream& outputStream, Set& ASet)
{
    // sort array by it's ASCII values
    sortArrayBasedOnASCII(ASet.arr);

    // remove the duplicate
    removeDuplicateCharacter(ASet.arr);

    cout << "{";
    
    // output the set
    for (int i = 0; i < strlen(ASet.arr); i++)
    {
        cout << ASet.arr[i]; 
    }
    cout << "}" << endl;

    return outputStream;
}

// assigment operator definiton
Set& Set::operator=(const Set& ASet)
{
    int arrayLength = strlen(ASet.arr);
 
    // copy all of it's content to new array
    for (int i = 0; i < arrayLength; i++)
    {
        this->arr[i] = ASet.arr[i];
    }
    // add a null terminator
    this->arr[arrayLength] = '\0';

    return *this;
}

// union operator definition
const Set operator +(Set& ASet, Set& BSet)
{
    // find the sum of two array length
    int arrayAlength = strlen(ASet.arr);
    int arrayBlength = strlen(BSet.arr);
    int totalLength = arrayAlength + arrayBlength;

    Set C;

    // variable for the second array
    int j = 0;

    // copy the values from array A and B
    for (int i = 0; i < totalLength; i++)
    {
        if (i < arrayAlength)
        {
            C.arr[i] = ASet.arr[i];
        }
        else
        {
            C.arr[i] = BSet.arr[j];
            j++; // index for the second array
        }
    }

    // add a null terminator
    C.arr[totalLength] = '\0';

    return C;
}

// intersection operator definition
const Set operator *(Set& ASet, Set& BSet)
{
    Set C;
    // variable for new array index
    int tempIndex = 0;

    // find the same value from Set A and Set B 
    // add it to C array
    for (int i = 0; i < strlen(ASet.arr); i++)
    {
        for (int j = 0; j < strlen(BSet.arr); j++)
        {
            if(ASet.arr[i] == BSet.arr[j])
            {
                C.arr[tempIndex] = ASet.arr[i];
                tempIndex++;
            }
        }

    }

    // add a null terminator
    C.arr[tempIndex] = '\0';

    return C;
}

// difference operator definition
const Set operator -(Set& ASet, Set& BSet)
{
    Set C;
    // variable for new array index
    int tempIndex = 0;
    // variable for know if a character exist in both Set
    bool exist = false;

    // Find the character which is not exist in B Set
    for (int i = 0; i < strlen(ASet.arr); i++)
    {
        // reset exist every i loop
        exist = false;
        for (int j = 0; j < strlen(BSet.arr); j++)
        {
            if (ASet.arr[i] == BSet.arr[j])
            {
                exist = true;
            }
        }

        // element in A does'nt exist in B
        if (!exist)
        {
            // add element into C array
            C.arr[tempIndex] = ASet.arr[i];
            tempIndex++;
        }
    }
    // add a null terminator
    C.arr[tempIndex] = '\0';

    return C;
}

// contains operator definition
void operator >=(Set& ASet, Set& BSet)
{
    int same = 0; // variable for count the same elements

    // find if every element of B Set is exist in A Set
    for (int i = 0; i < strlen(BSet.arr); i++)
    {
        for (int j = 0; j < strlen(ASet.arr); j++)
        {
            if (BSet.arr[i] == ASet.arr[j])
            {
                same++;
                break;
            }
        }
    }

    // check if all elements in B Set exist in A Set
    if (same == strlen(BSet.arr))
    {
        cout << "contains";
    }
    else
    {
        cout << "does not contain";
    }
}

// belongs to operator definition
void Set::in(char x)
{
    bool found = false;
    // find if this Set contains x
    for (int i = 0; i < strlen(this->arr); i++)
    {
        if (x == this->arr[i])
        {
            found = true;
            break; // terminate the loop
        }
    }

    // output the answer
    if (found)
        cout << "'" << x << "' is in";
    else
        cout << "'" << x << "' is not in"; 
}

// swap 2 values with reference
void swap (char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
}

// sort Array based on it's ASCII values
void sortArrayBasedOnASCII(char arr[])
{
    // using bubble sort to sort based on ASCII values
    for (int i = 0; i < strlen(arr); i++)
    {
        for (int j = i + 1; j < strlen(arr); j++)
        {
            if (arr[i] > arr[j])
            {
                swap(arr[i], arr[j]);
            }
        }

    }
    arr[strlen(arr)] = '\0';
}

// remove the duplicate character from arr
void removeDuplicateCharacter(char arr[])
{
    int arrayLength = strlen(arr);

    // create an dynamic array to save the new array without duplicate elements
    char *tempArray = new char[arrayLength];
    if (tempArray == NULL)
    {
        cout << "Memory allocation failed"<< endl;
        return; // Handle memory allocation failure
    }


    // initialize tempArray
    for (int i = 0; i < arrayLength; i++)
    {
        tempArray[i] = '\0';
    }

    int tempArrayIndex = 0;
    bool isDuplicate = false;

    // find the non duplicate elements in sorted Set
    for (int i = 0; i < arrayLength; i++)
    {   
        // set every j loop
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

        // if a elements is not duplicate 
        if (isDuplicate == false)
        {
            // save the elements into new array
            tempArray[tempArrayIndex] = arr[i];
            tempArrayIndex++;
        }
    }

    // copy the new array back to array
    for (int i = 0; i < tempArrayIndex; i++)
    {
        arr[i] = tempArray[i];
    }
    // add null terminator
    arr[tempArrayIndex] = '\0';

    // free the allocated memory
    delete[] tempArray;
}


