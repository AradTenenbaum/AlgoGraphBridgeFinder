#pragma once
#include "Graph.h"
#include <vector>
#include "Utils.h"

class Algorithms {
	std::vector<int> endList;
public:
	Graph* DFSDirectGraph(Graph& g);
	void VISIT(Graph& g, int u, std::vector<COLOR*> Color);
	bool isConnectedUndirectionalGraph(Graph& g);
	void directedVISIT(Graph& g, int u, std::vector<COLOR*> Color, Graph* directG);
private:
	std::vector<COLOR*> createColorArr(int size);
};