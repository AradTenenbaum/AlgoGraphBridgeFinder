#pragma once
#include <vector>
#include "Vertex.h"
#include "Utils.h"

class Graph {
	// Graph type can be Directed and Undirected
	GRAPH_TYPE type;
	std::vector<Vertex*> vertexArr;

public:
	Graph(GRAPH_TYPE _type, int size) : type(_type) {
		vertexArr.resize(size);
		for (int i = 0; i < vertexArr.size(); i++) {
			vertexArr[i] = new Vertex();
		}
	};

	void addArc(int fromValue, int toValue);

	int getSize() { return vertexArr.size(); };

	Vertex* getVertex(int u) { return vertexArr[u - 1]; };

	Graph* getReverseGraph();
};