/*
 * NeuralNetwork.h
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#ifndef NETWORK_NEURALNETWORK_H_
#define NETWORK_NEURALNETWORK_H_

#include "NeuralNetworkConfig.h"

#include "../layer/InputLayer.h"
#include "../layer/HiddenLayer.h"
#include "../layer/OutputLayer.h"

#include <vector>

namespace neural {

class NeuralNetwork {
private:
	InputLayer* inputLayer;
	vector<HiddenLayer*> hiddenLayers;
	OutputLayer* outputLayer;
	double bias;

	HiddenLayer* createHiddenLayers(unsigned int numberOfHiddenLayers,
			unsigned int numberOfNeuronsPerLayer, AbstractLayer* previousLayer,
			ActivationFunctionInterface* activationFunction,
			BiasNeuron* biasNeuron);
public:
	NeuralNetwork(NeuralNetworkConfig config);
	virtual ~NeuralNetwork();

	double getBias() {
		return bias;
	}

	void setBias(double bias) {
		this->bias = bias;
	}

	AbstractNeuron* getNeuron(unsigned int layer, unsigned int neuron);
	vector<double> feedForward(vector<double> inputs);
};

} /* namespace neural */

#endif /* NETWORK_NEURALNETWORK_H_ */
