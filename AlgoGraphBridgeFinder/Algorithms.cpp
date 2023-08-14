#include "Algorithms.h"

using namespace std;


Graph* Algorithms::DFSDirectGraph(Graph& g) {
	vector<COLOR*> Color = createColorArr(g.getSize());

	Graph* directedG = new Graph(DIRECTIONED, g.getSize());

	// MAIN LOOP
	for (int i = 1; i < g.getSize(); i++) {
		if (*Color[i - 1] == WHITE)
			directedVISIT(g, i, Color, directedG);
	}

	return directedG;
}

vector<int> Algorithms::DFSReturnEndList(Graph& g) {
	vector<COLOR*> Color = createColorArr(g.getSize());
	vector<int> endList;
	endList.resize(g.getSize());

	int currentIndex = 0;

	// MAIN LOOP
	for (int i = 1; i < g.getSize(); i++) {
		if (*Color[i - 1] == WHITE)
			endListVISIT(g, i, Color, endList, &currentIndex);
	}

	return endList;
}

vector<int> Algorithms::DFSStrongConnectedComponents(Graph& g) {
	vector<int> endList = DFSReturnEndList(g);
	Graph* reverseG = g.getReverseGraph();

	vector<COLOR*> Color = createColorArr(g.getSize());

	vector<int> Root;
	Root.resize(reverseG->getSize());

	// MAIN LOOP
	for (int i = reverseG->getSize()-1; i >= 0; i--) {
		//if (Root[endList[i] - 1] == 0) {
		//	Root[endList[i] - 1] = endList[i];
		//}
		if (*Color[endList[i] - 1] == WHITE) {
			Root[endList[i] - 1] = endList[i];
			rootListVISIT(*reverseG, endList[i], Color, Root);
		}
	}

	return Root;
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
		if (*Color[i] != BLACK)
			return false;
	}
	return true;
}

void Algorithms::VISIT(Graph& g, int u, vector<COLOR*> Color) {
	*Color[u - 1] = GREY;
	
	for (Node* v : g.getVertex(u)->getNeighbors()) { //לבדוק שלא חוזרים על קשתות פעמיים כשחוזרים מהרקורסיה
		if (*Color[v->getValue() - 1] == WHITE) {
			VISIT(g, v->getValue(), Color);
		}
	}

	*Color[u - 1] = BLACK;
}

void Algorithms::endListVISIT(Graph& g, int u, vector<COLOR*> Color, vector<int>& endList, int* currentIndex) {
	*Color[u - 1] = GREY;

	for (Node* v : g.getVertex(u)->getNeighbors()) {
		if (*Color[v->getValue() - 1] == WHITE) {
			endListVISIT(g, v->getValue(), Color, endList, currentIndex);
		}
	}

	*Color[u - 1] = BLACK;
	endList[*currentIndex] = u;
	(*currentIndex)++;
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

void Algorithms::rootListVISIT(Graph& g, int u, vector<COLOR*> Color, vector<int>& Root) {
	*Color[u - 1] = GREY;

	for (Node* v : g.getVertex(u)->getNeighbors()) {
		if (*Color[v->getValue() - 1] == WHITE) {
			Root[v->getValue()-1] = Root[u-1];
			rootListVISIT(g, v->getValue(), Color, Root);
		}
	}

	*Color[u - 1] = BLACK;
}