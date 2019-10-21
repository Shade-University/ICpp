#include <iostream>
#include "Game.h"
#include "StaticObject.h"
#include "Monster.h"

#define PI	3.14
int main()
{
	Game game;
	Object* rock = new StaticObject(1, Obstacle::Rock);
	rock->SetX(5);
	rock->SetY(5);

	Object* bigFlower = new StaticObject(2, Obstacle::BigFlower);
	bigFlower->SetX(10);
	bigFlower->SetY(15);

	Object* smallFlower = new StaticObject(3, Obstacle::SmallFlower);
	smallFlower->SetX(25);
	smallFlower->SetY(50);

	Object* monster = new Monster(4, 20, 20);
	monster->SetX(10);
	monster->SetY(10);
	MovingObject* monsterWithAngle = new Monster(5, 20, 20);
	monsterWithAngle->SetX(20);
	monsterWithAngle->SetY(20);
	monsterWithAngle->SetAngleRotation(PI);


	game.AddObject(rock);
	game.AddObject(bigFlower);
	game.AddObject(smallFlower);
	game.AddObject(monster);
	game.AddObject(monsterWithAngle);

	int* ids = game.FindIdStaticObjects(0, 100, 0, 100); //Takhle ale nevíme velikost pole
	MovingObject** movingObject = game.FindMovingObjectsInRange(10, 10, 10);
	MovingObject** movingObjectWithAngle = game.FindMovingObjectsInRange(20, 20, 10, 0, 2 * PI);
	std::cout << "First id of static object: " << ids[0] << std::endl;
	std::cout << "Second id of static object: " << ids[1] << std::endl;
	std::cout << "First moving object found: " << movingObject[0]->toString() << std::endl;
	std::cout << "Moving object with angle: " + movingObjectWithAngle[0]->toString();
	std::cin.get();
}
