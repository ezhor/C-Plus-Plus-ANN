/*
 * Synapse.h
 *
 *  Created on: 26 sept. 2018
 *      Author: ezhor
 */

#ifndef SYNAPSE_H_
#define SYNAPSE_H_

#include "PropagationInterface.h"

namespace neural {

class Synapse :public PropagationInterface{
private:
	PropagationInterface *propagation;
	double weight;
public:
	Synapse(PropagationInterface *propagation, double weight);
	virtual ~Synapse();
	double propagate();

	double getWeight() const {
		return weight;
	}

	void setWeight(double weight) {
		this->weight = weight;
	}
};



} /* namespace neural */

#endif /* SYNAPSE_H_ */
