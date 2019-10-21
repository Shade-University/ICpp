#pragma once
#include <stdexcept>
#include "Object.h"
#include "MovingObject.h"
#include "StaticObject.h"
class Game
{
private:
	static int OBJECT_COUNT;
	static int MAX_OBJECTS;
	Object** objects;
	bool isInRange(Object* object, double xmin, double xmax, double ymin, double ymax);
	bool isInRange(Object* object, double x, double y, double r);
	bool isInRange(MovingObject* object, double x, double y, double r, double umin, double umax);
public:
	Game();
	~Game();
	void AddObject(Object* o);
	int* FindIdStaticObjects(double xmin, double xmax, double ymin, double ymax);
	MovingObject** FindMovingObjectsInRange(double x, double y, double r);
	MovingObject** FindMovingObjectsInRange(double x, double y, double r, double umin, double umax);

};

