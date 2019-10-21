#pragma once
#include "Object.h"
#include <string>

class MovingObject : public Object
{
private:
	double angleRotation;
public:
	MovingObject(int id) : Object(id) { angleRotation = 0; }

	void SetAngleRotation(double angleRotation) { this->angleRotation = angleRotation; }
	double GetAngleRotation() const { return angleRotation; }
	std::string toString() const {
		return "Moving object, angleRotation: " + std::to_string(angleRotation);
	}
};

