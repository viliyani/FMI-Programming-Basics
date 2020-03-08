#include "Entity.h"
#include <typeinfo> 

Entity::Entity(std::string namePar, Point2D locationPar, EntityType entityTypePar)
{
	id = nextID++;
	name = namePar;
	location = locationPar;
	entityType = entityTypePar;
}

bool Entity::isAlive() const
{
	return true;
}

double Entity::getDistanceTo2D(const Entity & obj) const
{
	return location.getDistanceTo(obj.location);
}

double Entity::getDistanceTo(const Entity & obj) const
{
	if (typeid(obj) == typeid(Point2D) || typeid(obj) == typeid(Point2D))
	{
		return location.getDistanceTo(obj.location);
	}
	else {
		return location.getDistanceTo(obj.location);
	}
}

void Entity::moveTo(const Point2D & obj)
{
	location = obj;
}

void Entity::moveTo(const Entity & obj)
{
	location = obj.location;
}

