/*
 * HiddenLayer.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#include "HiddenLayer.h"
#include "../neuron/HiddenNeuron.h"

namespace neural {

HiddenLayer::HiddenLayer(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, BiasNeuron* biasNeuron) {
	this->createNeurons(numberOfNeurons, previousLayer, activationFunction, biasNeuron);
}

HiddenLayer::~HiddenLayer() {
	for (unsigned int i = 0; i < this->getSize(); ++i) {
			delete this->getNeuron(i);
		}
}

void HiddenLayer::createNeurons(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, BiasNeuron* biasNeuron){
	vector<AbstractNeuron*> neurons = vector<AbstractNeuron*>(numberOfNeurons);
	for (unsigned int i = 0; i < numberOfNeurons; ++i) {
		neurons.at(i) = new HiddenNeuron(previousLayer, activationFunction, biasNeuron);
	}
	this->setNeurons(neurons);
}

} /* namespace neural */
