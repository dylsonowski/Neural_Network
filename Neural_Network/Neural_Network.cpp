#include "Neural_Network.h"

namespace neural {
	Neural_Network::Neural_Network(std::vector<int> topology) : _topology(topology) {

		_networkSize = topology.size();
		for (auto it : topology) {

			Layer* layer = new Layer(it);
			_network.push_back(layer);
		}

		for (int x = 0; x < topology.size() - 1; x++) {

			utilities::math::Matrix* temp = new utilities::math::Matrix(topology.at(x + 1), topology.at(x), true);
			_weightMatrices.push_back(temp);
		}
	}

	Neural_Network::Neural_Network(std::vector<int> topology, std::vector<double> input) : _topology(topology) {

		_networkSize = topology.size();
		_networkInput = input;
		for (auto it : topology) {

			Layer* layer = new Layer(it);
			_network.push_back(layer);
		}

		for (int x = 0; x < _networkInput.size(); x++) {

			_network.at(0)->SetValue(x, input.at(x));
		}

		for (int x = 0; x < topology.size() - 1; x++) {

			utilities::math::Matrix* temp = new utilities::math::Matrix(topology.at(x + 1), topology.at(x), true);
			_weightMatrices.push_back(temp);
		}
	}

	Neural_Network::~Neural_Network() {

		for (auto it : _weightMatrices) {

			delete it;
		}
	}

	void Neural_Network::SetInputData(std::vector<double> input) {

		_networkInput = input;
		for (auto it : input) {

			_network.at(0)->SetValue(it, input.at(it));
		}
	}

	utilities::math::Matrix Neural_Network::GetNeuronMatrix(unsigned int iterator, int valueType) const {

		switch (valueType) {
		case 1:
			return _network.at(iterator)->GetValueMatrix();
			break;
		case 2:
			return _network.at(iterator)->GetActivationMatrix();
			break;
		case 3:
			return _network.at(iterator)->GetDerivationMatrix();
			break;
		default:
			printf("ERROR60: Bad value type was chosen!");
			system("pause");
			exit(1);
			break;
		}
	}

	utilities::math::Matrix Neural_Network::GetWeightMatrix(unsigned int iterator) const {

		try {

			if (iterator > _weightMatrices.size() - 1)
				throw 100;

			return *_weightMatrices.at(iterator);
		}
		catch (int error) {

			printf("ERROR%d: Weight matrix out of reach acces!\n", error);
			system("pause");
			exit(1);
		}
	}

	void Neural_Network::FeedForword() {

		for (int x = 0; x < _topology.size() - 1; x++) {

			utilities::math::Matrix a = GetNeuronMatrix(x, 1);
			utilities::math::Matrix b = GetWeightMatrix(x);
			
			if (x != 0)
				a = GetNeuronMatrix(x, 2);

			utilities::math::Matrix c = b * a;

			for (int y = 0; y < c.GetRowNumber(); y++) {

				double temp = c.GetValue(y, 0) + _network.at(x)->GetBiosValue();
				//_network.at(x + 1)->SetValue(y, temp);
				SetNeuronValue(x + 1, y, temp);
			}
		}
	}
}