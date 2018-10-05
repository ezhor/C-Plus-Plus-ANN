/*
 * ActivationFunctionInterface.h
 *
 *  Created on: 5 oct. 2018
 *      Author: ezhor
 */

#ifndef INTERFACE_ACTIVATIONFUNCTIONINTERFACE_H_
#define INTERFACE_ACTIVATIONFUNCTIONINTERFACE_H_

namespace neural {

class ActivationFunctionInterface {
public:
	virtual ~ActivationFunctionInterface(){}
	virtual double calculate(double value) = 0;
};

} /* namespace neural */

#endif /* INTERFACE_ACTIVATIONFUNCTIONINTERFACE_H_ */
