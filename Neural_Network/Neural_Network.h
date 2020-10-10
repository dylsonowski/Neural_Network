#pragma once
#include <memory>
#include "Layer.h"
#include "Matrix.h"

namespace neural {
	class Neural_Network {

	public:
		Neural_Network() = delete;
		Neural_Network(std::vector<int> topology);
		Neural_Network(std::vector<int> topology, std::vector<double> input);
		~Neural_Network();

		void SetNeuronValue(unsigned int layerIt, unsigned int neuronIt, double value) { _network.at(layerIt)->SetValue(neuronIt, value); }
		void SetInputData(std::vector<double> input);
		void SetTargetData(std::vector<double> targer) { _target = targer; }
		utilities::math::Matrix GetNeuronMatrix(unsigned int iterator, int valueType) const;
		utilities::math::Matrix GetWeightMatrix(unsigned int iterator) const;
		inline Layer* GetLayer(unsigned int iterator) const { return _network.at(iterator); }
		inline double GetError() const { return _error; }
		inline std::vector<double> GetOutputErrors() const { return _outputErrors; }
		inline std::vector<double> GetDerivedOutputErrors() const { return _derivedOutputErrors; }
		inline double GetPreviousError(unsigned int iterator) const { return _errorHistory.at(iterator); }
		void FeedForword();
		void BackPropagation();
		void SetError();
		std::string ToString() const {

			std::stringstream stream;
			int count = 1;

			for (auto it : _network) {

				if(count == 1)
					stream << "Layer " << count << ": " << it->ToString(true);
				else
					stream << "Layer " << count << ": " << it->ToString(false);
				count++;
			}

			return stream.str();
		}

	private:
		int _networkSize;
		std::vector<int> _topology;
		std::vector<double> _networkInput;
		std::vector<Layer*> _network;
		std::vector<utilities::math::Matrix*> _weightMatrices;
		std::vector<double> _target;
		double _error;
		std::vector<double> _outputErrors;
		std::vector<double> _derivedOutputErrors;
		std::vector<double> _errorHistory;
	};

	inline std::ostream& operator<<(std::ostream& stream, const Neural_Network* net) {

		return stream << net->ToString();
	}
}