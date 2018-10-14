/*
 * NeuralNetworkConfig.h
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#ifndef NETWORK_NEURALNETWORKCONFIG_H_
#define NETWORK_NEURALNETWORKCONFIG_H_

#include "../interface/ActivationFunctionInterface.h"
#include "../activationFunction/DummyActivationFunction.h"
#include "../neuron/BiasNeuron.h"

namespace neural {

class NeuralNetworkConfig {
private:
	unsigned int numberOfInputNeurons;
	unsigned int numberOfNeuronsPerHiddenLayer;
	unsigned int numberOfHiddenLayers;
	unsigned int numberOfOutputNeurons;
	BiasNeuron* biasNeuron;
	ActivationFunctionInterface* activationFunction;

public:
	const static int DEFAULT_NUMBER_OF_INPUT_NEURONS = 1;
	const static int DEFAULT_NUMBER_OF_HIDDEN_NEURONS_PER_LAYER = 1;
	const static int DEFAULT_NUMBER_OF_HIDDEN_LAYERS = 1;
	const static int DEFAULT_NUMBER_OF_OUTPUT_NEURONS = 1;
	BiasNeuron* DEFAULT_BIAS_NEURON = new BiasNeuron();
	ActivationFunctionInterface* DEFAULT_ACTIVATION_FUNCTION = new DummyActivationFunction();

	NeuralNetworkConfig();
	virtual ~NeuralNetworkConfig();

	ActivationFunctionInterface* getActivationFunction() const {
		return activationFunction;
	}

	void setActivationFunction(
			ActivationFunctionInterface* activationFunction) {
		this->activationFunction = activationFunction;
	}

	BiasNeuron* getBiasNeuron() const {
		return biasNeuron;
	}

	void setBiasNeuron(BiasNeuron* biasNeuron) {
		this->biasNeuron = biasNeuron;
	}

	unsigned int getNumberOfHiddenLayers() const {
		return numberOfHiddenLayers;
	}

	void setNumberOfHiddenLayers(unsigned int numberOfHiddenLayers) {
		this->numberOfHiddenLayers = numberOfHiddenLayers;
	}

	unsigned int getNumberOfNeuronsPerHiddenLayer() const {
		return numberOfNeuronsPerHiddenLayer;
	}

	void setNumberOfNeuronsPerHiddenLayer(
			unsigned int numberOfHiddenNeuronsPerHiddenLayer) {
		this->numberOfNeuronsPerHiddenLayer =
				numberOfHiddenNeuronsPerHiddenLayer;
	}

	unsigned int getNumberOfInputNeurons() const {
		return numberOfInputNeurons;
	}

	void setNumberOfInputNeurons(unsigned int numberOfInputNeurons) {
		this->numberOfInputNeurons = numberOfInputNeurons;
	}

	unsigned int getNumberOfOutputNeurons() const {
		return numberOfOutputNeurons;
	}

	void setNumberOfOutputNeurons(unsigned int numberOfOutputNeurons) {
		this->numberOfOutputNeurons = numberOfOutputNeurons;
	}
};

} /* namespace neural */

#endif /* NETWORK_NEURALNETWORKCONFIG_H_ */
