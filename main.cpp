#include <ctime>
#include <chrono>
#include <thread>
#include <cstdlib>
#include <iostream>

#include "maths.h"


int main() {
	std::srand(std::time(nullptr));

	while (true) {
		std::vector<Operation> choice = types[std::rand() % types.size()];
		double output = 0;

		std::cout << "\x1b[94mThink of a number\x1b[0m."" \x1b[92mAny number\x1b[0m!" << std::endl;

		for (Operation op : choice) {
			double amt = op.is_num ? 0 : op.amt;
			switch (op.type) {
			case Type::Plus: output += amt; break;
			case Type::Minus: output -= amt; break;
			case Type::Times: output *= amt; break;
			case Type::Divide: output /= amt; break;
			}

			std::cout << op.to_string() << std::endl;
			std::cout << "\x1b[94mContinue\x1b[0m ""(\x1b[32menter\x1b[0m) ";

			{
				std::string o;
				std::getline(std::cin, o);
				clear();
			}
		}

		std::cout << "\x1b[32mThink of the number you got\x1b[0m!" << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
		std::cout << "\x1b[33mOk, I'm reading your mind now\x1b[0m..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "\x1b[93mHmm\x1b[0m..." << std::endl;
		std::this_thread::sleep_for(std::chrono::milliseconds(500));
		std::cout << "\x1b[36mOk, your number is\x1b[0m: \x1b[1m\x1b[4m\x1b[96m" << output << "\x1b[0m!" << std::endl;

		std::cout << "\x1b[94mTry Again?\x1b[0m ""(\x1b[32my\x1b[0m/\x1b[32mn\x1b[0m) \x1b[32m";

		{
			std::string o;
			std::getline(std::cin, o);
			if (o == "n") {
				std::cout << "\x1b[91mGoodbye\x1b[0m!" << std::endl;
				break;
			}
			std::cout << "\x1b[0m";
			clear();
		}
	}
}
