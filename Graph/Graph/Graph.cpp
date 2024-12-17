#include<iostream>
#include<vector>
using namespace std;
class Graph {
private:
	int numVertices;
	vector<vector<int>>adjMatrix;
	bool isDirected;
public:
	Graph(int vertices, bool directed) {
		numVertices = vertices;
		isDirected = directed;
		adjMatrix.resize(numVertices, vector<int>(numVertices,0));// initializing the matrix with zero

	}
	void addEdge(int u, int v) {
		if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
			adjMatrix[u][v] = 1;
			if(isDirected)
				adjMatrix[v][u] = 1;
		}
		else {
			cout << "Invalid input. " << endl;
		}
	}
	void removeEdge(int u, int v) {
		if (u >= 0 && u < numVertices && v >= 0 && v < numVertices) {
			if (adjMatrix[u][v]) {

					adjMatrix[u][v] = 0;
					if (!isDirected) 
						adjMatrix[v][u] = 0;
					
					cout << "edge removed successfully: " << endl;

			} 
			else {
				cout << "There is no edge present between: " << u << " and " << v <<"."<< endl;
			}
		}
		else {
			cout << "Invalid input given" << endl;
		}
	}
	void displayMatrix() {
		cout<<"Adjacency Matrix : ("<<(isDirected?"directed" : "undirected ")<<"Graph ):"<<endl;
		for (int i = 0;i < numVertices;i++) {
			for (int j = 0; j < numVertices;j++) {
				cout << adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
};
int main() {
	// Create a directed graph with 4 vertices (0, 1, 2, 3)
	Graph directedGraph(4, true);
	directedGraph.addEdge(0, 1);
	directedGraph.addEdge(1, 2);
	directedGraph.addEdge(2, 3);
	directedGraph.removeEdge(1, 2);
	directedGraph.displayMatrix();

	// Create an undirected graph with 4 vertices (0, 1, 2, 3)
	Graph undirectedGraph(4, false);
	undirectedGraph.addEdge(0, 1);
	undirectedGraph.addEdge(0, 2);
	undirectedGraph.addEdge(1, 3);
	undirectedGraph.displayMatrix();

	return 0;
}
