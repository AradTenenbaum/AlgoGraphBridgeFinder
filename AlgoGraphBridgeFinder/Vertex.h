#pragma once
#include "Node.h"
#include <iostream>
#include <list>

class Vertex {
	std::list<Node*>::iterator position;
	std::list<Node*> neighbors;

public:
	Vertex() {
		position = neighbors.begin();
	};

	void addNeighbor(Node* newNeighbor) {
		neighbors.push_back(newNeighbor);
	}

	std::list<Node*> getNeighbors() { return neighbors; };

	void nextPos() { position++; };
	std::list<Node*>::iterator getPosition() { return position; };
};