/*
 * AbstractNeuron.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef NEURON_ABSTRACTNEURON_H_
#define NEURON_ABSTRACTNEURON_H_

#include "../interface/PropagationInterface.h"

namespace neural {

class AbstractNeuron: public PropagationInterface {
public:
	AbstractNeuron();
	virtual ~AbstractNeuron();
	double randomWeight();
	virtual double propagate() = 0;
};

} /* namespace neural */

#endif /* NEURON_ABSTRACTNEURON_H_ */
