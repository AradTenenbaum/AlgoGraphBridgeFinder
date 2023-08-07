#pragma once
#include <vector>
#include "Vertex.h"
#include "Utils.h"

class Graph {
	GRAPH_TYPE type;
	std::vector<Vertex*> vertexArr;

public:
	Graph(GRAPH_TYPE _type, int size) : type(_type) {
		vertexArr.resize(size);
		for (int i = 0; i < vertexArr.size(); i++) {
			vertexArr[i] = new Vertex();
		}
	};

	void addArc(int fromValue, int toValue) {
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

	int getSize() { return vertexArr.size(); };

	Vertex* getVertex(int u) { return vertexArr[u - 1]; };
};