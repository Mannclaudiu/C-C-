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

void GameOfLife::gridSizeMessage(){
	std::cout << "Please enter the grid size (at least 20x20): " << std::endl;
}

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

int GameOfLife::getGridWidth(){
	return this->gridWidth;
}

int GameOfLife::getGridHeight(){
	return this->gridHeight;
}

void GameOfLife::setCondition(){
	while (!(std::cin >> this->condition)){
		checkInputStream();
	}
}

std::string GameOfLife::getCondition(){
	return this->condition;
}

void GameOfLife::gridDimensionsMessage(){
	std::cout << "The grid size is: " << getGridWidth() << " x " << getGridHeight() << std::endl;
}

void GameOfLife::checkGridSize(){
		while ((getGridWidth() < defaultGridSize) || (getGridHeight() < defaultGridSize)){
			checkGridSizeMessage();
			setCondition();
			gridSizeFlowControl();
			gridDimensionsMessage();
		}
}

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

void GameOfLife::checkGridSizeMessage(){
	std::cout << "\nThe dimmension of grid is too small. Would you like to try again? (Y/N)" << std::endl;
}

void GameOfLife::checkInputStream(){
	std::cout << "Invalid input, please try again " << std::endl;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cout << std::endl;
}

char GameOfLife::checkForString(){
	std::string str = getCondition();
	if (str.length() != 1)
		return 0;
	else 
		return str[0];
}

void GameOfLife::setXCoordinate(){
	while ((std::cout << "xCoordinate: ") && !(std::cin >> this->xCoordinate)){
		checkInputStream();
	}
}

void GameOfLife::setYCoordinate(){
	while ((std::cout << "yCoordinate: ") && !(std::cin >> this->yCoordinate)){
		checkInputStream();
	}
}

int GameOfLife::getXCoordinate(){
	return this->xCoordinate;
}

int GameOfLife::getYCoordinate(){
	return this->yCoordinate;
}

void GameOfLife::setBaseMatrix(){
	this->baseMatrix = new char*[getGridWidth()];
	for (int i = 0; i < getGridWidth(); i++)
		baseMatrix[i] = new char[getGridHeight()];
}

void GameOfLife::fillBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++)
		for (int j = 0; j < getGridHeight(); j++)
			baseMatrix[i][j] = ' ';
}

void GameOfLife::printBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		std::cout << std::endl;
		for (int j = 0; j < getGridHeight(); j++){
			std::cout << baseMatrix[i][j] << " ";
		}
	}

}

void GameOfLife::deleteBaseMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		delete[] baseMatrix[i];
	}
	delete[] baseMatrix;
}

void GameOfLife::setNextMatrix(){
	this->nextMatrix = new char*[getGridWidth()];
	for (int i = 0; i < getGridWidth(); i++)
		nextMatrix[i] = new char[getGridHeight()];
}

void GameOfLife::fillNextMatrix(){
	for (int i = 0; i < getGridWidth(); i++)
		for (int j = 0; j < getGridHeight(); j++)
			nextMatrix[i][j] = ' ';
}

void GameOfLife::printNextMatrix(){
	for (int i = 0; i < getGridWidth(); i++){
		std::cout << std::endl;
		for (int j = 0; j < getGridHeight(); j++){
			std::cout << nextMatrix[i][j] << " ";
		}
	}
}

void GameOfLife::deleteNextMatrix(){
	for (int i = 0; i < getGridHeight(); i++){
		delete[] nextMatrix[i];
	}
	delete[] nextMatrix;
}

void GameOfLife::setCoordinatesToMatrix(){
	baseMatrix[getXCoordinate()][getYCoordinate()] = { '*' };
}

void GameOfLife::setNumberOfCoordinates(){
	while ((std::cout << "Number of coordinates: ") && !(std::cin >> this->coordinatesNumber)){
		checkInputStream();
	}
}

int GameOfLife::getNumberOfCoordinates(){
	return this->coordinatesNumber;
}

void GameOfLife::countCoordinatesMessage(int i){
	std::cout << "\nSet " << i << " of coordinates" << std::endl;
}

void GameOfLife::setCoordinates(){
	for (int i = 0; i < getNumberOfCoordinates(); i++){
		countCoordinatesMessage(i);
		setXCoordinate();
		setYCoordinate();
		setCoordinatesToMatrix();
	}
}


void GameOfLife::patternInputMethodMessage(){
	std::cout << "\nChoose pattern input method: \n \t 1.Set the pattern manually. \n \t 2.Load from a list of existing patterns." << std::endl;
}

void GameOfLife::setPatternInputMethod(){
	while ((std::cout << "In: ") && !(std::cin >>methodInput)){
		checkInputStream();
	}
}

int GameOfLife::getPatternInputMethod(){
	return methodInput;
}

void GameOfLife::inputPatternUnavailableMessage(){
	std::cout << "The input method does not exist. Would you like to try again? (Y/N)" << std::endl;
}


void GameOfLife::checkInputPatternAvailability(){
	while (getPatternInputMethod() > 2 || getPatternInputMethod() < 1){
		inputPatternUnavailableMessage();
		setCondition();
		checkInputPatternCondition();
	}
}

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

void GameOfLife::unavailableShapeMessage(){
	std::cout << "Shape does not exist, would you like to try again? (Y/N) " << std::endl;
}

void GameOfLife::checkShapeAvailability(){
	while (getDesiredShapeValue() >= Shapes::last_item || getDesiredShapeValue() < 0){
		unavailableShapeMessage();
		setCondition();
		checkShapeCondition();
	}
}

void GameOfLife::shapeMethodPackage(){
	shapeMenu();
	setDesiredShapeValue();
	availablePatterns();
	checkShapeAvailability();
}

void GameOfLife::shapeMenu(){
	std::cout << "0. Block\n1. Boat\n2. Blinker\n3. Beacon\n4. Pulsar\n5. Pentadecathlon\n6. Glider\n7. Cvadra_Blinker\n" << std::endl;
}

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

void GameOfLife::setDesiredShapeValue(){
	while ((std::cout << "Pattern number: ") && !(std::cin >> chooseShapeNumber)){
		checkInputStream();
	}
}

int GameOfLife::getDesiredShapeValue(){
	return chooseShapeNumber;
}

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

int GameOfLife::resetCounter(){
	return counter = 0;
}

int GameOfLife::returnCounter(){
	return counter;
}

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

void GameOfLife::drawShapes(){
	printNextMatrix();
	std::this_thread::sleep_for(std::chrono::milliseconds(CONST_SLEEP));
	system("cls");
}

void GameOfLife::interchangeMatrix(){
	for (int i = 1; i < getGridWidth() - 1; i++){
		for (int j = 1; j < getGridHeight() - 1; j++){
			baseMatrix[i][j] = nextMatrix[i][j];
		}
	}
}

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

void GameOfLife::startCoordinateMessage(){
	std::cout << "Please enter the start coordinates for selected shape: " << std::endl;
}

void GameOfLife::blockShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate()] = '*';
	baseMatrix[getXCoordinate() + 1][getYCoordinate() + 1] = '*';
}

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

void GameOfLife::blinkerShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	baseMatrix[getXCoordinate()][getYCoordinate() + 1] = '*';
	baseMatrix[getXCoordinate()][getYCoordinate() - 1] = '*';
}

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

void GameOfLife::pentadecathlonShape(){
	startCoordinateMessage();
	setXCoordinate();
	setYCoordinate();
	setCoordinatesToMatrix();
	cross(0, 0);
	cross(0, 5);
}

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