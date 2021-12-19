#include<iostream>

#include "src/interpreter/interpret.hpp"


int main(int argc, char *argv[]){
	// Check if the file is passed as an argument or not
	// if not then error out
 	if(argc != 2){
		std::cout<<"\nFile Missing , Invalid number of arguments\n";
		return 1;
	}
	std::cout<<"----------------------------------------------------------------------------\n";
	std::cout<<argv[1]<<std::endl;
	std::cout<<"----------------------------------------------------------------------------\n";
	
	Interpreter interpreter(argv[1]);

	return 0;
}