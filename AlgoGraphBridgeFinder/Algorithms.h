#pragma once
#include "Graph.h"
#include <vector>
#include "Utils.h"

class Algorithms {
	std::vector<int> endList;
public:
	void VISIT(Graph& g, int u, std::vector<COLOR*> Color);
	void endListVISIT(Graph& g, int u, std::vector<COLOR*> Color, std::vector<int>& endList, int* currentIndex);
	bool isConnectedUndirectionalGraph(Graph& g);
	void directedVISIT(Graph& g, int u, std::vector<COLOR*> Color, Graph* directG);
	Graph* DFSDirectGraph(Graph& g);
	std::vector<int> DFSReturnEndList(Graph& g);
	std::vector<int> DFSStrongConnectedComponents(Graph& g);
	void rootListVISIT(Graph& g, int u, std::vector<COLOR*> Color, std::vector<int>& Root);
private:
	std::vector<COLOR*> createColorArr(int size);
};