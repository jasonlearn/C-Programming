// Author: Jason Chan

#define _CRT_SECURE_NO_WARNINGS

/*  This application processes an array of commands which causes turtle to draw
    a pattern on a 2D floor.  This pattern is diplayed after commands have been executed */

#include <stdio.h>   // needed for the printf and scanf statements
#include <conio.h>   // needed for _getch() call at end of main()

// function prototypes
void turtleDraw(const int[]); // main function responsible for executing cmds

// main supplies data to be passed to turtleDraw() function
int main()
{

	int commands[] = { 5, 5, 4, 5, 9, 2,   // go to start of first letter and put pen down

		// B
		5, 12, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 11, 3, 5, 5,
		1, 3, 5, 12, 3, 5, 5, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 11, 3, 5, 5,

		1, 5, 5, 3, 5, 22, 2, // go to start of next letter and put pen down

		// O
		5, 10, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 7, 1, 3, 5, 1, 4, 2, 5, 1,
		1, 3, 5, 1, 2, 5, 10, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 7, 1, 3, 5, 1, 4, 2, 5, 1,

		1, 3, 5, 19, 2,     // go to start of next letter and put pen down

		// B
		5, 12, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 11, 3, 5, 5,
		1, 3, 5, 12, 3, 5, 5, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 2, 1, 3, 5, 1, 4, 2, 5, 1, 1, 3, 5, 1, 2, 5, 11, 3, 5, 5,

		// Test program bound checking and add border in the process

		//   Uncomment next line when ready to test out of bounds checking
		//1, 5, 100, 2, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100,

		1, 6, 9 }; // finish off


	// Invoke function which will execute commands
	turtleDraw(commands);

	// Time to go home

	_getch();
	return 0;
}

// define 2 enum types
enum TCmnds { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum Dirs { BEGIN_VALUE, NORTH, EAST, SOUTH, WEST, END_VALUE };

#define NROWS 22 // number of rows in floor
#define NCOLS 70 // number of colums in floor
#define TRUE 1
#define FALSE 0

const unsigned int STARTING_ROW = 0;    // row that turtle will start in
const unsigned int STARTING_COL = 0;    // column that turtle will start in

const enum TCmnds STARTING_DIRECTION = SOUTH; // direction that turtle 
                                              // will be facing at the start

const short STARTING_PEN_POSITION = FALSE; // Pen will be up when 
                                       //     program starts
                                       // 0 (false) means pen up, 
                                       // 1 (true) means pen down

// some more function prototypes
void displayFloor(const short[][NCOLS]);
void moveTurtle(short [][NCOLS], const int, const enum Dirs, const short, int *, int *);

// turtleDraw() - function responsible for executing commands
void turtleDraw(const int cmds[])
{
	// Define and initialize some important variiables

	// The 2D array floor will represent the surface that the turtle is travelling
	//      over and there by creating the pattern we will eventually print out.
	short floor[NROWS][NCOLS] = { FALSE };  //init to all FALSE (0).
	enum Dirs direction = STARTING_DIRECTION; // used to represent current direction that the turtle is moving
	                                      
	unsigned int row = STARTING_ROW;  // used to represent current row that turtle is at
	unsigned int col = STARTING_COL;  // used to represent current column that turtle is at

	short pen = STARTING_PEN_POSITION; // starting position of pen (up or down)
	                                   // 0 is up, 1 is down
	int cmdNo = 0; // The position in cmds array we are currently processing

	// The following do-while loop is the main loop of this program
	// We will stay in this loop as long as we are processing commands from the cmds[] array

	do {  // until END_OF_DATA is encountered

		switch (cmds[cmdNo]) {  // Switch statment that processes commands
		case PEN_UP: // Pen up
			pen = FALSE;
			break;

		case PEN_DWN: // Pen down
			// STUDENT PROVIDES THIS CODE line 113/114
			pen = TRUE;
			break;

		case TURN_RIGHT: // Turn right
			++direction; // for example, change from NORTH to EAST
			if (direction >= END_VALUE )   // in case we turn right when facing WEST
			{
				direction = NORTH;
			}
			break;

		case TURN_LEFT: // Turn left
			// STUDENT PROVIDES THIS CODE line 126-131
			++direction;
			if (direction >= END_VALUE)
			{
				direction = SOUTH;
			}
			break;

		case MOVE: // Move forward 
			++cmdNo;  // move to next command in the command array
			          //   we need next value to know how many spaces to move
			       
			// We pass pointers to row and col below so that when we update in moveTurtle()
			//    they are updated here in turtleDraw() as well.
			moveTurtle(floor,  cmds[cmdNo], direction, pen, &row, &col); // move turtle as required
			                                                             //  and update floor as req.
			break; // end of case MOVE:

		case DISPLAY: // display the floor matrix
			displayFloor(floor);
			break;

		case END_OF_DATA: // end of data reached
			break; // no action required, will exit do-while loop automatically

		default: // should never get here !!!
			puts("\n\nERROR - invalid command encountered in"
				" turtleDraw() switch statement.\n\n");
			return;  // major error, so go home

		} // end of switch statment

		++cmdNo;   // move to next command

	} while (cmds[cmdNo] != END_OF_DATA); // repeat until end of data is reached

}

// moveTurtle() - responsible for moving the turtle on the floor and modifying floor if pen is down.
// This function is passed pointers to row and col because they need to be passed by reference
//      because this function must update the row and col when moving turtle. Note that 
//      floor is also passed by reference, but because anarry name is a pointer, the array
//      is automatically passed by reference.
void moveTurtle(short floor [][NCOLS], const int numOfMoves, const enum Dirs currDir, const short penPos, int * rowPtr, int * colPtr)
{
	// STUDENT PROVIDES THIS CODE (function moveTurtle)
	int i; // counter for array

	// validates if pen is up and facing north
	if ( penPos == FALSE && currDir == NORTH ){
		//iterates through number of moves for heading north
		for (i = 0; i < numOfMoves; i++)
		{
			floor[*rowPtr-i][*colPtr] = 1;
		}
		*rowPtr -= (numOfMoves);
	}
	// validates if pen is up and facing east
	else if (penPos == FALSE && currDir == EAST ){
		//iterates through number of moves for heading east
		for (i = 0; i < numOfMoves; i++)
		{
			floor[*rowPtr][*colPtr+1] = 1;
		}
		*colPtr += (numOfMoves); //
	}
	// validates if pen is up and facing south
	else if (penPos == FALSE && currDir == SOUTH ){
		//iterates through number of moves for heading south
		for (i = 0; i < numOfMoves; i++)
		{
			floor[*rowPtr+1][*colPtr] = 1;
		}
		*rowPtr += (numOfMoves);
	}
	// validates if pen is up and facing west
	else if (penPos == FALSE && currDir == WEST ){
		//iterates through number of moves for heading west
		for (i = 0; i < numOfMoves; i++)
		{
			floor[*rowPtr][*colPtr-1] = 1;
		}
		*colPtr -= (numOfMoves);
	}
}// end of moveTurtle()

// Responsible for displaying the floor
void displayFloor(const short floorSurface[][NCOLS])
{
	// STUDENT PROVIDES THIS CODE (function displayFloor)
	int i, j;

	//iterates through floorSurface
	for (i = 0; i < NCOLS; i++)
	{
		printf("\n");
		for (j = 0; j < NCOLS; j++)
		{
			if ( floorSurface[i][j] == 1 )
			{
				// displays if row and column is true
				printf("*"); 
			}
			else
			{
				//displays when row and column is false
				printf(" ");
			}
		}
	}
	_getch();

} // end of displayFloor()