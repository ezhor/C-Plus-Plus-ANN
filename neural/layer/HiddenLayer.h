/*
 * HiddenLayer.h
 *
 *  Created on: 12 oct. 2018
 *      Author: ezhor
 */

#ifndef LAYER_HIDDENLAYER_H_
#define LAYER_HIDDENLAYER_H_

#include "AbstractLayer.h"
#include "../interface/ActivationFunctionInterface.h"

namespace neural {

class HiddenLayer: public AbstractLayer {
private:
	void createNeurons(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, double* bias);
public:
	HiddenLayer(unsigned int numberOfNeurons, AbstractLayer* previousLayer, ActivationFunctionInterface* activationFunction, double* bias);
	virtual ~HiddenLayer();
};

} /* namespace neural */

#endif /* LAYER_HIDDENLAYER_H_ */
