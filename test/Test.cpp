//============================================================================
// Name        : ANN.cpp
// Author      : ezhor
// Version     :
// Copyright   :
// Description : A neural network experiment
//============================================================================

#include <iostream>
#include <time.h>
#include <math.h>

#include "../neural/activationFunction/TanhActivationFunction.h"
#include "../neural/synapse/Synapse.h"

#include "../neural/neuron/InputNeuron.h"
#include "../neural/neuron/HiddenNeuron.h"
#include "../neural/neuron/BiasNeuron.h"

#include "../neural/layer/AbstractLayer.h"
#include "../neural/layer/InputLayer.h"
#include "../neural/layer/HiddenLayer.h"

#include "../neural/network/NeuralNetwork.h"
#include "../neural/network/NeuralNetworkConfig.h"

using namespace std;
using namespace neural;

void setupRandomness();
void checkSingleSynapse();
void checkMultipleSynapseFromInputLayerToHiddenNeuron();
void checkMultipleSynapseFromInputLayerToHiddenLayer();
void checkDeepLearningNeuralNetworkFeedForward();
void validate(double expected, double actual, double epsilon, string testName);

int main() {
	string separator = "-------------------------------------";

	cout << "Test started" << endl << separator << endl;
	checkSingleSynapse();
	checkMultipleSynapseFromInputLayerToHiddenNeuron();
	checkMultipleSynapseFromInputLayerToHiddenLayer();
	checkDeepLearningNeuralNetworkFeedForward();
	cout  << separator << endl << "Test finished" << endl;

	return 0;
}

void checkSingleSynapse(){
	InputNeuron* inputNeuron = new InputNeuron();
	Synapse* synapse = new Synapse(inputNeuron, 2);
	inputNeuron->setInput(10);
	validate(20, synapse->propagate(), 0, "Single synapse");
	delete synapse;
}

void checkMultipleSynapseFromInputLayerToHiddenNeuron(){
	InputLayer* inputLayer = new InputLayer(2);
	HiddenNeuron* hiddenNeuron;
	TanhActivationFunction* activationFunction = new TanhActivationFunction();
	double epsilon = 0.001;
	BiasNeuron* biasNeuron = new BiasNeuron();

	inputLayer->setInputValue(0, 2);
	inputLayer->setInputValue(1, 3);
	hiddenNeuron = new HiddenNeuron(inputLayer, activationFunction, biasNeuron);
	hiddenNeuron->getSynapses().at(0)->setWeight(-1);
	hiddenNeuron->getSynapses().at(1)->setWeight(0.5);
	hiddenNeuron->getSynapses().at(2)->setWeight(2);
	validate(tanh(1.5), hiddenNeuron->propagate(), epsilon, "Multiple synapse from input layer to single hidden neuron");
	delete inputLayer;
	delete hiddenNeuron;
	delete activationFunction;
	delete biasNeuron;
}

void checkMultipleSynapseFromInputLayerToHiddenLayer(){
	InputLayer* inputLayer = new InputLayer(2);
	HiddenLayer* hiddenLayer;
	TanhActivationFunction* activationFunction = new TanhActivationFunction();
	double epsilon = 0.001;
	BiasNeuron* biasNeuron = new BiasNeuron();

	inputLayer->setInputValue(0, 2);
	inputLayer->setInputValue(1, 3);

	hiddenLayer = new HiddenLayer(2, inputLayer, activationFunction, biasNeuron);
	((HiddenNeuron*)hiddenLayer->getNeuron(0))->getSynapses().at(0)->setWeight(-1);
	((HiddenNeuron*)hiddenLayer->getNeuron(0))->getSynapses().at(1)->setWeight(0.5);
	((HiddenNeuron*)hiddenLayer->getNeuron(0))->getSynapses().at(2)->setWeight(2);

	((HiddenNeuron*)hiddenLayer->getNeuron(1))->getSynapses().at(0)->setWeight(2);
	((HiddenNeuron*)hiddenLayer->getNeuron(1))->getSynapses().at(1)->setWeight(4);
	((HiddenNeuron*)hiddenLayer->getNeuron(1))->getSynapses().at(2)->setWeight(-3);

	validate(tanh(1.5), ((HiddenNeuron*)hiddenLayer->getNeuron(0))->propagate(), epsilon, "Multiple synapse from input layer to hidden layer using bias neuron (Test 1)");
	validate(tanh(13), ((HiddenNeuron*)hiddenLayer->getNeuron(1))->propagate(), epsilon, "Multiple synapse from input layer to hidden layer using bias neuron (Test 2)");
	delete inputLayer;
	delete hiddenLayer;
	delete activationFunction;
	delete biasNeuron;
}

void checkDeepLearningNeuralNetworkFeedForward(){
	NeuralNetworkConfig config = NeuralNetworkConfig();
	NeuralNetwork* neuralNetwork;
	AbstractNeuron* currentNeuron;
	vector<double> inputs = vector<double>(1);
	double epsilon = 0.001;

	config.setNumberOfHiddenLayers(2);
	neuralNetwork  = new NeuralNetwork(config);
	inputs.at(0) = 1;

	currentNeuron = neuralNetwork->getNeuron(1, 0);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(0)->setWeight(0.5);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(1)->setWeight(-3);

	currentNeuron = neuralNetwork->getNeuron(2, 0);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(0)->setWeight(1.5);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(1)->setWeight(2.5);

	currentNeuron = neuralNetwork->getNeuron(3, 0);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(0)->setWeight(1);
	((HiddenNeuron*)currentNeuron)->getSynapses().at(1)->setWeight(2);

	validate(0.75, neuralNetwork->feedForward(inputs).at(0), epsilon, "Deep learning neural network feed-forward with single synapse and bias");

	delete neuralNetwork;
}

void validate(double expected, double actual, double epsilon, string testName){
	double difference = expected - actual;
	if(difference < 0){
		difference = difference*(-1);
	}
	if(difference <= epsilon){
			cout << testName << " OK" << endl;
		}else{
			cout << "- "<< testName << " ERROR" << endl;
			cout << "-Expected: " << expected << endl;
			cout << "-Actual: " << actual << endl;
		}
}

void setupRandomness(){
	srand(clock());
	rand();
}
