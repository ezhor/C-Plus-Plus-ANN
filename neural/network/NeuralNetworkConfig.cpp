/*
 * NeuralNetworkConfig.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#include "NeuralNetworkConfig.h"

namespace neural {

NeuralNetworkConfig::NeuralNetworkConfig() {
	this->numberOfInputNeurons = DEFAULT_NUMBER_OF_INPUT_NEURONS;
	this->numberOfNeuronsPerHiddenLayer = DEFAULT_NUMBER_OF_HIDDEN_NEURONS_PER_LAYER;
	this->numberOfHiddenLayers = DEFAULT_NUMBER_OF_HIDDEN_LAYERS;
	this->numberOfOutputNeurons = DEFAULT_NUMBER_OF_OUTPUT_NEURONS;
	this->biasNeuron = DEFAULT_BIAS_NEURON;
	this->activationFunction = DEFAULT_ACTIVATION_FUNCTION;
}

NeuralNetworkConfig::~NeuralNetworkConfig() {
}

} /* namespace neural */
