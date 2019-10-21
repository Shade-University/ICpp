#pragma once
class Object
{
private:
	int id;
	double x;
	double y;
public:
	Object(int id) { this->id = id; x = 0; y = 0; }
	virtual ~Object() { }

	int GetId() const { return id; }

	void SetX(double x) { this->x = x; }
	int GetX() const { return  x; }

	void SetY(double y) { this->y = y; }
	int GetY() const { return  y; }

};

