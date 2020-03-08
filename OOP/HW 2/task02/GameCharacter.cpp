#define _CRT_SECURE_NO_WARNINGS
#include "GameCharacter.h"
#include <cstring>
using namespace std;

GameCharacter::GameCharacter() : pointsLife(0), pointsMagic(0), pointsAttack(0), pointsDefense(0)
{
	setName(" ");
}

GameCharacter::GameCharacter(const char * namePar, int pointsLifePar, int pointsMagicPar, int pointsAttackPar, int pointsDefensePar) : pointsLife(pointsLifePar), pointsMagic(pointsMagicPar), pointsAttack(pointsAttackPar), pointsDefense(pointsDefensePar)
{
	setName(namePar);
}

GameCharacter::~GameCharacter()
{
	delete[] name;
}

void GameCharacter::setName(const char * namePar)
{
	if (namePar == nullptr) {
		cout << "Error! Nullptr!" << endl;
		return;
	}

	delete[] name;

	name = new char[strlen(namePar) + 1];
	strcpy(name, namePar);
}

const char * GameCharacter::getName() const
{
	return name;
}

int GameCharacter::getPointsLife() const
{
	return pointsLife;
}

int GameCharacter::getPointsMagic() const
{
	return pointsMagic;
}

int GameCharacter::getPointsAttack() const
{
	return pointsAttack;
}

int GameCharacter::getPointsDefense() const
{
	return pointsDefense;
}

void GameCharacter::getattacked(int enemyPointsAttack)
{
	int result = enemyPointsAttack - pointsDefense;

	if (result > 0) {
		pointsLife -= result;
	}
}

void GameCharacter::print() const
{
	cout << endl;
	cout << "___ Game Character ___" << endl;
	cout << "Name: " << name << endl;
	cout << "Points Life: " << pointsLife << endl;
	cout << "Points Magic: " << pointsMagic << endl;
	cout << "Points Attack: " << pointsAttack << endl;
	cout << "Points Defense: " << pointsDefense << endl;
	cout << endl;
}
