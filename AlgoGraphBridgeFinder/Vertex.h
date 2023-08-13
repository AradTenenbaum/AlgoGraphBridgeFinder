#pragma once
#include "Node.h"
#include <iostream>
#include <list>

class Vertex {
	std::list<Node*> neighbors;

public:
	Vertex() {};

	void addNeighbor(Node* newNeighbor) {
		neighbors.push_back(newNeighbor);
	}

	std::list<Node*> getNeighbors() { return neighbors; };

};