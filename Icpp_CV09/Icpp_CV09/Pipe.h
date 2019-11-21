#include <vector>
#include "Template.h"


class Pipe : public IPipe {
private:
	std::vector<APipeComponent*> _vect;
public:
	Pipe(std::vector<APipeComponent*> vect) : _vect(vect) { };
	const APipeComponent* GetComponent(int x, int y) const
	{
		for (APipeComponent* c : _vect)
		{
			if (c->_x == x && c->_y == y)
			{
				return c;
			}
		}

		return nullptr;
	}
	bool IsPipeValid() const
	{
		bool valid = true;
		for (APipeComponent* c : _vect)
		{
				if (!c->IsConnectionValid(this))
				{
					valid = false;
				}
		}

		return valid;
	}
};