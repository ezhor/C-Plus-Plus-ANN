/*
 * Layer.cpp
 *
 *  Created on: 27 sept. 2018
 *      Author: ezhor
 */

#include "AbstractLayer.h"

namespace neural {

AbstractLayer::AbstractLayer() {
}

AbstractLayer::~AbstractLayer() {
}

AbstractNeuron* AbstractLayer::getNeuron(int i){
	return this->neurons.at(i);
}

unsigned int AbstractLayer::getSize(){
	return neurons.size();
}

void AbstractLayer::deleteNeurons(){
	for (unsigned int i = 0; i < this->getSize(); ++i) {
		delete this->getNeuron(i);
	}
}

void AbstractLayer::setNeurons(vector<AbstractNeuron*> neurons){
	deleteNeurons();
	this->neurons = neurons;
}

} /* namespace neural */
