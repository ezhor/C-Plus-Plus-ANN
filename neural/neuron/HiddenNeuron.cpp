/*
 * HiddenNeuron.cpp
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#include "HiddenNeuron.h"
#include "../layer/AbstractLayer.h"
#include "InputNeuron.h"

namespace neural {

HiddenNeuron::HiddenNeuron(AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, double* bias) {
	this->bias = bias;
	this->activationFunction = activationFunction;
	createSynapses(previousLayer);
}

HiddenNeuron::~HiddenNeuron() {
	for (unsigned int i = 0; i < synapses.size(); i++) {
		delete synapses.at(i);
	}
	synapses.clear();
}

double HiddenNeuron::propagate(){
	double result = 0;
	for (unsigned int i = 0; i < this->synapses.size(); ++i) {
		result += this->synapses.at(i)->propagate();
	}
	return this->activationFunction->calculate(result + *(this->bias));
}

void HiddenNeuron::createSynapses(AbstractLayer* previousLayer){
	this->synapses = vector<Synapse*>(previousLayer->getSize());
	for (unsigned int i = 0; i < previousLayer->getSize(); i++) {
		synapses.at(i) = new Synapse(previousLayer->getNeuron(i), randomWeight());
	}
}

} /* namespace neural */
