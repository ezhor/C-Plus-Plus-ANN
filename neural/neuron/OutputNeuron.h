/*
 * OutputNeuron.h
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#ifndef NEURON_OUTPUTNEURON_H_
#define NEURON_OUTPUTNEURON_H_

#include <vector>

#include "../layer/AbstractLayer.h"
#include "AbstractNeuron.h"
#include "../synapse/Synapse.h"
#include "../interface/ActivationFunctionInterface.h"
#include "BiasNeuron.h"

using namespace std;

namespace neural {

class OutputNeuron: public AbstractNeuron {
private:
	vector<Synapse*> synapses;
	ActivationFunctionInterface* activationFunction;
	double* bias;
	void createSynapses(AbstractLayer* previousLayer, BiasNeuron* biasNeuron);
public:
	OutputNeuron(AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, BiasNeuron* biasNeuron);
	virtual ~OutputNeuron();
	virtual double propagate();

	vector<Synapse*>& getSynapses(){
		return synapses;
	}
};

} /* namespace neural */

#endif /* NEURON_HIDDENNEURON_H_ */
