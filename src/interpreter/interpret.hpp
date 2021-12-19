#ifndef INTERPRET_H_

#define INTERPRET_H_

#include <fstream>
#include <iostream>
#include <array>

class Interpreter{

	private:
		std::fstream inFile;
		char currentChar;
		std::array<uint8_t,30000> memoryBuffer{};
		unsigned int memoryPointer;

	public:
		Interpreter(std::string fileName);
		~Interpreter();

};

#endif