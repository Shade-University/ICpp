#pragma once
#include "MovingObject.h"

class Monster : public MovingObject
{
private:
	int hp;
	int maxHp;
public:
	Monster(int id, int hp, int maxHp) : MovingObject(id) { this->hp = hp; this->maxHp = maxHp; }

	void SetHp(int hp) { this->hp = hp; }
	double GetHp() const { return hp; }

	void SetMaxHp(int maxHp) { this->maxHp = maxHp; }
	double GetMaxHp() const { return maxHp; }
};

