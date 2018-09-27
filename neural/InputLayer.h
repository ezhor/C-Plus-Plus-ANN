/*
 * InputLayer.h
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#ifndef INPUTLAYER_H_
#define INPUTLAYER_H_

#include "Layer.h"

namespace neural {

class InputLayer: public Layer {
public:
	InputLayer();
	virtual ~InputLayer();
};

} /* namespace neural */

#endif /* INPUTLAYER_H_ */
