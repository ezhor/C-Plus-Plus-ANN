/*
 * InputLayer.h
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#ifndef LAYER_INPUTLAYER_H_
#define LAYER_INPUTLAYER_H_

#include "AbstractLayer.h"

namespace neural {

class InputLayer: public AbstractLayer {
private:
	void createNeurons(unsigned int numberOfNeurons);
public:
	InputLayer(int numberOfNeurons);
	virtual ~InputLayer();
	void setInputValue(unsigned int neuronIndex, double value);
};

} /* namespace neural */

#endif /* LAYER_INPUTLAYER_H_ */
