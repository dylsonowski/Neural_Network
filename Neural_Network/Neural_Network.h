#pragma once
#include "Layer.h"

class Neural_Network {

public:
	Neural_Network(std::vector<int> topology);
	Neural_Network(std::vector<int> topology, std::vector<double> input);

	void SetInputData(std::vector<double> input);
	std::string ToString() const {

		std::stringstream stream;
		int count = 1;

		for (auto it : _network) {

			stream << "Layer " << count << ": " << it->ToString();
			count++;
		}
		
		return stream.str();
	}

private:
	int _networkSize;
	std::vector<int> _topology;
	std::vector<Layer*> _network;
};

inline std::ostream& operator<<(std::ostream& stream, const Neural_Network* net) {

	return stream << net->ToString();
}