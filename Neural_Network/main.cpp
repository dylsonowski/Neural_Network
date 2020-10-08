#include <Windows.h>
#include <iostream>
#include "Neural_Network.h"
#include "Matrix.h"

int main(int argc, char* argv[]) {

	std::vector<int> topology{ 2, 3, 3, 4 };
	std::vector<double> input{ 1, 0 };
	neural::Neural_Network* network = new neural::Neural_Network(topology, input);
	std::cout << network << "\n\n\n";
	network->FeedForword();
	//utilities::math::Matrix matrix1(2, 3, true);
	//utilities::math::Matrix matrix1 = network->GetWeightMatrix(0);
	//utilities::math::Matrix matrix2(1, 2, 2.0f);
	//utilities::math::Matrix matrix3 = ~matrix1;
	//utilities::math::Matrix matrix4 = matrix3[1];
	//matrix2 = matrix1;

	std::cout << network->GetWeightMatrix(0) << "\n";
	std::cout << network->GetWeightMatrix(1) << "\n";
	std::cout << network->GetWeightMatrix(2) << "\n\n\n\n";
	std::cout << network;
	//std::cout << matrix2 << "\n\n\n";
	//std::cout << matrix3 << "\n\n\n";
	//std::cout << matrix4 << "\n\n\n";
	//utilities::math::Matrix matrix3 = matrix1 * matrix2;
	//std::cout << (matrix1 * matrix2);
	delete network;
	system("pause");
	return 0;
}