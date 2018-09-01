#include <string>
#define defaultGridSize 20

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


	int **myMatrix;

public:
	GameOfLife();
	~GameOfLife();
	void gridSizeMessage();
	void setGridWidth();
	void setGridHeight();	
	void setCondition();
	int getGridWidth();
	int getGridHeight();
	std::string getCondition();
	void gridDimensionsMessage();
	void checkGridSize();
	void gridSizeFlowControl();
	void checkGridSizeMessage();
	void checkInputStream();
	char checkForString();
	void setXCoordinate();
	void setYCoordinate();
	int getXCoordinate();
	int getYCoordinate();
	void setBaseMatrix();
	void fillBaseMatrix();
	void printBaseMatrix();
	void deleteBaseMatrix();
	void setNextMatrix();
	void fillNextMatrix();
	void printNextMatrix();
	void deleteNextMatrix();
	void setCoordinatesToMatrix();
	void setNumberOfCoordinates();
	int getNumberOfCoordinates();
	void countCoordinatesMessage(int i);
	void setCoordinates();
	int findNeighbours(int i, int j);
	int resetCounter();
	int returnCounter();
	int rules(int i, int j);
	void drawShapes();
	void interchangeMatrix();
	void nucleusOfGame();
	void startCoordinateMessage();

	void blockShape();
	void boatShape();
	void blinkerShape();
	void beaconShape();
	void gliderShape();
	void pulsarShape();
	void pentadecathlonShape();
	void cvadraBlinkerShape();

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
	
	void patternInputMethodMessage();
	void availablePatterns();
	void patternInputMethod();
	void setPatternInputMethod();
	int getPatternInputMethod();
	void checkShapeAvailability();
	void unavailableShapeMessage();
	void checkShapeCondition();
	void setDesiredShapeValue();
	int getDesiredShapeValue();
	void shapeMenu();
	void checkInputPatternAvailability();
	void inputPatternUnavailableMessage();
	void checkInputPatternCondition();
	void shapeMethodPackage();
	void motherboard();



	int getCell(int i, int j);
	void setMyMatrix();
	void fillMyMatrix();
	void printMyMatrix();
};