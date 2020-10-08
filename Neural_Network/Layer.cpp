#include <iostream>
#include "Layer.h"

namespace neural {
	Layer::Layer(int size) : _size(size) {

		for (int it = 0; it < size; it++) {

			Neuron* neuron = new Neuron(0.000000000);
			_layer.push_back(neuron);
		}

		_bios = 1;
	}

	Layer::Layer(int size, double biosValue) {

		for (int it = 0; it < size; it++) {

			Neuron* neuron = new Neuron(0.000000000);
			_layer.push_back(neuron);
		}

		_bios = biosValue;
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

	utilities::math::Matrix Layer::GetValueMatrix() const {

		utilities::math::Matrix temp(_size, 1, false);

		for (int x = 0; x < _size; x++) {
			temp.SetValue(x, 0, _layer.at(x)->GetValue());
		}
		return temp;
	}

	utilities::math::Matrix Layer::GetActivationMatrix() const {

		utilities::math::Matrix temp(_size, 1, false);

		for (int x = 0; x < _size; x++) {
			temp.SetValue(x, 0, _layer.at(x)->GetActivationValue());
		}
		return temp;
	}

	utilities::math::Matrix Layer::GetDerivationMatrix() const {

		utilities::math::Matrix temp(_size, 1, false);

		for (int x = 0; x < _size; x++) {
			temp.SetValue(x, 0, _layer.at(x)->GetDerivationValue());
		}
		return temp;
	}
}