#pragma once
class Node {
	int value;
	bool isUsed;
	Node* reverse;

public:
	Node(int _value, Node* _reverse) : value(_value), reverse(_reverse), isUsed(false) {};
	Node(int _value) : value(_value), reverse(nullptr), isUsed(false) {};

	void setUsed() { isUsed = true; };
	void markUsed() { 
		setUsed(); 
		if (reverse != nullptr) reverse->setUsed(); 
	};
	bool getUsed() { return isUsed; };
	void setReverse(Node* _reverse) { reverse = _reverse; };
	Node* getReverse() { return reverse; };
	int getValue() { return value; };
};