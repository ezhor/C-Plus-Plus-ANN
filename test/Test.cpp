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
#include "../neural/layer/HiddenLayer.h"

#include "../neural/neuron/InputNeuron.h"
#include "../neural/neuron/HiddenNeuron.h"

using namespace std;
using namespace neural;

void setupRandomness();
void checkSingleSynapse();
void checkMultipleSynapseFromInputLayerToHiddenNeuron();
void checkMultipleSynapseFromInputLayerToHiddenLayer();

int main() {
	string separator = "------------------------------------------------------------";
	cout << "Test started" << endl << separator << endl;
	checkSingleSynapse();
	checkMultipleSynapseFromInputLayerToHiddenNeuron();
	checkMultipleSynapseFromInputLayerToHiddenLayer();
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
	double biasValue = 1;

	inputLayer->setInputValue(0, 2);
	inputLayer->setInputValue(1, 3);
	hiddenNeuron = new HiddenNeuron(inputLayer, activationFunction, &biasValue);
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

void checkMultipleSynapseFromInputLayerToHiddenLayer(){
	InputLayer* inputLayer = new InputLayer(2);
	HiddenLayer* hiddenLayer;
	TanhActivationFunction* activationFunction = new TanhActivationFunction();
	double epsilon = 0.001;
	double biasValue = 1;

	inputLayer->setInputValue(0, 2);
	inputLayer->setInputValue(1, 3);

	hiddenLayer = new HiddenLayer(2, inputLayer, activationFunction, &biasValue);
	((HiddenNeuron*)hiddenLayer->getNeuron(0))->getSynapses().at(0)->setWeight(-1);
	((HiddenNeuron*)hiddenLayer->getNeuron(0))->getSynapses().at(1)->setWeight(0.5);
	((HiddenNeuron*)hiddenLayer->getNeuron(1))->getSynapses().at(0)->setWeight(2);
	((HiddenNeuron*)hiddenLayer->getNeuron(1))->getSynapses().at(1)->setWeight(4);

	if((((HiddenNeuron*)hiddenLayer->getNeuron(0))->propagate() - tanh(0.5)) < epsilon &&
			(((HiddenNeuron*)hiddenLayer->getNeuron(1))->propagate() - tanh(17)) < epsilon){
		cout << "Multiple synapse from input layer to hidden layer OK" << endl;
	}else{
		cout << "-Multiple synapse from input layer to hidden layer ERROR" << endl;
		cout << "-Expected: " << tanh(0.5) << "and" << tan(17) << endl;
		cout << "-Actual: " << ((HiddenNeuron*)hiddenLayer->getNeuron(0))->propagate() << "and"
				<< ((HiddenNeuron*)hiddenLayer->getNeuron(0))->propagate() << endl;
	}
	delete inputLayer;
	delete hiddenLayer;
	delete activationFunction;
}

void setupRandomness(){
	srand(clock());
	rand();
}
