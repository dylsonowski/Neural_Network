#include "Neural_Network.h"

Neural_Network::Neural_Network(std::vector<int> topology) {

	for (auto it : topology) {

		Layer* layer = new Layer(it);
		_network.push_back(layer);
	}
}

Neural_Network::Neural_Network(std::vector<int> topology, std::vector<double> input) {

	for (auto it : topology) {

		Layer* layer = new Layer(it);
		_network.push_back(layer);
	}

	for (auto it : input) {

		_network.at(0)->SetValue(it, input.at(it));
	}
}

void Neural_Network::SetInputData(std::vector<double> input) {

	for (auto it : input) {

		_network.at(0)->SetValue(it, input.at(it));
	}
}
