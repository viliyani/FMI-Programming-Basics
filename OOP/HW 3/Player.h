#pragma once
#include "Entity.h"

class Player : public Entity {
private:
	int damage;
	int health;
public:
	bool isAlive() const;
	void attack();
};