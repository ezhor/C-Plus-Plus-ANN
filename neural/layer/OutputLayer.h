/*
 * OutputLayer.h
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#ifndef LAYER_OUTPUTLAYER_H_
#define LAYER_OUTPUTLAYER_H_

#include "AbstractLayer.h"
#include "../interface/ActivationFunctionInterface.h"
#include "../neuron/BiasNeuron.h"

namespace neural {

class OutputLayer: public AbstractLayer {
private:
	void createNeurons(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, BiasNeuron* biasNeuron);
public:
	OutputLayer(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, BiasNeuron* biasNeuron);
	virtual ~OutputLayer();
};

} /* namespace neural */

#endif /* LAYER_HIDDENLAYER_H_ */
