
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
		cout << "1" << endl;
		// check if array full with size n
		if(arrayFull(array, n))
		{
			// display the array if there is a solution
			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{	
					cout << setw(3) << array[i][j];
				}
				cout << endl;
			}

			break;
		}

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < n; j++)
				{	
					cout << setw(3) << array[i][j];
				}
				cout << endl;
			}

		cout << "2" << endl;
		// find the possible move from currentRow & currentColumn with saved previousKmove
		int Kmove = knightPossibleMove(currentRow, currentColumn, previousKMove, array, n);
		cout << "3" << endl;
		// if Knight can moves 
		if (Kmove >= 0)
		{
			cout << "move a step " << endl;
			cout << "4" << endl;
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
			cout << "cannot moves, move to backwoard position" << endl;

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
			cout << "5" << endl;
			// toggle the block to be unvisited
			array[currentRow][currentColumn] = 0;
			cout << "6" << endl;
			// get the information from top node and set it to current row and currentColumn
			currentRow = knightStack.getTopRow();
			currentColumn = knightStack.getTopColumn();
			// try a new move 
			previousKMove = knightStack.getTopKmove() + 1; 
			step--;
			cout << "7" << endl;

			// remove the current value
			knightStack.pop();
			
			
		}
	}
	while(true);

	cout << "keluar loop";
}


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

int knightPossibleMove(int row, int column, int previousKMove,  int **array, int tableSize)
{
	// cout << "masuk function knight possible" << endl;
	// Set the maximum row and column, Explaination : index for array start from 0
	int maxRow = tableSize;
	int maxColumn = tableSize;
	int tempRow = row;
	int tempColumn = column;

	cout << "2.1" << endl;
	bool canMove = false;
	int canMoveIndex;

	// check possible move from previous Kmove to avoid infinite running
	for (int i = previousKMove; i < 8; i++)
	{
		cout << "2.2" << endl;
		// reset row and column every loop
		row  = tempRow;
		column = tempColumn;

		row += moves[i].row;
		column += moves[i].column;

		// check if the moves is possible
		if (row < maxRow && column < maxColumn && row >= 0 && column >= 0)
		{
			cout << "2.3" << endl;
			// check if the array if filled or not
			if (array[row][column] == 0)
			{
				cout << "2.4" << endl;
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