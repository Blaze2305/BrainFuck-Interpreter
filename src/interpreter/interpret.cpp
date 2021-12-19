#include "interpret.hpp"


Interpreter::Interpreter(std::string fileName){
	this->inFile = std::fstream(fileName);
	this->memoryPointer = 0;
}


Interpreter::~Interpreter(){
	this->inFile.close();
}