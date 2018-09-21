#include "Dragons.h"

using namespace std;

/*
	Purpose: Function used to compute the distance between a creature and an enemy creature
*/
int computeDistance(int x, int y)
{
	return abs(x - y);
}

Creature::Creature(const std::string _name, int _level, int _lifePoints, int _force, int _position)
	:name(_name), level(_level), lifePoints(_lifePoints), force(_force), position(_position){
}


Creature::~Creature(){

}

bool Creature::isAlive(){
	if (this->lifePoints > 0)
		return true;
	else
		return false;
}

int Creature::attackPoints(){
	int attack = 0;
	if (isAlive()){
		attack = level * force;
		return attack;
	}
	else
		return attack;
}

void Creature::move(int value){
	this->position += value;
}

void Creature::isDead(){
	std::cout << name << " is no more! " << std::endl;
}

void Creature::weaken(int value){
	if (isAlive()){
		lifePoints -= value;
		if (lifePoints < 0){
			lifePoints = 0;
			isDead();
		}
	}
	else return;

}

void Creature::showData(){
	std::cout << this->name << ", level: "
		<< this->level << ", life points: "
		<< this->lifePoints << ", force: "
		<< this->force
		<< ", attack points: " << attackPoints()
		<< ", position: " << this->position << std::endl;
}

Dragon::Dragon(const std::string _name, int _level, int _lifePoints, int _force, int _flameRange, int _position = 0)
	:Creature(_name, _level, _lifePoints, _force, _position), flameRange(_flameRange){
}

Dragon::Dragon(){

}

Dragon::~Dragon(){

}

void Dragon::fly(int pos){
	this->move(pos);
}


Hidra::Hidra(const std::string _name, int _level, int _lifePoints, int _force, int _neckLength, int _poisonDose, int _position = 0)
	:Creature(_name, _level, _lifePoints, _force, _position), neckLength(_neckLength), poisonDose(_poisonDose){
}

Hidra::Hidra(){

}

Hidra::~Hidra(){

}

void Dragon::breathOn(Creature &enemy){
	if (!enemy.isAlive())
		return;
	else if ((enemy.isAlive() && this->lifePoints > 0) && (computeDistance(position, enemy.position) <= flameRange)){
		enemy.weaken(attackPoints());
		lifePoints -= computeDistance(position, enemy.position);
	}
	if (!enemy.isAlive()){
		this->level += 1;
	}
}

void Hidra::injectPoison(Creature &enemy){
	if (!enemy.isAlive())
		return;
	else if ((enemy.isAlive() && this->lifePoints > 0) && (computeDistance(position, enemy.position) <= neckLength))
		enemy.weaken(attackPoints() + poisonDose);
	if (!enemy.isAlive())
		this->level += 1;

}


int Creature::getPosition(){
	return position;
}

