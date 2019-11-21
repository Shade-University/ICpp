#include "Template.h"

class PipeComponent : public APipeComponent
{
private:
	char _value;
public:
	PipeComponent(int x, int y, char value) { _x = x; _y = y; _value = value; }
	bool IsConnectionValid(const IPipe* pipe) const
	{
		bool valid = true;
			switch (_value)
			{
			case '-':
				if (pipe->GetComponent(_x - 1, _y) == nullptr && pipe->GetComponent(_x + 1, _y) == nullptr)
					valid = false;
				break;
			case 'I':
				if (pipe->GetComponent(_x, _y - 1) == nullptr && pipe->GetComponent(_x, _y + 1) == nullptr)
					valid = false;
				break;
			case '+':
				if (pipe->GetComponent(_x - 1, _y) == nullptr && pipe->GetComponent(_x + 1, _y) == nullptr
					&& pipe->GetComponent(_x, _y - 1) == nullptr && pipe->GetComponent(_x, _y + 1) == nullptr)
					valid = false;
				break;
			case 'O':
				break;
			case 'T':
				if (pipe->GetComponent(_x - 1, _y) == nullptr && pipe->GetComponent(_x + 1, _y) == nullptr && pipe->GetComponent(_x, _y - 1) == nullptr)
					valid = false;
				break;
			default:
				break;
			}

			return valid;
		}
};