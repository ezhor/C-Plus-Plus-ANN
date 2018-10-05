/*
 * Layer.h
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#ifndef LAYER_ABSTRACTLAYER_H_
#define LAYER_ABSTRACTLAYER_H_

#include <vector>
#include "../neuron/AbstractNeuron.h"

using namespace std;

namespace neural {

class AbstractLayer {
private:
	vector<AbstractNeuron*> neurons;
protected:
	AbstractLayer();
public:
	virtual ~AbstractLayer();
	AbstractNeuron* getNeuron(int i);
	void deleteNeurons();
	void setNeurons(vector<AbstractNeuron*> neurons);
	unsigned int getSize();
};

} /* namespace neural */

#endif /* LAYER_ABSTRACTLAYER_H_ */
