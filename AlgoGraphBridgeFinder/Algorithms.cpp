#include "Algorithms.h"

using namespace std;

Graph Algorithms::DFSDirectGraph(Graph& g) {
	vector<COLOR> Color;
	Color.resize(g.getSize());

	// INIT
	fill(Color.begin(), Color.end(), WHITE);

	// MAIN LOOP

}

void Algorithms::VISIT(Graph& g, int u, vector<COLOR> Color) {
	Color[u - 1] = GREY;
	std::list<Node*>::iterator it = g.getVertex(u)->getPosition();
	for (; it != g.getVertex(u)->getNeighbors().end(); ) {
		if (Color[(*it)->getValue() - 1] == WHITE) {
			++it;
			(*it)->setUsed();
		}
	}
}