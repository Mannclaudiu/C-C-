#include <string>
#define defaultGridSize 20
#define CONST_SLEEP 50
/**
	Purpose: Enumeration, used to store the shapes. 'last_item' is a refference who is used in order to keep track of 
			 shapes. Any shape that will be added, it will be added before 'last_item'.
*/
enum Shapes{
	block, boat, blinker, beacon, pulsar, pentadecathlon, glider, cvadra_blinker, last_item
};

class GameOfLife{


private:

	/**
		Purpose: 'gridWidth' is a variable who is used in order to set the grid width.
	*/
	int gridWidth;

	/**
		Purpose: 'gridHeight' is a variable who is used in order to set the grid height.
	*/
	int gridHeight;

	/**
		Purpose: 'xCoordinate' is a variable who is used in order to set the coordinate for x.
	*/
	int xCoordinate;

	/**
		Purpose: 'yCoordinate' is a variable who is used in order to set the coordinate for y.
	*/
	int yCoordinate;

	/**
		Purpose: 'coordinatesNumber' is a variable who is used in order to store the number of coordinates.
	*/
	int coordinatesNumber;

	/**
		Purpose: 'baseMatrix' is a matrix o characters, used to store the start patterns.
	*/
	char** baseMatrix;

	/**
		Purpose: 'nextMatrix' is a matrix o characters, used to store the next pattern.
	*/
	char** nextMatrix;

	/**
		Purpose: 'condition' is a variable who is used in order to set Y/N answers in the future methods.
	*/
	std::string condition;

	/**
		Purpose: 'counter' is a variable used to count alive neighbours.
	*/
	int counter;

	/**
		Purpose: 'defaultValue' is a variable, who is used in order to set default grid size (if true),
				 or to give user another chance to set the grid size (if false), based on an (Y/N) answer.
				 Y = false, N = true.
	*/
	bool defaultValue;

	/**
		Purpose: 'chooseShapeNumber' is a variable used to to store the value of shape, aslked by user.
	*/
	int chooseShapeNumber;

	/**
		Purpose: 'methodInput' is a variable used to pick pattern input method.
	*/
	int methodInput;

	bool success;


public:
	GameOfLife();
	~GameOfLife();

	/**
		Purpose: Prints a message which tells us to set the grid size
	*/
	void gridSizeMessage();

	/**
		Purpose: Prints a message and at the same time it asks us for grid width. Depending by 'defaultValue'
			variable, we may be asked to set the grid width again, or set a default value.
			'checkInputStream()' is used in order to block wrong values that come from istream.
	*/
	void setGridWidth();

	/**
		Purpose: Prints a message and at the same time it asks us for grid height. It have the same logic with 'setGridWitdh()',
			but here instead of grid width, we use grid height.
	*/
	void setGridHeight();

	/**
		Purpose : set the user input condition
	*/
	void setCondition();

	/**
		Purpose : return the grid width size
	*/
	int getGridWidth();

	/**
		Purpose : return the grid height size
	*/
	int getGridHeight();

	/**
		Purpose : return the condition value
	*/
	std::string getCondition();

	/**
		Purpose : Prints a message to inform the user about the grid size chosen
	*/
	void gridDimensionsMessage();

	/**
		Purpose : Used to check the grid size. The grid size is verified by comparing isteam value with default value.
			If the while loop is true, then we print a message to inform user that the size input values are wrong and
			we ask him to try again. There is also a method used to get the decision of user, and a method who executes
			the flow based on decision.
	*/
	void checkGridSize();

	/**
		Purpose: Based on user input (Y/N), it executes the specific methods. If user wants to set the
			grid size again (Y), then we call those methods who let him accomplish that job.
			Else if the user don't want to set the grid size anymore, then a default size is set,
			and a message with final grid size will appear to the screen.
			User input is stored in the 'istream' char variable, and it is returned from
			'checkForString()' method.
	*/
	void gridSizeFlowControl();

	/**
		Purpose: Prints a message to inform the user that the grid size is too small, and it also asks
			the user if want to try again to set the grid size.
	*/
	void checkGridSizeMessage();

	/**
		Purpose: If istream expects only numbers, and user will set letters, then we need to inform the user that the
			input is invalid. We also clear the data that user typed, and by using 'ignore()' method, we ignore every
			character untill '\n' is found.
			By using this function, we can set the input again, if it was invalid.
	*/
	void checkInputStream();

	/**
		Purpose: If the user sets a string as input, which length is != 1, then we exit the function returning nothing.
			Else if the string has one character i.e 'y', 'g', etc, then we return this character.
	*/
	char checkForString();

	/**
		Purpose: Used to set the coordinates for x.
	*/
	void setXCoordinate();

	/**
		Purpose: Used to set the coordinates for y.
	*/
	void setYCoordinate();

	/**
		Purpose: Used to return the coordinates for x.
	*/
	int getXCoordinate();

	/**
		Purpose: Used to return the coordinates for y.
	*/
	int getYCoordinate();

	/**
		Purpose: Create the first matrix.
	*/
	void setBaseMatrix();

	/**
		Purpose: Initialise the first matrix.
	*/
	void fillBaseMatrix();

	/**
		Purpose: Prints the first matrix.
	*/
	void printBaseMatrix();

	/**
		Purpose: Used to dealocate memory
	*/
	void deleteBaseMatrix();

	/**
		Purpose: Create the second matrix.
	*/
	void setNextMatrix();

	/**
		Purpose: Initialise the second matrix.
	*/
	void fillNextMatrix();

	/**
		Purpose: Prints the second matrix.
	*/
	void printNextMatrix();

	/**
		Purpose: Used to dealocate memory
	*/
	void deleteNextMatrix();

	/**
		Purpose: At given matrix coordinates, we set '*'.
	*/
	void setCoordinatesToMatrix();

	/**
		Purpose: Set the number of coordinates.
	*/
	void setNumberOfCoordinates();

	/**
		Purpose: Return the number of coordinates.
	*/
	int getNumberOfCoordinates();

	/**
		Purpose: Counts every set consisting of two coordinates (x, y).
	*/
	void countCoordinatesMessage(int i);

	/**
		Purpose: By iterating until number of coordinates, we are setting the coordinates.
	*/
	void setCoordinates();

	/**
		Purpose: The user needs to choose, between two input modes: either set the pattern manually by setting coordinates for every point,
			either uses a list of patterns, and give only starting coordinates point
	*/
	void patternInputMethodMessage();

	/**
		Purpose: Ask the user for pattern input method, and return this value.
	*/
	void setPatternInputMethod();

	/**
		Purpose: Gets the value for pattern input method
	*/
	int getPatternInputMethod();

	/**
		Purpose: Prints a message if pattern input method does not exist.
	*/
	void inputPatternUnavailableMessage();

	/**
		Purpose: Checks if the user choses one of the two pattern input methods.
	*/
	void checkInputPatternAvailability();

	/**
		Purpose: A switch case where we chose a different flow for our game, depending on pattern input method
	*/
	void patternInputMethod();

	/**
		Purpose: A switch case where we choose from a list of availavle shapes, stored in Enumeration structure.
	*/
	void availablePatterns();


	/**
		Purpose: If a shape is unavailable, then we warn the user about that.
	*/
	void unavailableShapeMessage();

	/**
		Purpose: Checks if values for every shape, are in range.
	*/
	void checkShapeAvailability();

	/**
		Purpose: This method is used to make a pack of methods that will be used in more than one place.
	*/
	void shapeMethodPackage();


	/**
		Purpose: The menu where we can see available shapes.
	*/
	void shapeMenu();


	/**
		Purpose: Checks for an answer given by the user.
	*/
	void checkShapeCondition();

	/**
		Purpose: Checks for an answer given by the user. Even if those two check functions are duplicate, I didn't want
			to fix it, because I may improve my application and add unique content for any of them. So those two check methods
			will get fixed in the future.
	*/
	void checkInputPatternCondition();

	/**
		Purpose: Set a value who is used to pick a shape.
	*/
	void setDesiredShapeValue();

	/**
		Purpose: Return the value of the shape.
	*/
	int getDesiredShapeValue();

	/**
		Purpose: Method used to find the neighbours of each point.
	*/
	int findNeighbours(int i, int j);

	/**
		Purpose: Method used to reset the counter.
	*/
	int resetCounter();

	/**
		Purpose: Method used to return the counter.
	*/
	int returnCounter();

	/**
		Purpose: There is the set of four rules used to bring alive the game of live
	*/
	int rules(int i, int j);

	/**
		Puspose: Print the matrix. Also uses a timer where we can set the speed of each transision.
			By using 'system("cls")' we clear the screen.
	*/
	void drawShapes();

	/**
		Purpose: We need two matrixes for this game. First is the initial matrix, and second is the next matrix who
			stores a drawing based on first matrix coordinates. We need to assign second matrix, to first matrix
			in order to reach the next change in coordinates.
	*/
	void interchangeMatrix();

	/**
		Purpose: This function is where the game gets alive
	*/
	void nucleusOfGame();

	/**
		Purpose: For every shape selected, we need to set only x and y coordinates, and the shape gets alive.
	*/
	void startCoordinateMessage();

	/**
		Purpose: Used to draw the a block shape :
													*  *
													*  *
	*/
	void blockShape();

	/**
		Purpose: Used to draw a boat shape :
												*  *  
												*     *
												   *
	*/
	void boatShape();

	/**
		Purpose: Used to draw a blinker shape :
												*                                     *
												*                 *  *  *             *
												*                                     *
	*/
	void blinkerShape();

	/**
		Purpose: Used to draw a beacon shape :
											*  *                      *  *                   *  *
											*                         *  *                   *
												   *                     *  *                      *
											   	*  *                     *  *                   *  *
	*/
	void beaconShape();

	/**
		Purpose: Used to draw a pulsar shape :
													*                *
													*                *
													*  *          *  *

										*  *  *		   *  *    *  *       *  *  *
											  *		*     *    *     *    *
													*  *          *  *

													*  *          *  *
											  *  	*     *    *     *    *
										*  *  *		   *  *    *  *       *  *  *

													*  *           *  *
													*		          *
													*				  *
	*/
	void pulsarShape();

	/**
		Purpose: Draw a pentadecathlon shape:
											  *              *
										*  *     *  *  *  *     *  *
										      *              *
	*/
	void pentadecathlonShape();

	/**
		Purpose: Draw a glider shape: 
										   *
											  *
										*  *  *
	*/
	void gliderShape();

	/**
		Purpose: Draw a shape that advances to cvadra blinker shape:
																	   *
																	*  *  *
	*/
	void cvadraBlinkerShape();

	/**
		Purpose: All those functions are used to build sequences for every shape
	*/
	int tetronimoShape1of8(int i, int j);
	int tetronimoShape2of8(int i, int j);
	int tetronimoShape3of8(int i, int j);
	int tetronimoShape4of8(int i, int j);
	int tetronimoShape5of8(int i, int j);
	int tetronimoShape6of8(int i, int j);
	int tetronimoShape7of8(int i, int j);
	int tetronimoShape8of8(int i, int j);
	int shapeShip1of2(int i, int j);
	int shapeShip2of2(int i, int j);
	int cross(int i, int j);
	
	/**
		Purpose: And this is the end, the method who control everything in my game.
	*/
	void motherboard();



};