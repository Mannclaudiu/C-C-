#include "game_of_life.h"
#include <iostream>
#include <limits>
#include <chrono>
#include <thread>
#include <cctype>

GameOfLife::GameOfLife(){
	defaultValue = false;
}

GameOfLife::~GameOfLife(){

}
/**
	Purpose: Prints a message which tells us to set the grid size
*/
void GameOfLife::gridSizeMessage(){
	std::cout << "Please enter the grid size (at least 20x20): " << std::endl;
}

/**
	Purpose: Prints a message and at the same time it asks us for grid width. Depending by 'defaultValue'
			 variable, we may be asked to set the grid width again, or set a default value.
			 'checkInputStream()' is used in order to block wrong values that come from istream.
*/
void GameOfLife::setGridWidth(){

	if (!defaultValue){
		while ((std::cout << "Grid width: ") && !(std::cin >> this->gridWidth)){
			checkInputStream();
		}
	}
	else{
		gridWidth = defaultGridSize;
	}
}

/**
	Purpose: Prints a message and at the same time it asks us for grid height. It have the same logic with 'setGridWitdh()',
			 but here instead of grid width, we use grid height.
*/
void GameOfLife::setGridHeight(){
	if (!defaultValue){
		while ((std::cout << "Grid height: ") && !(std::cin >> this->gridHeight)){
			checkInputStream();
		}
	}
	else {
		gridHeight = defaultGridSize;
	}
}

/**
	Purpose : return the grid width size
*/
int GameOfLife::getGridWidth(){
	return this->gridWidth;
}

/**
	Purpose : return the grid height size
*/
int GameOfLife::getGridHeight(){
	return this->gridHeight;
}

/**
	Purpose : set the user input condition
*/
void GameOfLife::setCondition(){
	while (!(std::cin >> this->condition)){
		checkInputStream();
	}
}

/**
	Purpose : return the condition value
*/
std::string GameOfLife::getCondition(){
	return this->condition;
}

/**
	Purpose : Prints a message to inform the user about the grid size chosen
*/
void GameOfLife::gridDimensionsMessage(){
	std::cout << "The grid size is: " << getGridWidth() << " x " << getGridHeight() << std::endl;
}

/**
	Purpose : Used to check the grid size. The grid size is verified by comparing isteam value with default value.
			  If the while loop is true, then we print a message to inform user that the size input values are wrong and
			  we ask him to try again. There is also a method used to get the decision of user, and a method who executes
			  the flow based on decision.
*/
void GameOfLife::checkGridSize(){
		while ((getGridWidth() < defaultGridSize) || (getGridHeight() < defaultGridSize)){
			checkGridSizeMessage();
			setCondition();
			gridSizeFlowControl();
			gridDimensionsMessage();
		}
}

/**
	Purpose: Based on user input (Y/N), it executes the specific methods. If user wants to set the
			 grid size again (Y), then we call those methods who let him accomplish that job.
			 Else if the user don't want to set the grid size anymore, then a default size is set,
			 and a message with final grid size will appear to the screen.
			 User input is stored in the 'istream' char variable, and it is returned from
			 'checkForString()' method.
*/
void GameOfLife::gridSizeFlowControl(){
	char istream = checkForString();

	switch (toupper(istream)){
		case 'Y':
			setGridWidth();
			setGridHeight();
			break;
		case 'N': 
			defaultValue = true;			
			setGridWidth();
			setGridHeight();
			break;
		default: 
			break;
	}
}

/**
	Purpose: Prints a message to inform the user that the grid size is too small, and it also asks
			 the user if want to try again to set the grid size.
*/
void GameOfLife::checkGridSizeMessage(){
	std::cout << "\nThe dimmension of grid is too small. Would you like to try again? (Y/N)" << std::endl;
}

/**
	Purpose: If istream expects only numbers, and user will set letters, then we need to inform the user that the
			 input is invalid. We also clear the data that user typed, and by using 'ignore()' method, we ignore every
			 character untill '\n' is found.
			 By using this function, we can set the input again, if it was invalid.
*/
void GameOfLife::checkInputStream(){
	std::cout << "Invalid input, please try again " << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
}

/**
	Purpose: If the user sets a string as input, which length is != 1, then we exit the function returning nothing.
			 Else if the string has one character i.e 'y', 'g', etc, then we return this character.
*/
char GameOfLife::checkForString(){
	std::string str = getCondition();
	if (str.length() != 1)
		return 0;
	else 
		return str[0];
}

/**
	Purpose: Used to set the coordinates for x.
*/
void GameOfLife::setXCoordinate(){
	while ((std::cout << "xCoordinate: ") && !(std::cin >> this->xCoordinate)){
		checkInputStream();
	}
}

/**
	Purpose: Used to set the coordinates for y.
*/
void GameOfLife::setYCoordinate(){
	while ((std::cout << "yCoordinate: ") && !(std::cin >> this->yCoordinate)){
		checkInputStream();
	}
}

/**
	Purpose: Used to return the coordinates for x.
*/
int GameOfLife::getXCoordinate(){
	return this->xCoordinate;
}

/**
	Purpose: Used to return the coordinates for y.
*/
int GameOfLife::getYCoordinate(){
	return this->yCoordinate;
}

/**
	Purpose: Create the first matrix.
*/
void GameOfLife::setBaseMatrix(){
	this->baseMatrix = new char*[getGridWidth()];
	for (int i = 0; i < getGridWidth(); i++)
		baseMatrix[i] = new char[getGridHeight()];
}

/**
	Purpose: Initialise the first matrix.
*/
void GameOfLife::fillBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++)
		for (int j = 0; j < getGridHeight(); j++)
			baseMatrix[i][j] = ' ';
}

/**
	Purpose: Prints the first matrix.
*/
void GameOfLife::printBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		std::cout << std::endl;
		for (int j = 0; j < getGridHeight(); j++){
			std::cout << baseMatrix[i][j] << " ";
		}
	}

}

/**
	Purpose: Used to dealocate memory
*/
void GameOfLife::deleteBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		delete[] baseMatrix[i];
	}
	delete[] baseMatrix;
}

/**
	Purpose: Create the second matrix.
*/
void GameOfLife::setNextMatrix(){
	this->nextMatrix = new char*[getGridWidth()];
	for (int i = 0; i < getGridWidth(); i++)
		nextMatrix[i] = new char[getGridHeight()];
}

/**
	Purpose: Initialise the second matrix.
*/
void GameOfLife::fillNextMatrix(){
	for (int i = 0; i < getGridWidth(); i++)
		for (int j = 0; j < getGridHeight(); j++)
			nextMatrix[i][j] = ' ';
}

/**
	Purpose: Prints the second matrix.
*/
void GameOfLife::printNextMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		std::cout << std::endl;
		for (int j = 0; j < getGridHeight(); j++){
			std::cout << nextMatrix[i][j] << " ";
		}
	}
}

/**
Purpose: Used to dealocate memory
*/
void GameOfLife::deleteNextMatrix(){
	for (int i = 0; i < getGridHeight(); i++){
		delete[] nextMatrix[i];
	}
	delete[] nextMatrix;
}

/**
	Purpose: At given matrix coordinates, we set '*'.
*/
void GameOfLife::setCoordinatesToMatrix(){
	baseMatrix[getXCoordinate()][getYCoordinate()] = { '*' };
}

/**
	Purpose: Set the number of coordinates.
*/
void GameOfLife::setNumberOfCoordinates(){
	while ((std::cout << "Number of coordinates: ") && !(std::cin >> this->coordinatesNumber)){
		checkInputStream();
	}
}

/**
	Purpose: Return the number of coordinates.
*/
int GameOfLife::getNumberOfCoordinates(){
	return this->coordinatesNumber;
}

/**
	Purpose: Counts every set consisting of two coordinates (x, y).
*/
void GameOfLife::countCoordinatesMessage(int i){
	std::cout << "\nSet " << i << " of coordinates" << std::endl;
}

/**
	Purpose: By iterating until number of coordinates, we are setting the coordinates.
*/
void GameOfLife::setCoordinates(){
	for (int i = 0; i < getNumberOfCoordinates(); i++){
		countCoordinatesMessage(i);
		setXCoordinate();
		setYCoordinate();
		setCoordinatesToMatrix();
	}
}


/**
	Purpose: The user needs to choose, between two input modes: either set the pattern manually by setting coordinates for every point,
			 either uses a list of patterns, and give only starting coordinates point
*/
void GameOfLife::patternInputMethodMessage(){
	std::cout << "\nChoose pattern input method: \n \t 1.Set the pattern manually. \n \t 2.Load from a list of existing patterns." << std::endl;
}

/**
	Purpose: Ask the user for pattern input method, and return this value.
*/
void GameOfLife::setPatternInputMethod(){
	while ((std::cout << "In: ") && !(std::cin >>methodInput)){
		checkInputStream();
	}
}

/**
Purpose: Gets the value for pattern input method
*/
int GameOfLife::getPatternInputMethod(){
	return methodInput;
}

/**
	Purpose: Prints a message if pattern input method does not exist.
*/
void GameOfLife::inputPatternUnavailableMessage(){
	std::cout << "The input method does not exist. Would you like to try again? (Y/N)" << std::endl;
}


/**
	Purpose: Checks if the user choses one of the two pattern input methods.
*/
void GameOfLife::checkInputPatternAvailability(){
	while (getPatternInputMethod() > 2 || getPatternInputMethod() < 1){
		inputPatternUnavailableMessage();
		setCondition();
		checkInputPatternCondition();
	}
}

/**
	Purpose: A switch case where we chose a different flow for our game, depending on pattern input method
*/
void GameOfLife::patternInputMethod(){
	setPatternInputMethod();

	int in = getPatternInputMethod();
	switch (in){
	case 1: setNumberOfCoordinates();
		setCoordinates();
		break;
	case 2: shapeMethodPackage();
		break;
	default:checkInputPatternAvailability();
		break;
	}
}

/**
	Purpose: A switch case where we choose from a list of availavle shapes, stored in Enumeration structure.
*/
void GameOfLife::availablePatterns(){
	int x = getDesiredShapeValue();
	switch (x){
	case block:		
		blockShape();
		break;
	case boat:		
		boatShape();
		break;
	case blinker:	
		blinkerShape();
		break;
	case beacon:	
		beaconShape();
		break;
	case pulsar:	
		pulsarShape();
		break;
	case pentadecathlon:
		pentadecathlonShape();
		break;
	case glider:	
		gliderShape();
		break;
	case cvadra_blinker: 
		cvadraBlinkerShape();
		break;
	default:
		break;
	}
}

/**
	Purpose: If a shape is unavailable, then we warn the user about that.
*/
void GameOfLife::unavailableShapeMessage(){
	std::cout << "Shape does not exist, would you like to try again? (Y/N) " << std::endl;
}

/**
	Purpose: Checks if values for every shape, are in range.
*/
void GameOfLife::checkShapeAvailability(){
	while (getDesiredShapeValue() >= Shapes::last_item || getDesiredShapeValue() < 0){
		unavailableShapeMessage();
		setCondition();
		checkShapeCondition();
	}
}

/**
	Purpose: This method is used to make a pack of methods that will be used in more than one place.
*/
void GameOfLife::shapeMethodPackage(){
	shapeMenu();
	setDesiredShapeValue();
	availablePatterns();
	checkShapeAvailability();
}

/**
	Purpose: The menu where we can see available shapes.
*/
void GameOfLife::shapeMenu(){
	std::cout << "0. Block\n1. Boat\n2. Blinker\n3. Beacon\n4. Pulsar\n5. Pentadecathlon\n6. Glider\n7. Cvadra_Blinker\n" << std::endl;
}

/**
	Purpose: Checks for an answer given by the user.
*/
void GameOfLife::checkShapeCondition(){
	char ch = checkForString();

	switch (toupper(ch)){
	case 'Y':
		shapeMethodPackage();
		break;
	case 'N':
		exit(0);
		break;
	default:
		break;
	}
}

/**
	Purpose: Checks for an answer given by the user. Even if those two check functions are duplicate, I didn't want
	to fix it, because I may improve my application and add unique content for any of them. So those two check methods
	will get fixed in the future.
*/
void GameOfLife::checkInputPatternCondition(){
	char ch = checkForString();

	switch (toupper(ch)){
	case 'Y':
		patternInputMethod();
		break;
	case 'N':
		exit(0);
		break;
	default:
		break;
	}
}

/**
	Purpose: Set a value who is used to pick a shape.
*/
void GameOfLife::setDesiredShapeValue(){
	while ((std::cout << "Pattern number: ") && !(std::cin >> chooseShapeNumber)){
		checkInputStream();
	}
}

/**
	Purpose: Return the value of the shape.
*/
int GameOfLife::getDesiredShapeValue(){
	return chooseShapeNumber;
}

/**
	Purpose: Method used to find the neighbours of each point.
*/
int GameOfLife::findNeighbours(int i, int j){
	for (int x = -1; x <= 1; x++){
		for (int y = -1; y <= 1; y++){
			if (baseMatrix[i + x][j + y] == '*'){
				counter++;
			}
			if ((x == 0 && y == 0) && baseMatrix[i][j] == '*')
				counter--;
		}
	}
	return counter;
}

/**
	Purpose: Method used to reset the counter.
*/
int GameOfLife::resetCounter(){
	return counter = 0;
}

/**
	Purpose: Method used to return the counter.
*/
int GameOfLife::returnCounter(){
	return counter;
}

/**
	Purpose: There is the set of four rules used to bring alive the game of live
*/
int GameOfLife::rules(int i, int j){
	if ((baseMatrix[i][j] == '*') && returnCounter() < 2){
		nextMatrix[i][j] = ' ';
	}
	else if ((baseMatrix[i][j] == '*') && returnCounter() > 3){
		nextMatrix[i][j] = ' ';
	}
	else if ((baseMatrix[i][j] == ' ') && returnCounter() == 3){
		nextMatrix[i][j] = '*';
	}
	else if ((baseMatrix[i][j] == '*') && ((returnCounter() == 2) || (returnCounter() == 3))){
		nextMatrix[i][j] = '*';
	}

	return 0;
}

/**
	Puspose: Print the matrix. Also uses a timer where we can set the speed of each transision.
			 By using 'system("cls")' we clear the screen.
*/
void GameOfLife::drawShapes(){
	printBaseMatrix();
	//printNextMatrix();
	std::this_thread::sleep_for(std::chrono::milliseconds(200));
	system("cls");
}

/**
	Purpose: We need two matrixes for this game. First is the initial matrix, and second is the next matrix who
	         stores a drawing based on first matrix coordinates. We need to assign second matrix, to first matrix 
			 in order to reach the next change in coordinates.
*/
void GameOfLife::interchangeMatrix(){
	for (int i = 1; i < getGridWidth() - 1; i++){
		for (int j = 1; j < getGridHeight() - 1; j++){
			baseMatrix[i][j] = nextMatrix[i][j];
		}
	}
}

/**
	Purpose: This function is where the game gets alive
*/
void GameOfLife::nucleusOfGame(){
	for (int i = 1; i < getGridWidth() - 1; i++){
		for (int j = 1; j < getGridHeight() - 1; j++){
			resetCounter();
			findNeighbours(i, j);
			rules(i, j);			
		}
	}
	drawShapes();
	interchangeMatrix();
}

/**
	Purpose: For every shape selected, we need to set only x and y coordinates, and the shape gets alive.
*/
void GameOfLife::startCoordinateMessage(){
	std::cout << "Please enter the start coordinates for selected shape: " << std::endl;
}

/**
	Purpose: Used to draw the a block shape :
												 *  *
												 *  *
*/
void GameOfLife::blockShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate() + 1] = '*';
}

/**
	Purpose: Used to draw a boat shape :
												*  *
												*     *
												   *
*/
void GameOfLife::boatShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate()] = ' ';
	baseMatrix[getXCoordinate() - 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() - 1] = '*';
	baseMatrix[getXCoordinate() - 1][getYCoordinate() - 1] = '*';
}

/**
Purpose: Used to draw a blinker shape :
											*                                     *
											*                 *  *  *             *
											*                                     *
*/
void GameOfLife::blinkerShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() - 1] = '*';
}

/**
Purpose: Used to draw a beacon shape :
										*  *                      *  *                   *  *
										*                         *  *                   *
										       *                     *  *                      *
										    *  *                     *  *                   *  *
*/
void GameOfLife::beaconShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate()] = ' ';
	baseMatrix[getXCoordinate() - 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate() - 1][getYCoordinate() - 1] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() - 1] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate() + 1] = ' ';
	baseMatrix[getXCoordinate() + 2][getYCoordinate() + 2] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate() + 2] = '*';
	baseMatrix[getXCoordinate() + 2][getYCoordinate() + 1] = '*';
}

/**
Purpose: Used to draw a pulsar shape :
													*                * 
													*                *    
													*  *          *  *                     
												
										  *  *  *      *  *    *  *       *  *  *
											    *   *     *    *     *    *
													*  *          *  * 

													*  *          *  *   
												*	*     *    *     *    *
										  *  *  *	   *  *    *  *       *  *  *

													*  *           *  *
													*		          *
													*				  *
*/    
void GameOfLife::pulsarShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	shapeShip1of2(0, 0);
	shapeShip1of2(4, 4);
	shapeShip2of2(0, 4);
	shapeShip2of2(4, 0);
	tetronimoShape1of8(-4, 0);
	tetronimoShape2of8(-4, 4);
	tetronimoShape3of8(0, 8);
	tetronimoShape4of8(4, 8);
	tetronimoShape5of8(8, 4);
	tetronimoShape6of8(8, 0);
	tetronimoShape7of8(4, -4);
	tetronimoShape8of8(0, -4);
}

/**
	Purpose: Draw a pentadecathlon shape:
											      *              * 
											*  *     *  *  *  *     *  * 
											      *              *
*/
void GameOfLife::pentadecathlonShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	cross(0, 0);
	cross(0, 5);
}

/**
	Purpose: Draw a glider shape:
										*
										   *
									 *  *  *
*/
void GameOfLife::gliderShape(){
		startCoordinateMessage();
		setXCoordinate();
		setYCoordinate();
		setCoordinatesToMatrix();
		baseMatrix[getXCoordinate()][getYCoordinate()] = ' ';
		baseMatrix[getXCoordinate() - 1][getYCoordinate()] = '*';
		baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
		baseMatrix[getXCoordinate() + 1][getYCoordinate() + 1] = '*';
		baseMatrix[getXCoordinate() + 1][getYCoordinate()] = '*';
		baseMatrix[getXCoordinate() + 1][getYCoordinate() - 1] = '*';
}

/**
Purpose: Draw a shape that advances to cvadra blinker shape:
												*
										     *  *  *
*/
void GameOfLife::cvadraBlinkerShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate() - 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() - 1] = '*';
}

int GameOfLife::tetronimoShape1of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';

	return 0;
}

int GameOfLife::tetronimoShape2of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';

	return 0;
}

int GameOfLife::tetronimoShape3of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) + 1] = '*';

	return 0;
}

int GameOfLife::tetronimoShape4of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) + 1] = '*';

	return 0;
}

int GameOfLife::tetronimoShape5of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) + 1] = '*';

	return 0;
}

int GameOfLife::tetronimoShape6of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) - 1] = '*';

	return 0;
}

int GameOfLife::tetronimoShape7of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';

	return 0;
}

int GameOfLife::tetronimoShape8of8(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';

	return 0;
}

int GameOfLife::shapeShip1of2(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';

	return 0;
}

int GameOfLife::shapeShip2of2(int i, int j){
	baseMatrix[(getXCoordinate() + i)][getYCoordinate() + j] = ' ';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';

	return 0;
}

int GameOfLife::cross(int i, int j){
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j)] = ' ';
	baseMatrix[(getXCoordinate() + i) - 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 1] = '*';
	baseMatrix[(getXCoordinate() + i) + 1][(getYCoordinate() + j)] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 1] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) - 2] = '*';
	baseMatrix[(getXCoordinate() + i)][(getYCoordinate() + j) + 2] = '*';

	return 0;
}



/**
	Purpose: And this is the end, the method who control everything in my game.
*/
void GameOfLife::motherboard(){
	gridSizeMessage();
	setGridWidth();
	setGridHeight();
	gridDimensionsMessage();
	checkGridSize();
	setBaseMatrix();
	fillBaseMatrix();
	patternInputMethodMessage();
	patternInputMethod();
	setNextMatrix();
	fillNextMatrix();


	while (true){
		nucleusOfGame();
	}

	// These two delete functions will not execute since while loop.
	deleteBaseMatrix(); 
	deleteNextMatrix();

	system("pause");
}
