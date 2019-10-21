#include "Game.h"

int Game::MAX_OBJECTS = 20;
int Game::OBJECT_COUNT = 0;

Game::Game() 
{
	objects = new Object*[MAX_OBJECTS];
	/*for (int i = 0; i < ROWS; i++)
	{
		objects[i] = nullptr;
	}*/
}
Game::~Game()
{
	delete[] objects;
}
bool Game::isInRange(Object* object, double xmin, double xmax, double ymin, double ymax)
{
	return object->GetX() > xmin && object->GetX() < xmax
		&& object->GetY() > ymin&& object->GetY() < ymax;
}
bool Game::isInRange(Object* object, double x, double y, double r)
{
	return pow(object->GetX() - x, 2) + pow(object->GetY() - y, 2) < pow(r, 2);
}
bool Game::isInRange(MovingObject* object, double x, double y, double r, double umin, double umax)
{
	return isInRange(object, x, y, r) && object->GetAngleRotation() > umin&& object->GetAngleRotation() < umax;
}
void Game::AddObject(Object* o)
{
	if (OBJECT_COUNT + 1 > MAX_OBJECTS) 
	{
		throw std::out_of_range("Array oversized");
	}

	objects[OBJECT_COUNT++] = o;
}
int* Game::FindIdStaticObjects(double xmin, double xmax, double ymin, double ymax)
{
	//Nenapadl mì lepší zpùsob jak to udìlat s polema.
	int found = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr && isInRange(objects[i], xmin, xmax, ymin, ymax)) 
		{
			found++;
		}
	}

	if (found == 0)
	{
		return nullptr;
	}

	int* output = new int[found];
	int counter = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		StaticObject* so = dynamic_cast<StaticObject*>(objects[i]);
		if (so != nullptr && isInRange(objects[i], xmin, xmax, ymin, ymax))
		{
			output[counter++] = so->GetId();
		}
	}

	return output;
}

MovingObject** Game::FindMovingObjectsInRange(double x, double y, double r)
{
	int found = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
		if (so != nullptr && isInRange(objects[i], x, y, r))
		{
			found++;
		}
	}

	if (found == 0)
	{
		return nullptr;
	}

	MovingObject** output = new MovingObject * [found];
	int counter = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
		if (so != nullptr && isInRange(objects[i], x, y, r))
		{
			output[counter++] = so;
		}
	}

	return output;
}
MovingObject** Game::FindMovingObjectsInRange(double x, double y, double r, double umin, double umax)
{
	int found = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
		if (so != nullptr && isInRange(so, x, y, r, umin, umax))
		{
			found++;
		}
	}

	if (found == 0)
	{
		return nullptr;
	}

	MovingObject** output = new MovingObject * [found];
	int counter = 0;
	for (int i = 0; i < OBJECT_COUNT; i++)
	{
		MovingObject* so = dynamic_cast<MovingObject*>(objects[i]);
		if (so != nullptr && isInRange(so, x, y, r, umin, umax))
		{
			output[counter++] = so;
		}
	}

	return output;
}

