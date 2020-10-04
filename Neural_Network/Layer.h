#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Neuron.h"

class Layer {

public:
	Layer(int size);
	void SetValue(int iterator, double val);
	std::vector<double> GetActivationLayer() const;
	std::vector<double> GetDerivationLayer() const;
	std::string ToString() const {

		std::stringstream stream;

		for (int it = 0; it < _size; it++) {

			if (it == _size - 1)
				stream << _layer.at(it)->GetActivationValue() << "\n";
			else
				stream << _layer.at(it)->GetActivationValue() << " | ";
		}

		return stream.str();
	}

private:
	int _size;
	std::vector<Neuron*> _layer;
};

