/*
 * NeuralNetwork.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#include "NeuralNetwork.h"

namespace neural {

NeuralNetwork::NeuralNetwork(NeuralNetworkConfig config) {
	HiddenLayer* lastHiddenLayer;

	this->inputLayer = new InputLayer(config.getNumberOfInputNeurons());

	lastHiddenLayer = createHiddenLayers(config.getNumberOfHiddenLayers(),
			config.getNumberOfNeuronsPerHiddenLayer(), this->inputLayer,
			config.getActivationFunction(), config.getBiasNeuron());

	this->outputLayer = new OutputLayer(config.getNumberOfOutputNeurons(),
			lastHiddenLayer, config.getActivationFunction(), config.getBiasNeuron());
}

NeuralNetwork::~NeuralNetwork() {
// TODO Auto-generated destructor stub
}

HiddenLayer* NeuralNetwork::createHiddenLayers(
		unsigned int numberOfHiddenLayers, unsigned int numberOfNeuronsPerLayer,
		AbstractLayer* previousLayer,
		ActivationFunctionInterface* activationFunction,
		BiasNeuron* biasNeuron) {

	AbstractLayer* currentPreviousLayer = previousLayer;
	HiddenLayer* currentLayer;

	vector<HiddenLayer*> hiddenLayers = vector<HiddenLayer*>(
			numberOfHiddenLayers);
	for (unsigned int i = 0; i < numberOfHiddenLayers; ++i) {
		currentLayer = new HiddenLayer(numberOfNeuronsPerLayer,
				currentPreviousLayer, activationFunction, biasNeuron);
		hiddenLayers.at(i) = currentLayer;
		currentPreviousLayer = currentLayer;
	}
	this->hiddenLayers = hiddenLayers;
	return currentLayer;
}

AbstractNeuron* NeuralNetwork::getNeuron(unsigned int layer, unsigned int neuron){
	AbstractLayer* chosenLayer;
	if(layer == 0){
		chosenLayer = this->inputLayer;
	}else if(layer > this->hiddenLayers.size()){
		chosenLayer = this->outputLayer;
	}else{
		chosenLayer = this->hiddenLayers.at(layer-1);
	}
	return chosenLayer->getNeuron(neuron);
}

vector<double> NeuralNetwork::feedForward(vector<double> inputs){
	vector<double> outputs = vector<double>(this->outputLayer->getSize());

	for(unsigned int i=0; i<inputs.size(); i++){
		this->inputLayer->setInputValue(i, inputs.at(i));
	}
	for(unsigned int i=0; i<outputs.size(); i++){
		outputs.at(i) = outputLayer->getNeuron(i)->propagate();
	}

	return outputs;
}

} /* namespace neural */
