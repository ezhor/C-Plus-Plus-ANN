//============================================================================
// Name        : ANN.cpp
// Author      : ezhor
// Version     :
// Copyright   :
// Description : A neural network experiment
//============================================================================

#include <iostream>
#include <time.h>
#include <memory>
#include "../neural/Synapse.h"
#include "../neural/InputNeuron.h"

using namespace std;
using namespace neural;

void setupRandomness();

int main() {
	InputNeuron *inputNeuron = new InputNeuron();
	Synapse *synapse = new Synapse(inputNeuron, 2);
	inputNeuron->setInput(10);
	cout <<"Si la sinapsis es correcta esto debería ser 20: " << synapse->propagate() << endl;
	delete synapse;

	return 0;
}

void setupRandomness(){
	srand(clock());
	rand();
}
