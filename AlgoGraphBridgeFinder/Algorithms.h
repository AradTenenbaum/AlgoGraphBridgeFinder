#pragma once
#include "Graph.h"
#include <vector>
#include "Utils.h"

class Algorithms {
public:
	// The function receives a graph and return true if it is connected, else false
	bool isConnectedUndirectionalGraph(Graph& g);
	// The function runs dfs to direct g, return the new directed graph
	Graph* DFSDirectGraph(Graph& g);
	// The function print the bridges in the graph
	void printBridgesInGraph(Graph& g, std::vector<int> insertionOrder);
private:
	// The function runs dfs and returns the end list of the dfs on the graph 
	std::vector<int> DFSReturnEndList(Graph& g);
	// The function runs dfs and return all the S.C.C from the graph
	std::vector<int> DFSStrongConnectedComponents(Graph& g);
	// The function runs visit on the vertex u on the graph
	void VISIT(Graph& g, int u, std::vector<COLOR*> Color);
	// The fucntion runs visit on the vertex u on the graph and builds end list
	void endListVISIT(Graph& g, int u, std::vector<COLOR*> Color, std::vector<int>& endList, int* currentIndex);
	// The fucntion runs visit on the vertex u on the graph and builds the directed graph
	void directedVISIT(Graph& g, int u, std::vector<COLOR*> Color, Graph* directG);
	// The fucntion runs visit on the vertex u on the graph 
	// and builds the roots list for the S.C.C
	void rootListVISIT(Graph& g, int u, std::vector<COLOR*> Color, std::vector<int>& Root);
	// The function creates a new color vector to use for each DFS function
	std::vector<COLOR*> createColorArr(int size);
};