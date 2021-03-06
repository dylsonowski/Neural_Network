#include <math.h>
#include "Neuron.h"

namespace neural {
	Neuron::Neuron(double val) {

		SetValue(val);
	}

	void Neuron::Activate() {

		_activationValue = 1 / (1 + exp(-_value));
	}

	void Neuron::Derivate() {

		_derivationValue = _activationValue * (1 - _activationValue);
	}

	void Neuron::SetValue(double val) {

		_value = val;
		Activate();
		Derivate();
	}
}