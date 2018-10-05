/*
 * HiddenNeuron.h
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#ifndef NEURON_HIDDENNEURON_H_
#define NEURON_HIDDENNEURON_H_

#include <vector>

#include "../layer/AbstractLayer.h"
#include "AbstractNeuron.h"
#include "../synapse/Synapse.h"
#include "../interface/ActivationFunctionInterface.h"

using namespace std;

namespace neural {

class HiddenNeuron: public AbstractNeuron {
private:
	vector<Synapse*> synapses;
	ActivationFunctionInterface* activationFunction;
	double bias;
	void createSynapses(AbstractLayer* layer);
public:
	HiddenNeuron(AbstractLayer* layer, ActivationFunctionInterface* activationFunction, double bias);
	virtual ~HiddenNeuron();
	virtual double propagate();

	vector<Synapse*>& getSynapses(){
		return synapses;
	}
};

} /* namespace neural */

#endif /* NEURON_HIDDENNEURON_H_ */
