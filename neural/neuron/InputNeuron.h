/*
 * InputNeuron.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef NEURON_INPUTNEURON_H_
#define NEURON_INPUTNEURON_H_

#include "../neuron/AbstractNeuron.h"

namespace neural {

class InputNeuron: public AbstractNeuron {
private:
	double input;
public:
	InputNeuron();
	virtual ~InputNeuron();
	virtual double propagate();

	double getInput() const {
		return input;
	}

	void setInput(double input) {
		this->input = input;
	}
};

} /* namespace neural */

#endif /* NEURON_INPUTNEURON_H_ */
