/*
 * BiasNeuron.cpp
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#include "../neuron/BiasNeuron.h"

namespace neural {

BiasNeuron::BiasNeuron() {
	this->biasValue = this->DEFAULT_BIAS_VALUE;
}

BiasNeuron::BiasNeuron(double biasValue) {
	this->biasValue = biasValue;
}

BiasNeuron::~BiasNeuron() {
}

double BiasNeuron::propagate(){
	return biasValue;
}

} /* namespace neural */
