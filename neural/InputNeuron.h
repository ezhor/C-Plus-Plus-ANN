/*
 * InputNeuron.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef INPUTNEURON_H_
#define INPUTNEURON_H_

#include "AbstractNeuron.h"

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

#endif /* INPUTNEURON_H_ */
