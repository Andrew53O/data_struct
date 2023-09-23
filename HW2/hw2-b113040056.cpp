#include <iostream>
#include <string.h>
using namespace std;

// global prototypes
int countFilledLength(const char arr[]);
void sortArrayBasedOnASCII(char arr[]);
void removeDuplicateCharacter(char arr[]);
void swap (char& a, char& b);


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
    
    friend const Set operator +( Set& ASet,  Set& BSet); 

    friend const Set operator *(Set& ASet, Set& BSet);

    friend const Set operator -(Set& ASet, Set& BSet);

    friend void operator >=(Set& ASet, Set& BSet);
    
    void in(char x);




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
        char aCharacter;

        // input for set A and B
        cin >> A;
        cin >> B;

        // input for a single charater tested in set A or set B
        cin >> aCharacter;

        // all operations
        cout << A;
        cout << B;
        Set C;

        C = A + B;

        cout << "A+B: " << C;

        C = A * B;

        cout << "A*B: " << C;


        C = A - B;

        cout << "A-B: " << C;

        C = B - A;

        cout << "B-A: " << C;

        A >= B;
        B >= A;

        A.in(aCharacter);
        B.in(aCharacter);
        

    }
}



Set::Set()
{
    for (int i = 0; i < 256; i++)
    {
        arr[i] = '\0';
    }
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
    // sort the array 
    sortArrayBasedOnASCII(ASet.arr);

    // remove the duplicate
    removeDuplicateCharacter(ASet.arr);

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
 
    for (int i = 0; i < arrayLength; i++)
    {
        this->arr[i] = ASet.arr[i];
    }
    this->arr[arrayLength] = '\0';

    return *this;
}


const Set operator +(Set& ASet, Set& BSet)
{
    int arrayAlength = strlen(ASet.arr);
    int arrayBlength = strlen(BSet.arr);

    int totalLength = arrayAlength + arrayBlength ;

    Set C;

    int j = 0;
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

    C.arr[totalLength] = '\0';

    return C;
}

const Set operator *(Set& ASet, Set& BSet)
{
    Set C;
    int tempIndex = 0;

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

    C.arr[tempIndex] = '\0';

    return C;
}


const Set operator -(Set& ASet, Set& BSet)
{
    Set C;
    int tempIndex = 0;
    bool exist = false;

    for (int i = 0; i < strlen(ASet.arr); i++)
    {
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
            C.arr[tempIndex] = ASet.arr[i];
            tempIndex++;
        }
    }
    C.arr[tempIndex] = '\0';

    return C;
}




void operator >=(Set& ASet, Set& BSet)
{

    int same = 0;
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

    if (same == strlen(BSet.arr))
    {
        cout << "contains";
    }
    else
    {
        cout << "does not contain";
    }
}

void Set::in(char x)
{
    cout << "yang dicari" << x << endl; 
    bool found = false;
    for (int i = 0; i < strlen(this->arr); i++)
    {
        if (x == this->arr[i])
        {
            found = true;
            break;
        }
    }

    if (found)
        cout << "'" << x << "' is in" << endl;
    else
        cout << "'" << x << "' is not in" << endl;  
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


void swap (char& a, char& b)
{
    char temp = a;
    a = b;
    b = temp;
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
                swap(arr[i], arr[j]);
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
// 1. continue finish all of the operator
// - operator

