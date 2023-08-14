/*
Welcome to Algorithms project of Arad Tenenbaum and Lior Barak
You need to enter the number of vertexes and the number of arcs
The vertexes are numbered from 1 to the number you entered
If the graph is not connected you will be notified by the program
If it is connected the program will print all the bridges in the graph
*/
#include <iostream>
#include "Graph.h"
#include "Algorithms.h"

using namespace std;

int main()
{
	int n,m;
	cin >> n;
	cin >> m;
	if (n <= 0 || m < 0) {
		cout << "Invalid input" << endl;
		exit(1);
	}

	Graph graph = Graph(UNDIRECTIONED, n);

	vector<int> insertionOrder;
	insertionOrder.resize(2 * m);


	int from, to;

	for (int i = 0; i < m; i++) {
		cin >> from;
		cin >> to;
		if (to > n || to < 1 || from > n || from < 1) {
			cout << "Invalid input" << endl;
			exit(1);
		}
		insertionOrder[2 * i] = from;
		insertionOrder[(2 * i) + 1] = to;
		graph.addArc(from, to);
	}

	Algorithms algo = Algorithms();
	if (!algo.isConnectedUndirectionalGraph(graph)) {
		cout << "Graph is not connected" << endl;
	}
	else {
		Graph* directedGraph = algo.DFSDirectGraph(graph);
		algo.printBridgesInGraph(*directedGraph, insertionOrder);
		delete directedGraph;
	}


	return 0;
}