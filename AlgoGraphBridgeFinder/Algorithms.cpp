#include "Algorithms.h"

using namespace std;


Graph* Algorithms::DFSDirectGraph(Graph& g) {
	vector<COLOR*> Color = createColorArr(g.getSize());

	Graph* directedG = new Graph(DIRECTIONED, g.getSize());

	// MAIN LOOP
	for (int i = 1; i < g.getSize(); i++) {
		if (*Color[i - 1] == WHITE) directedVISIT(g, i, Color, directedG);
	}

	return directedG;
}

vector<COLOR*> Algorithms::createColorArr(int size) {
	vector<COLOR*> Color;
	Color.resize(size);

	for (int i = 0; i < size; i++) {
		Color[i] = new COLOR(WHITE);
	}

	return Color;
}

bool Algorithms::isConnectedUndirectionalGraph(Graph& g) {
	vector<COLOR*> Color = createColorArr(g.getSize());
	VISIT(g, 1, Color);
	for (int i = 0; i < g.getSize(); i++) {
		if (*Color[i] != BLACK) return false;
	}
	return true;
}

void Algorithms::VISIT(Graph& g, int u, vector<COLOR*> Color) {
	*Color[u - 1] = GREY;
	
	for (Node* v : g.getVertex(u)->getNeighbors()) {
		if (*Color[v->getValue() - 1] == WHITE) {
			//v->markUsed();
			VISIT(g, v->getValue(), Color);
		}
	}

	*Color[u - 1] = BLACK;
}

void Algorithms::directedVISIT(Graph& g, int u, vector<COLOR*> Color, Graph* directG) {
	*Color[u - 1] = GREY;

	for (Node* v : g.getVertex(u)->getNeighbors()) {
		if (!v->getUsed()) {
			directG->addArc(u, v->getValue());
			v->markUsed();
		}
		if (*Color[v->getValue() - 1] == WHITE) {
			directedVISIT(g, v->getValue(), Color, directG);
		}
	}

	*Color[u - 1] = BLACK;
}