#pragma once
#include "Object.h"
enum class Obstacle { Rock, SmallFlower, BigFlower};

class StaticObject: public Object
{
private:
	Obstacle obstacle;

public:
	StaticObject(int id, Obstacle obstacle) : Object(id) { this->obstacle = obstacle; }
	Obstacle GetObstacle() const { return obstacle; }
};

