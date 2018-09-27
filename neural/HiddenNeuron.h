/*
 * HiddenNeuron.h
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#ifndef HIDDENNEURON_H_
#define HIDDENNEURON_H_

#include <vector>
#include "AbstractNeuron.h"
#include "Synapse.h"
#include "Layer.h"

using namespace std;

namespace neural {

class HiddenNeuron: public AbstractNeuron {
private:
	vector<Synapse*> synapses;
	double bias;
public:
	HiddenNeuron(Layer layer, double bias);
	virtual ~HiddenNeuron();
};

} /* namespace neural */

#endif /* HIDDENNEURON_H_ */
