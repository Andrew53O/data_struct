// Author: 洪理川 B113040056
// Date: Oct. 1  2023
// Purpose: Test if a knight can visit each positon of a chess board (Stack application)

#include <iostream>
#include <iomanip>
using namespace std;

// Global prototypes
void KnightChess(int n);
bool arrayFull(int **array, int size);
int knightPossibleMove(int row, int column, int previousKmove,  int **array, int tableSize);

struct knightMove
{
	int row;
	int column;
};

class Stack;  // let the Node class code know Stack this existence
class Node
{
	public:
    // constructor
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
    // constructors
	Stack();
	Stack(int row, int column);

    // push values to stack
	void push(int row, int column, int Kmove);

    // remove top value from stack		
	void pop();

    // clear stack values
	void clear();

    // display all stack values
	void displayStack();

    // display top stack value
	void displayData();

    // Getter
	Node *getTopNode() {return TopNode;}
	int getTopRow () {return TopNode->row;}
	int getTopColumn () {return TopNode->column;}
	int getTopKmove () {return TopNode->Kmove;}

	private: 
	Node *TopNode = NULL;

};

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
    cout << "When n = 1: " << endl;
	KnightChess(1);

    cout << "When n = 2: " << endl;
	KnightChess(2);

    cout << "When n = 3: " << endl;
	KnightChess(3);

    cout << "When n = 4: " << endl;
	KnightChess(4);

    cout << "When n = 5: " << endl;
	KnightChess(5);

    cout << "When n = 6: " << endl;
	KnightChess(6);

	cout << "When n = 7: " << endl;
	KnightChess(7);

	cout << "When n = 8: " << endl;
	KnightChess(8);
}

// Test if a knight can visit each position of a chess board in n * n board
void KnightChess(int n)
{
	Stack knightStack;
	// creating dynamic array of size n by n
	int **array = new int*[n];

	for (int i = 0; i < n; i++)
	{
		array[i] = new int[n];
	}

	// initialize dynamic array with 0 value
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			array[i][j] = 0;
		}
	}

	int step = 2; // starting step (becuase step is fixed in array[0][0])
	int currentRow = 0; // saves the currentRow index 
	int currentColumn = 0; // saves the currentColumn index
	int previousKMove = 0; // saves the previous Knight Move, default with 0

	// fixed value
	array[0][0] = 1;

	// start fill the chess board
	do 
	{
		// check if array full with size n
		if(arrayFull(array, n))
		{
			// display the array if there is a solution
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{	
					// formatting output
					cout << setw(3) << array[i][j];
				}
				cout << endl;
			}

			break;
		}
		
		// find the possible move from currentRow & currentColumn with saved previousKmove
		int Kmove = knightPossibleMove(currentRow, currentColumn, previousKMove, array, n);
		
		// if Knight can moves 
		if (Kmove >= 0)
		{
			// Push currentRow, currentColumn and Knight we will do 
			knightStack.push(currentRow, currentColumn, Kmove);

			// add row and column value from the move
			currentRow += moves[Kmove].row;
			currentColumn += moves[Kmove].column;

			// set the block to be visited in step
			array[currentRow][currentColumn] = step;
			step++;

			// To reset the previousMove if find a new path
			if (previousKMove != 0)
			{
				previousKMove = 0;
			}
		}
		else // cannot moves, move to backward position
		{		
			// the starting position
			if (knightStack.getTopNode() == NULL)
			{
				// No solution case because it doesn't find any possible path from the starting point (after trying all moves)
				if (currentRow == 0 && currentColumn == 0 && previousKMove > 8)
				{
					cout << "No solution" << endl;
					break;
				}

				// find another way from the starting position
				previousKMove++;
				continue;
			}

			// toggle the block to be unvisited
			array[currentRow][currentColumn] = 0;

			// get the information from top node and set it to current row and currentColumn
			currentRow = knightStack.getTopRow();
			currentColumn = knightStack.getTopColumn();
			// try a new move 
			previousKMove = knightStack.getTopKmove() + 1; 
			step--;

			// remove the current value
			knightStack.pop();
		}
	}
	while(true);

	// free dynamic array
	for (int i = 0; i < n; i++)
	{
		delete[] array[i];
	}

	delete[] array;

	cout << endl;
}

// check if the array is full or not 
bool arrayFull(int **array, int size)
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

// return a possible of knight else return -1
int knightPossibleMove(int row, int column, int previousKMove,  int **array, int tableSize)
{
	// Set the maximum row and column, Explaination : index for array start from 0
	int maxRow = tableSize;
	int maxColumn = tableSize;

	// temp variable for row and column
	int tempRow = row;
	int tempColumn = column;

	// boolean variable for check if it a possible move or not
	bool canMove = false;
	int canMoveIndex;

	// check possible move from previous Kmove to avoid infinite running
	for (int i = previousKMove; i < 8; i++)
	{
		// reset row and column every loop
		row  = tempRow;
		column = tempColumn;

		// test by adding the value
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

	// return value
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
	// intentionally empty
}

/*-------------------------*/
/*-------Stack Class-------*/     	
/*-------------------------*/

Stack::Stack() 
{
	// intentionally empty
}

// push value to the stack
void Stack::push(int row, int column, int Kmove)
{
	// Create a new node
	Node *PnewNode = new Node;
	
	// fill the node value
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

// remove a value from the stack
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

// clear the stack 
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

// display the stack all values
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