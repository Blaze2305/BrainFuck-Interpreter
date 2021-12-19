#include "interpret.hpp"


Interpreter::Interpreter(std::string fileName){
	std::ifstream inFile(fileName);
	this->code.assign((std::istreambuf_iterator<char>(inFile) ),
                		(std::istreambuf_iterator<char>()) );
	this->codeLength = this->code.length();
	this->memoryPointer = 0;
	this->checkBrackets();
}


void Interpreter::checkBrackets(){
	for(int codePointer=0; codePointer<codeLength; codePointer++){
		if (code[codePointer]=='['){
			this->bracketStack.push(codePointer);
		}
		if (code[codePointer]==']'){ 
			if(this->bracketStack.empty()){ 
				std::cerr<<"Unmatched ']' at byte "<<codePointer<<std::endl;
				exit(1);
			} else {
				int lBracketPos = this->bracketStack.top();
				this->bracketPairs[codePointer] = lBracketPos ;
				this->bracketPairs[lBracketPos] = codePointer;
				this->bracketStack.pop();
			}
		}
	}

	if(!this->bracketStack.empty()){
		std::cerr<<"Extra [ present in source"<<std::endl;
		exit(1);
	}
}

void Interpreter::run(){
	uint8_t currentChar;
	for(int codePointer=0; codePointer<codeLength; codePointer++){
		currentChar = code[codePointer];
		switch(currentChar){
			case '>':{
				this->memoryPointer += 1;
				break;
			}
			case '<':{
				this->memoryPointer -= 1;
				break;
			}
			case '+':{
				this->memoryBuffer[this->memoryPointer]+=1;
				break;
			}
			case '-':{
				this->memoryBuffer[this->memoryPointer]-=1;
				break;
			}
			case '.':{
				std::cout<<this->memoryBuffer[this->memoryPointer];
				break;
			}
			case ',':{
				std::cin>>this->memoryBuffer[this->memoryPointer];
				break;
			}
			case '[':{
				if(!this->memoryBuffer[this->memoryPointer]){
					codePointer = this->bracketPairs[codePointer];
				}
				break;
			}
			case ']':{
				if(this->memoryBuffer[this->memoryPointer]){
					codePointer = this->bracketPairs[codePointer];
				}
				break;
			}
		}
	}
}