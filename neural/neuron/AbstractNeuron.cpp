/*
 * AbstractNeuron.cpp
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#include "AbstractNeuron.h"

#include <random>

namespace neural {

AbstractNeuron::AbstractNeuron() {
}

AbstractNeuron::~AbstractNeuron() {
}

double AbstractNeuron::randomWeight(){
	return (double)rand()/RAND_MAX;
}

} /* namespace neural */
