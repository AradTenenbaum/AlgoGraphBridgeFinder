#pragma once
#include "Node.h"
#include <iostream>
#include <list>

class Vertex {
	// Neighbors list
	std::list<Node*> neighbors;

public:
	// Empty ctor
	Vertex() {};

	// Dtor
	~Vertex() {
		for (Node* v : neighbors) {
			delete v;
		}
	}

	// Add a neighbor to the vertex, used by add arc
	void addNeighbor(Node* newNeighbor) {
		neighbors.push_back(newNeighbor);
	}
	// Return all the neighbors of a vertex
	std::list<Node*> getNeighbors() { return neighbors; };

};