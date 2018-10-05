/*
 * SigmoidActivationFunction.cpp
 *
 *  Created on: 5 oct. 2018
 *      Author: ezhor
 */

#include "TanhActivationFunction.h"
#include "math.h"

namespace neural {

TanhActivationFunction::~TanhActivationFunction() {
}

double TanhActivationFunction::calculate(double value){
	return tanh(value);
}

} /* namespace neural */
