/*
 * PropagationInterface.h
 *
 *  Created on: 1 sept. 2018
 *      Author: ezhor
 */

#ifndef PROPAGATIONINTERFACE_H_
#define PROPAGATIONINTERFACE_H_

namespace neural {

class PropagationInterface {
public:
	virtual ~PropagationInterface(){}
	virtual double propagate() = 0;
};

} /* namespace neural */

#endif /* PROPAGATIONINTERFACE_H_ */
