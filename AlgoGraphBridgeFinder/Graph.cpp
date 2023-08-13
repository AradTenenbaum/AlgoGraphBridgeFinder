#include "Graph.h"


void Graph::addArc(int fromValue, int toValue) {
	if (type == DIRECTIONED) {
		vertexArr[fromValue - 1]->addNeighbor(new Node(toValue));
	}
	else {
		Node* nodeFrom = new Node(toValue);
		Node* nodeTo = new Node(fromValue, nodeFrom);
		vertexArr[fromValue - 1]->addNeighbor(nodeFrom);
		vertexArr[toValue - 1]->addNeighbor(nodeTo);
		nodeFrom->setReverse(nodeTo);
	}
}

Graph* Graph::getReverseGraph() {
	if (type == DIRECTIONED) {
		Graph* reverseGraph = new Graph(DIRECTIONED, vertexArr.size());

	}
	else {
		return nullptr;
	}
}
