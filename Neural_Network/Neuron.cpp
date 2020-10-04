#include <math.h>
#include "Neuron.h"

Neuron::Neuron(int val) {

	SetValue(val);
}

void Neuron::Activate() {

	_activationValue = 1 / (1 - exp(-_value));
}

void Neuron::Derivate() {

	_derivationValue = _activationValue * (1 - _activationValue);
}

void Neuron::SetValue(int val) {

	_value = val;
	Activate();
	Derivate();
}
