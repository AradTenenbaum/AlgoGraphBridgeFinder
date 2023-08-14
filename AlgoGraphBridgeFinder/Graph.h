#pragma once
#include <vector>
#include "Vertex.h"
#include "Utils.h"

class Graph {
	// Graph type can be Directed and Undirected
	GRAPH_TYPE type;
	std::vector<Vertex*> vertexArr;

public:
	// Createds a graph of specific type, init the size of the vertex vector 
	Graph(GRAPH_TYPE _type, int size) : type(_type) {
		vertexArr.resize(size);
		for (int i = 0; i < vertexArr.size(); i++) {
			vertexArr[i] = new Vertex();
		}
	};
	// Dtor of graph
	~Graph() {
		for (int i = 0; i < vertexArr.size(); i++) {
			delete vertexArr[i];
		}
	}
	// Adds arc to the graph depends on the type
	void addArc(int fromValue, int toValue);
	// Returns the size of the graph
	int getSize() { return vertexArr.size(); };
	// Get a specific vertex in the graph
	Vertex* getVertex(int u) { return vertexArr[u - 1]; };
	// Create and return the reversed graph(Directed)
	Graph* getReverseGraph();
};