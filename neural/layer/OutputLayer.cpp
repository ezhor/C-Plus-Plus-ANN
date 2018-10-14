/*
 * OutputLayer.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#include "OutputLayer.h"
#include "../neuron/OutputNeuron.h"

namespace neural {

OutputLayer::OutputLayer(unsigned int numberOfNeurons,
		AbstractLayer* previousLayer,
		ActivationFunctionInterface* activationFunction,
		BiasNeuron* biasNeuron) {
	this->createNeurons(numberOfNeurons, previousLayer, activationFunction,
			biasNeuron);
}

OutputLayer::~OutputLayer() {
	for (unsigned int i = 0; i < this->getSize(); ++i) {
		delete this->getNeuron(i);
	}
}

void OutputLayer::createNeurons(unsigned int numberOfNeurons,
		AbstractLayer* previousLayer,
		ActivationFunctionInterface* activationFunction,
		BiasNeuron* biasNeuron) {
	vector<AbstractNeuron*> neurons = vector<AbstractNeuron*>(numberOfNeurons);
	for (unsigned int i = 0; i < numberOfNeurons; ++i) {
		neurons.at(i) = new OutputNeuron(previousLayer, activationFunction,
				biasNeuron);
	}
	this->setNeurons(neurons);
}

} /* namespace neural */
