#include <iostream>
#include "Layer.h"

Layer::Layer(int size) : _size(size) {

	for (int it = 0; it < size; it++) {

		Neuron* neuron = new Neuron(0.000000000);
		_layer.push_back(neuron);
	}
}

void Layer::SetValue(int iterator, double val) {

	_layer.at(iterator)->SetValue(val);
}

std::vector<double> Layer::GetActivationLayer() const {
	
	try {

		if (_layer.empty())
			throw(5);

		std::vector<double> temp;

		for (auto it : _layer) {

			temp.push_back(it->GetActivationValue());
		}
			return temp;
	}
	catch (int error) {

		std::cout << "ERROR" << error << ": layer vector is empty!\n";
	}
}

std::vector<double> Layer::GetDerivationLayer() const {

	try {

		if (_layer.empty())
			throw(5);

		std::vector<double> temp;

		for (auto it : _layer) {

			temp.push_back(it->GetDerivationValue());
		}
		return temp;
	}
	catch (int error) {

		std::cout << "ERROR" << error << ": layer vector is empty!\n";
	}
}
