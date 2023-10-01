#include <iostream>
#include <iomanip>
using namespace std;

// Global prototypes
bool arrayFull(int array[][5], int size);
int knightPossibleMove(int row, int column, int previousKmove,  int array[][5], int tableSize);

struct knightMove
{
	int row;
	int column;
};

// let the Node class code know Stack this existence
class Stack; 
class Node
{
	public:
	Node();
	Node(int row, int column);

	// let 'Stack' class have access to the private/proctected member of 'Node' class
	friend class Stack;
	
	private:
	Node *next;
	int row;
	int column;
	int Kmove;
};

class Stack
{
	public: 
	Stack();
	Stack(int row, int column);

	void push(int row, int column, int Kmove);		
	void pop();

	void clear();
	void displayStack();

	void displayData();

	int getTopRow () {return TopNode->row;}
	int getTopColumn () {return TopNode->column;}
	int getTopKmove () {return TopNode->Kmove;}

	private: 
	Node *TopNode = NULL;

};

// declare 2D arrays for keep track of it's position
int array1[1][1] = {0};
int array2[2][2] = {0};
int array3[3][3] = {0};
int array4[4][4] = {0};
int array5[5][5] = {0};
int array6[6][6] = {0};

// declare array of possible knight moves
knightMove moves[8] = {
					{-2, 1}, 
					{-1, 2}, 
					{1, 2}, 
					{2, 1}, 
					{2, -1}, 
					{1, -2}, 
					{-1, -2}, 
					{-2, -1} 
					};

int main(void)
{
	// 
	Stack three;

	int n = 5;

	int step = 2;
	int currentRow = 0;
	int currentColumn = 0;
	int previousKMove = 0;


	// starting position
	array5[0][0] = 1;

	do 
	{
		cout << "do while loop" << step << endl;

		if (step)
		{
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{	
					cout << setw(3) << array5[i][j];
				}
				cout << endl;
			}
		}
		// if (step == 9)
		// {
		// 	break;
		// }

		// check if array full with size n
		if(arrayFull(array5, 5))
		{
			cout << "full" << endl;
			break;
		}

		int Kmove = knightPossibleMove(currentRow, currentColumn, previousKMove, array5, 5);

		// if Knight can moves 
		if (Kmove >= 0)
		{
			// push then add currentRow and currentColumn because we rwemember the original position and Knight moves
			three.push(currentRow, currentColumn, Kmove);

			currentRow += moves[Kmove].row;
			currentColumn += moves[Kmove].column;

			cout << "current => " << currentRow << " " << currentColumn  << " " << Kmove << endl;
			// visited
			array5[currentRow][currentColumn] = step;
			step++;

			if (previousKMove != 0)
			{
				previousKMove = 0;
			}
		}
		else // cannot moves, move to backward position
		{		
			
			array5[currentRow][currentColumn] = 0;
			// get the information from top node and set it to current row and currentColumn
			currentRow = three.getTopRow();
			currentColumn = three.getTopColumn();
			previousKMove = three.getTopKmove() + 1;
			step--;

			three.pop();

			// No solution Case because it find no possible solution from the starting point
			if (currentRow == 0 && currentColumn == 0)
			{
				cout << "No solution" << endl;
				break;
			}

			
			cout << "cannot moves, moves to backward position" << endl;
			three.displayStack();
			cout << "displaying the data";
			three.displayData();

		}
		
		
	}
	while(true);

	cout << "Keluar while loop" << endl;
	

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{	
			cout << setw(3) << array5[i][j];
		}
		cout << endl;
	}
	

	cout << "lese print" << endl;
	return 0;
}


bool arrayFull(int array[][5], int size)
{
	bool isFull = true;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if(array[i][j] == 0)
			{
				isFull = false;
			}

		}
	}

	return isFull;
}

int knightPossibleMove(int row, int column, int previousKMove,  int array[][5], int tableSize)
{
	// Set the maximum row and column, Explaination : index for array start from 0
	int maxRow = tableSize;
	int maxColumn = tableSize;
	int tempRow = row;
	int tempColumn = column;


	bool canMove = false;
	int canMoveIndex;

	
	// check possible move from previous Kmove to avoid infinite running
	for (int i = previousKMove; i < 8; i++)
	{
		// reset row and column every loop
		row  = tempRow;
		column = tempColumn;

		row += moves[i].row;
		column += moves[i].column;

		// check if the moves is possible
		if (row < maxRow && column < maxColumn && row >= 0 && column >= 0)
		{
			// check if the array if filled or not
			if (array[row][column] == 0)
			{
				canMove = true;
				canMoveIndex = i;
				break;
			}

		}
	}


	if (canMove)
	{
		return canMoveIndex;
	}
	else
	{
		return -1;
	}

	
}


Node::Node()
{

}

/*-------------------------*/
/*-------Stack Class-------*/     	
/*-------------------------*/

// Stack::Stack(int row, int column)
// {
// 	this->row = row;
// 	this->column = column;
// 	// intentionally blank
// }

Stack::Stack() 
{


}

void Stack::push(int row, int column, int Kmove)
{
	// Create a new node
	Node *PnewNode = new Node;
	
	PnewNode->row = row;
	PnewNode->column = column;
	PnewNode->Kmove = Kmove;
	PnewNode->next = NULL;

	// insert into the stack
	Node *tempTop = TopNode;

	// top node point to new node
	TopNode = PnewNode;

	// new node point to the item that top point (before point to the new node)
	PnewNode->next = tempTop;

}

void Stack::pop()
{
	// tuilis klo top itu null
	if (TopNode == NULL)
	{
		cout << "Stack is empty";
		return; 
	}

	Node *tempTop = TopNode;
	TopNode = TopNode->next;

	delete tempTop;
}



void Stack::clear()
{
	// delete each node so it's properly deallocated
	while (TopNode != NULL)
    {
        Node *temp = TopNode;
        TopNode = TopNode->next;
        delete temp;
    }
}

void Stack::displayStack()
{
	cout << "Displaying Stack" << endl;
	Node *tempTopNode = TopNode;
	while(tempTopNode != NULL)
	{
		cout << tempTopNode->Kmove << endl;
		tempTopNode = tempTopNode->next;
	}
	cout << endl;
}

// print out the Top data 
void Stack::displayData()
{
	cout << "Displaying data" << endl;

	if (TopNode != NULL)
	{
		cout << TopNode->row <<  "," << TopNode->column << ", " << TopNode->Kmove << endl;
	}
	cout << "Stack is empty" << endl;


}