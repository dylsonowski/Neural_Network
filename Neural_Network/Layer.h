#pragma once
#include <vector>
#include <string>
#include <sstream>
#include "Neuron.h"
#include "Matrix.h"

namespace neural {
	class Layer {

	public:
		Layer() = delete;
		Layer(int size);
		Layer(int size, double biosValue);
		~Layer() = default;

		void SetValue(int iterator, double val);
		std::vector<double> GetActivationLayer() const;
		std::vector<double> GetDerivationLayer() const;
		inline int GetBiosValue() const { return _bios; }
		utilities::math::Matrix GetValueMatrix() const;
		utilities::math::Matrix GetActivationMatrix() const;
		utilities::math::Matrix GetDerivationMatrix() const;
		std::string ToString(bool inputLayer) const {

			std::stringstream stream;

			for (int it = 0; it < _size; it++) {

				if(inputLayer) {
					if (it == _size - 1)
						stream << _layer.at(it)->GetValue() << "\n";
					else
						stream << _layer.at(it)->GetValue() << " | ";
				}
				else {
					if (it == _size - 1)
						stream << _layer.at(it)->GetActivationValue() << "\n";
					else
						stream << _layer.at(it)->GetActivationValue() << " | ";
				}
			}
			return stream.str();
		}

	private:
		int _size, _bios;
		std::vector<Neuron*> _layer;
	};
}