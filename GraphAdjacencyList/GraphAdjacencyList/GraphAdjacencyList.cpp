#include<iostream>
#include<vector>
#include<list>
using namespace std;
class Graph{
private:
	int v;//  number of vertices
	vector < list<int>>adjList;// adjaceny list
public:
	Graph(int vertices) {
		v = vertices;
		adjList.resize(v);
	}

	void addEdge(int u, int v) {
		adjList[u].push_back(v);
		adjList[v].push_back(u);
	}
	void displayGraph() {
		for (int i = 0; i < v; i++) {
			cout << "Vertex " << i << ":";
			for (int neighbor : adjList[i]) {
				cout << " -> " << neighbor;
			}
			cout << endl;
		}
	}
};
int main() {
	int vertices = 5; // Total vertices
	Graph g(vertices);

	// Adding edges
	g.addEdge(0, 1);
	g.addEdge(0, 4);
	g.addEdge(1, 2);
	g.addEdge(1, 3);
	g.addEdge(1, 4);
	g.addEdge(2, 3);
	g.addEdge(3, 4);

	cout << "Adjacency List Representation of the Graph:\n";
	g.displayGraph();

	return 0;
}



