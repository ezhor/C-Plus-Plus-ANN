/*
 * AbstractNeuron.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef ABSTRACTNEURON_H_
#define ABSTRACTNEURON_H_

#include "PropagationInterface.h"

namespace neural {

class AbstractNeuron: public PropagationInterface {
public:
	AbstractNeuron();
	virtual ~AbstractNeuron();
	double randomWeight();
	virtual double propagate() = 0;
};

} /* namespace neural */

#endif /* ABSTRACTNEURON_H_ */
