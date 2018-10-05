/*
 * InputLayer.cpp
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#include "InputLayer.h"
#include "../neuron/InputNeuron.h"

namespace neural {

InputLayer::InputLayer(int numberOfNeurons) {
	this->createNeurons(numberOfNeurons);
}

InputLayer::~InputLayer() {
	for (unsigned int i = 0; i < this->getSize(); ++i) {
		delete this->getNeuron(i);
	}
}

void InputLayer::createNeurons(unsigned int numberOfNeurons){
	vector<AbstractNeuron*> neurons = vector<AbstractNeuron*>(numberOfNeurons);
	for (unsigned int i = 0; i < numberOfNeurons; ++i) {
		neurons.at(i) = new InputNeuron();
	}
	this->setNeurons(neurons);
}

void InputLayer::setInputValue(unsigned int neuronIndex, double value){
	((InputNeuron*)this->getNeuron(neuronIndex))->setInput(value);
}

} /* namespace neural */
