#include <Windows.h>
#include <iostream>
#include "Neural_Network.h"

int main(int argc, char* argv[]) {

	std::vector<int> input;
	input.push_back(2);
	input.push_back(4);
	input.push_back(4);
	input.push_back(3);
	//{ 2, 4, 4, 3 };
	Neural_Network* network = new Neural_Network(input);
	std::cout << network;
	delete network;

	system("pause");
	return 0;
}