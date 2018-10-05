/*
 * SigmoidActivationFunction.h
 *
 *  Created on: 5 oct. 2018
 *      Author: ezhor
 */

#ifndef ACTIVATIONFUNCTION_TANHACTIVATIONFUNCTION_H_
#define ACTIVATIONFUNCTION_TANHACTIVATIONFUNCTION_H_

#include "../interface/ActivationFunctionInterface.h"

namespace neural {

class TanhActivationFunction: public ActivationFunctionInterface {
public:
	virtual ~TanhActivationFunction();
	double calculate(double value);
};

} /* namespace neural */

#endif /* ACTIVATIONFUNCTION_TANHACTIVATIONFUNCTION_H_ */
