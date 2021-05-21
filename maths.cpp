#include "maths.h"

// Operation(Type::
std::vector<std::vector<Operation>> types = {
	{
		Operation(Type::Plus, 3),
		Operation(Type::Times, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 3),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Times, 2),
		Operation(Type::Plus, 10),
		Operation(Type::Divide, 2),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 2),
		Operation(Type::Times, 2),
		Operation(Type::Plus, 1),
		Operation(Type::Minus),
		Operation(Type::Plus, 3),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 3),
		Operation(Type::Times, 2),
		Operation(Type::Minus, 1),
		Operation(Type::Divide, 2),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 5),
		Operation(Type::Times, 4),
		Operation(Type::Divide, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 4),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Times, 2),
		Operation(Type::Plus, 2),
		Operation(Type::Minus, 4),
		Operation(Type::Divide, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 3)
	},
	{
		Operation(Type::Times, 4),
		Operation(Type::Plus, 9),
		Operation(Type::Minus),
		Operation(Type::Divide, 3),
		Operation(Type::Plus, 2),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 8),
		Operation(Type::Minus, 2),
		Operation(Type::Minus),
		Operation(Type::Times, 3),
		Operation(Type::Plus, 8)
	},
	{
		Operation(Type::Times, 2),
		Operation(Type::Plus, 10),
		Operation(Type::Minus, 4),
		Operation(Type::Divide, 2),
		Operation(Type::Minus),
		Operation(Type::Times, 3),
		Operation(Type::Plus, 6)
	},
	{
		Operation(Type::Times, 3),
		Operation(Type::Plus, 4),
		Operation(Type::Minus, 2),
		Operation(Type::Plus),
		Operation(Type::Minus, 2),
		Operation(Type::Plus),
		Operation(Type::Times, 2),
		Operation(Type::Plus, 10),
		Operation(Type::Divide, 10),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 3),
		Operation(Type::Times, 2),
		Operation(Type::Plus, 3),
		Operation(Type::Divide, 2),
		Operation(Type::Minus),
		Operation(Type::Minus, 1.5),
		Operation(Type::Plus, 3.9)
	},
	{
		Operation(Type::Times, 4),
		Operation(Type::Plus, 2),
		Operation(Type::Divide, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 6),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Plus, 4),
		Operation(Type::Divide, 2),
		Operation(Type::Plus, 3),
		Operation(Type::Times, 2),
		Operation(Type::Minus)
	},
	{
		Operation(Type::Divide, 2),
		Operation(Type::Plus, 3),
		Operation(Type::Times, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 3)
	},
	{
		Operation(Type::Times, 2),
		Operation(Type::Plus, 4),
		Operation(Type::Divide, 4),
		Operation(Type::Times, 2),
		Operation(Type::Minus),
		Operation(Type::Plus, 1)
	},
	{
		Operation(Type::Plus, 4),
		Operation(Type::Divide, 3),
		Operation(Type::Times, 6),
		Operation(Type::Minus),
		Operation(Type::Plus, 2),
		Operation(Type::Minus),
		Operation(Type::Minus, 5)
	},
	{
		Operation(Type::Divide, 2),
		Operation(Type::Plus, 3),
		Operation(Type::Times, 4),
		Operation(Type::Minus),
		Operation(Type::Minus, 5),
		Operation(Type::Minus)
	}
};



const char* type_to_str(Type t) {
	switch (t) {
	case Type::Plus: return "Add";
	case Type::Minus: return "Subtract";
	case Type::Times: return "Multiply";
	case Type::Divide: return "Divide";
	}
}


Operation::Operation(Type type, double amt)  {
	this->type = type;
	this->amt = amt;
}

Operation::Operation(Type type)  {
	this->type = type;
	this->amt = 0;
	is_num = true;
}

std::string Operation::to_string() {
	std::stringstream out;
	std::string fmt;

	switch (type) {
	case Type::Plus: fmt = "to"; break;
	case Type::Minus: fmt = "from"; break;
	case Type::Times: fmt = "and"; break;
	case Type::Divide: fmt = "from"; break;
	}

	out << "\x1b[92m\x1b[3m" << type_to_str(type) << "\x1b[0m \x1b[4m\x1b[1m\x1b[33m";
	if (!is_num) out << amt;
	else out << "your original number";
	out << "\x1b[0m \x1b[32m" << fmt << " ""\x1b[93mthe current number\x1b[0m.";

	return out.str();
}

void clear() {
	std::cout << "\x1b[1;1H\x1b[2J";
}
