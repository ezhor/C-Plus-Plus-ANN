/*
 * InputNeuron.cpp
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#include "../neuron/InputNeuron.h"

#include <iostream>
using namespace std;

namespace neural {

InputNeuron::InputNeuron() {
	input = 0;
}

InputNeuron::~InputNeuron() {
}

double InputNeuron::propagate(){
	return input;
}

} /* namespace neural */
