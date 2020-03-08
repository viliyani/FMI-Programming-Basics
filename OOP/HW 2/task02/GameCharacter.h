#pragma once
#include <iostream>
using namespace std;

class GameCharacter {
private:
	GameCharacter();
	char * name = nullptr;
	int pointsLife;
	int pointsMagic;
	int pointsAttack;
	int pointsDefense;
protected:
	GameCharacter(const char * namePar, int pointsLifePar, int pointsMagicPar, int pointsAttackPar, int pointsDefensePar);
	~GameCharacter();
public:
	void setName(const char * namePar);

	const char * getName() const;
	int getPointsLife() const;
	int getPointsMagic() const;
	int getPointsAttack() const;
	int getPointsDefense() const;

	void getattacked(int enemyPointsAttack);

	void print() const;

};