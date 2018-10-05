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
#include <math.h>

#include "../neural/activationFunction/TanhActivationFunction.h"
#include "../neural/synapse/Synapse.h"
#include "../neural/layer/AbstractLayer.h"
#include "../neural/layer/InputLayer.h"
#include "../neural/neuron/InputNeuron.h"
#include "../neural/neuron/HiddenNeuron.h"

using namespace std;
using namespace neural;

void setupRandomness();
void checkSingleSynapse();
void checkMultipleSynapseFromInputLayerToHiddenNeuron();

int main() {
	string separator = "----------------------------------------------------------";
	cout << "Test started" << endl << separator << endl;
	checkSingleSynapse();
	checkMultipleSynapseFromInputLayerToHiddenNeuron();
	cout  << separator << endl << "Test finished" << endl;

	return 0;
}

void checkSingleSynapse(){
	InputNeuron *inputNeuron = new InputNeuron();
	Synapse *synapse = new Synapse(inputNeuron, 2);
	inputNeuron->setInput(10);
	if(synapse->propagate() == 20){
		cout << "Single synapse OK" << endl;
	}else{
		cout << "-Single synapse ERROR" << endl;
		cout << "-Expected: " << 20 << endl;
		cout << "-Actual: " << synapse->propagate() << endl;
	}
	delete synapse;
}

void checkMultipleSynapseFromInputLayerToHiddenNeuron(){
	InputLayer* inputLayer = new InputLayer(2);
	HiddenNeuron* hiddenNeuron;
	TanhActivationFunction* activationFunction = new TanhActivationFunction();
	double epsilon = 0.001;

	inputLayer->setInputValue(0, 2);
	inputLayer->setInputValue(1, 3);
	hiddenNeuron = new HiddenNeuron(inputLayer, activationFunction, 1);
	hiddenNeuron->getSynapses().at(0)->setWeight(-1);
	hiddenNeuron->getSynapses().at(1)->setWeight(0.5);
	if((hiddenNeuron->propagate() - tanh(0.5)) < epsilon){
		cout << "Multiple synapse from input layer to single hidden neuron OK" << endl;
	}else{
		cout << "-Multiple synapse from input layer to single hidden neuron ERROR" << endl;
		cout << "-Expected: " << tanh(0.5) << endl;
		cout << "-Actual: " << hiddenNeuron->propagate() << endl;
	}
	delete inputLayer;
	delete hiddenNeuron;
	delete activationFunction;
}

void setupRandomness(){
	srand(clock());
	rand();
}
