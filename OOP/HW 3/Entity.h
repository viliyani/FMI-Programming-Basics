#pragma once
#include <string>
#include <iostream>
#include "Enums.h"
#include "Point2D.h"

class Entity {
protected:
	static int nextID;
	int id;
	std::string name;
	Point2D location;
	EntityType entityType;
public:
	Entity(std::string namePar, Point2D locationPar, EntityType entityTypePar);
	Entity() {
		id = nextID++;
	}
	virtual bool isAlive() const;

	virtual void attack() = 0;

	double getDistanceTo2D(const Entity & obj) const;
	double getDistanceTo(const Entity & obj) const;

	void moveTo(const Point2D & obj);
	void moveTo(const Entity & obj);

};