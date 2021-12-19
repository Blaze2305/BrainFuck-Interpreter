#include "interpret.hpp"


Interpreter::Interpreter(std::string fileName){
	this->inFile = std::fstream(fileName);
	uint8_t temp = 0;
	for(auto item:this->memoryBuffer){
		std::cout<<(int)item<<"--";
	}
}


Interpreter::~Interpreter(){
	this->inFile.close();
}