#pragma once
//Every node at the vertex List of neighborhoods.
class Node {
	// The node number.
	int value;
	// If the arc already used.
	bool isUsed;
	// For Undirected graph represent the reverse arc (two sided arc).
	Node* reverse;

public:
	// ctor's.
	Node(int _value, Node* _reverse) : value(_value), reverse(_reverse), isUsed(false) {};
	Node(int _value) : value(_value), reverse(nullptr), isUsed(false) {};
	// Set the node arc as used.
	void setUsed() { isUsed = true; };
	// Mark the arc and the reverse arc as Used.
	void markUsed() { 
		setUsed(); 
		if (reverse != nullptr) reverse->setUsed(); 
	};
	// Get if the arc is used before.
	bool getUsed() { return isUsed; };
	// Set reverse arc for existing arc.
	void setReverse(Node* _reverse) { reverse = _reverse; };
	// Get the reverse arc for specific arc.
	Node* getReverse() { return reverse; };
	//Get the arc node number.
	int getValue() { return value; };
};