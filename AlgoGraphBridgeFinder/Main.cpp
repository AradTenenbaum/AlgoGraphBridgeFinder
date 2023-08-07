#include <iostream>
#include "Graph.h"

using namespace std;

int main()
{
	int n,m;
	cin >> n;
	Graph graph = Graph(UNDIRECTIONED, n);
	cin >> m;

	int from, to;

	for (int i = 0; i < m; i++) {
		cout << "from: " << endl;
		cin >> from;
		cout << "to: " << endl;
		cin >> to;

		graph.addArc(from, to);
	}

	return 0;
}