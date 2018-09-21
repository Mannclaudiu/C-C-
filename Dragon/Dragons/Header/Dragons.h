#pragma once

#include <iostream>
#include <vector>
#include <string>


/*******************************************
* Write your implementation starting here.
* Read documentation for further details.
*******************************************/

#ifdef LIBRARY_EXPORT
#define DRAGONS_API __declspec(dllexport)
#else
#define DRAGONS_API __declspec(dllimport)
#endif

class DRAGONS_API Creature
{
	/*******************************************
	* Write your implementation starting here.
	* Read documentation for further details.
	*******************************************/
protected:
	/*
		Purpose: Creature's name
	*/
	const std::string name;

	/*
		Purpose: Creature's level
	*/
	int level;

	/*
		Purpose: Creature's number of health points
	*/
	int lifePoints;

	/*
		Purpose: Creature's force
	*/
	int force;

	/*
		Purpose: Creature's position
	*/
	int position;

	/*
		Purpose: friend classes, in order to acces protected members of this class.
	*/
	friend class Dragon;
	friend class Hidra;

public:
	/*
		Purpose: a constructor allowing the initialization of the name, level, health points, 
		force and position of the creature using the values passed as parameters, in this order; 
		the constructor accepts zero as default value for the position;
	*/
	Creature(const std::string _name, int _level, int _lifePoints, int _force, int _position);
	Creature(){};
	~Creature();

	/*
		Purpose: a method bool isAlive() returning true if the creature is alive 
		(number of health points greater than zero) or false otherwise;
	*/
	bool isAlive();

	/*
		Purpose:a method attackPoints returning the number of attack points that can be inflicted by 
		the creature to others; the value is computed as the level multiplied by the force if the creature 
		is alive, or zero otherwise;
	*/
	int attackPoints();

	/*
		Purpose: a method move(int), which does not return anything and adds the integer passed as parameter
		to the position of the creature;
	*/
	void move(int value);

	/*
		Purpose: a method isDead(), which does not return anything and displays the message (<name> is no more!) 
		using strictly this format. <name> is the name of the creature;
	*/
	void isDead();

	/*
		Purpose: a method weaken(int), which does not return anything and substracts the number of points passed
		as parameter from the number of health points of the creature, if it is alive; if the creature dies, 
		its number of health points is set to zero and the method isDead is called;
	*/
	void weaken(int value);

	/*
		Purpose: a method showData(), which does not return anything and displays information about the creature
	*/
	void showData();

	/*
		Purpose: A method returning the position of the creature.
	*/
	int getPosition();
};


class DRAGONS_API Dragon : public Creature{
private:

	/*
		Purpose: Dragon's rage of flame
	*/
	int flameRange;
public:
	/*
		Purpose: A constructor which initializes its name, level, number of health points, the force, 
		the range of the flame and the position of the dragon using the values passed as parameters, 
		in this order; the constructor accepts zero as default value for the position;	
	*/
	Dragon(const std::string _name, int _level, int _lifePoints, int _force, int _flameRange, int _position);
	Dragon();
	~Dragon();

	/*
		Purpose:  method fly(int pos) which does not return anything and allows the dragon to move
		to the given position pos;
	*/
	void fly(int pos);

	/*
		Purpose: a method breathOn(Creature& enemy) which does not return anything and simulates what happens
		when the dragon blows its flame towards another Creature:
			1. If the dragon and the creature are both alive and if the creature is in range of its flame, the dragon 
			   inflicts its attack points as damage to the creature; the creature weakens by the number of attack points;
			2. The dragon also weakens; it loses n health points, with n being the distance between the dragon and 
			   the creature (the further the dragon has to blow, the more it weakens);
			3. If after this epic fight the dragon is still alive and the creature dies, the dragon increases in level
			   by one unit;
		The creature is in the range of the flame of the dragon if the distance between them is smaller or equal to the range
		of the flame.
	*/
	void breathOn(Creature &enemy);
};

class DRAGONS_API Hidra : public Creature{
private:
	/*
		Purpose: Hidra's length of the neck
	*/
	int neckLength;

	/*
		Purpose: Hidra's dose of poison
	*/
	int poisonDose;

public:
	/*
		Purpose: a constructor which initializes its name, level, number of health points, force, the length of its neck, 
		the poison dose and the position using the values passed as parameters, in this order; 
		the constructor accepts zero as default value for the position;
	*/
	Hidra(const std::string _name, int _level, int _lifePoints, int _force, int _neckLength, int _poisonDose, int _position);
	Hidra();
	~Hidra();

	/*
		Poison: a method injectPoison(Creature& enemy) which does not return anything and simulates what happens
		when the hydra poisons another Creature:
			1. If the hydra and the creature are alive and the creature is in range of the head of the hydra, 
		       then the hydra inflicts damage to the creature; the creature weakens by the number of attack points 
			   of the hydra plus its dose of poison;
			2. The creature is “in range of the head of the hydra” if the distance the creature and the hydra is smaller
			   or equal to the length of the neck of the hydra.
            3. If at the end of the fight the creature is no longer alive, the hydra increases in level by one unit;
	*/
	void injectPoison(Creature &enemy);
};