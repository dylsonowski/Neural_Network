#pragma once

class Neuron {

public:
	Neuron(int val);
	~Neuron() = default;

	void Activate();
	void Derivate();
	void SetValue(int val);
	inline double GetValue() const { return _value; }
	inline double GetActivationValue() const { return _activationValue; }
	inline double GetDerivationValue() const { return _derivationValue; }

private:
	double _value, _activationValue, _derivationValue;
};

