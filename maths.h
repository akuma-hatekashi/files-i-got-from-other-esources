#ifndef MATHS_H
#define MATHS_H

#include <iostream>
#include <string>
#include <vector>
#include <sstream>


enum class Type { Plus, Minus, Times, Divide };
const char* type_to_str(Type);

struct Operation {
	Type type;
	double amt;
    bool is_num = false;

	Operation(Type, double);
    Operation(Type);
	std::string to_string();
};

// A list of possible things
extern std::vector<std::vector<Operation>> types;

void clear();

#endif
