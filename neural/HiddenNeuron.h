/*
 * HiddenNeuron.h
 *
 *  Created on: 5 sept. 2018
 *      Author: ezhor
 */

#ifndef HIDDENNEURON_H_
#define HIDDENNEURON_H_

#include "AbstractNeuron.h"

namespace neural {

class HiddenNeuron: public AbstractNeuron {
public:
	HiddenNeuron();
	virtual ~HiddenNeuron();
};

} /* namespace neural */

#endif /* HIDDENNEURON_H_ */
