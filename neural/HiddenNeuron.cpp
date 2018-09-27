/*
 * HiddenNeuron.cpp
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#include "HiddenNeuron.h"
#include "InputNeuron.h"
#include "Layer.h"

namespace neural {

HiddenNeuron::HiddenNeuron(Layer layer, double bias) {
	this->bias = bias;
}

HiddenNeuron::~HiddenNeuron() {
}

} /* namespace neural */
