/*
 * DummyActivationFunction.h
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#ifndef ACTIVATIONFUNCTION_DUMMYACTIVATIONFUNCTION_H_
#define ACTIVATIONFUNCTION_DUMMYACTIVATIONFUNCTION_H_

#include "../interface/ActivationFunctionInterface.h"

namespace neural {

class DummyActivationFunction: public ActivationFunctionInterface {
public:
	virtual ~DummyActivationFunction();
	double calculate(double value);
};

} /* namespace neural */

#endif /* ACTIVATIONFUNCTION_DUMMYACTIVATIONFUNCTION_H_ */
