#ifndef INTERPRET_H_

#define INTERPRET_H_

#include <fstream>
#include <iostream>
#include <array>
#include <stack>
#include <map>
#include <string>


static const int MAX_CODE_SIZE = 65536;

class Interpreter{

	private:
		std::string code;
		int codeLength;
		std::array<uint8_t,30000> memoryBuffer{};
		unsigned int memoryPointer;

		std::map<int,int> bracketPairs;
		std::stack<int> bracketStack;

		void checkBrackets();

	public:
		Interpreter(std::string fileName);

		void run();
};

#endif