/*
 * BiasNeuron.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef NEURON_BIASNEURON_H_
#define NEURON_BIASNEURON_H_

#include "../neuron/AbstractNeuron.h"

namespace neural {

class BiasNeuron: public AbstractNeuron {
private:
	double biasValue;
public:
	double DEFAULT_BIAS_VALUE = 1;
	BiasNeuron();
	BiasNeuron(double biasValue);
	virtual ~BiasNeuron();
	virtual double propagate();
};

} /* namespace neural */

#endif /* NEURON_INPUTNEURON_H_ */
