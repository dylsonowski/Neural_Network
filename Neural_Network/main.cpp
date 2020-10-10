#include <Windows.h>
#include <iostream>
#include "Neural_Network.h"
#include "Matrix.h"

int main(int argc, char* argv[]) {

	std::vector<int> topology{ 2, 3, 3, 4 };
	std::vector<double> input{ 1, 1 };
	std::vector<double> target{ 0, 0, 0, 1 };
	neural::Neural_Network* network = new neural::Neural_Network(topology, input);
	network->SetTargetData(target);
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
	network->SetError();
	std::cout << network->GetError() << "\n\n";
	for (int it = 0; it < network->GetOutputErrors().size(); it++) {
		std::cout << network->GetOutputErrors().at(it) << " | ";
	}
	std::cout << "\n\n";
	for (int it = 0; it < network->GetDerivedOutputErrors().size(); it++) {
		std::cout << network->GetDerivedOutputErrors().at(it) << " | ";
	}
	std::cout << "\n\n\n\n";
	network->BackPropagation();
	//std::cout << matrix2 << "\n\n\n";
	//std::cout << matrix3 << "\n\n\n";
	//std::cout << matrix4 << "\n\n\n";
	//utilities::math::Matrix matrix3 = matrix1 * matrix2;
	//std::cout << (matrix1 * matrix2);
	delete network;
	system("pause");
	return 0;
}