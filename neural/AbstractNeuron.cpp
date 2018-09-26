/*
 * AbstractNeuron.cpp
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#include <random>
#include "AbstractNeuron.h"

namespace neural {

AbstractNeuron::AbstractNeuron() {
	// TODO Auto-generated constructor stub

}

AbstractNeuron::~AbstractNeuron() {
}

double AbstractNeuron::randomWeight(){
	return (double)rand()/RAND_MAX;
}

} /* namespace neural */
