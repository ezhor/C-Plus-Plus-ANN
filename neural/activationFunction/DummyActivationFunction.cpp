/*
 * DummyActivationFunction.cpp
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#include "DummyActivationFunction.h"

namespace neural {

DummyActivationFunction::~DummyActivationFunction() {

}

double DummyActivationFunction::calculate(double value){
	return value;
}

} /* namespace neural */
