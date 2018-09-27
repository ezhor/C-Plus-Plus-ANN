/*
 * Layer.h
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#ifndef LAYER_H_
#define LAYER_H_

#include <vector>
#include "AbstractNeuron.h"

using namespace std;

namespace neural {

class Layer {
private:
	vector<AbstractNeuron*> synapses;
protected:
	Layer();
public:
	virtual ~Layer();
};

} /* namespace neural */

#endif /* LAYER_H_ */
