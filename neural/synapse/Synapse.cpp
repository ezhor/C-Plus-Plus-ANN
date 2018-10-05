/*
 * Synapse.cpp
 *
 *  Created on: 26 sept. 2018
 *      Author: ezhor
 */

#include "Synapse.h"
#include <iostream>
using namespace std;

namespace neural {

Synapse::Synapse(PropagationInterface *propagation, double weight) {
	this->propagation = propagation;
	this->weight = weight;
}

Synapse::~Synapse() {
}

double Synapse::propagate(){
	return this->weight * this->propagation->propagate();
}

} /* namespace neural */
