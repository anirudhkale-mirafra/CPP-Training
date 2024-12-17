#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void bfs(int node, vector < vector<int>>adjList, vector<bool>visited) {
	queue<int>q;
	q.push(node);
	visited[node] = true;

	while (!q.empty()) {
		int x = q.front();
		cout << x << " ";
		q.pop();
		for (int i : adjList[x]) {
			if (!visited[i]) {
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main() {
	int V = 5; 
	vector<vector<int>> adj(V);

	// Example graph (undirected)
	adj[0] = { 1, 2 };
	adj[1] = { 0, 3, 4 };
	adj[2] = { 0 };
	adj[3] = { 1 };
	adj[4] = { 1 };

	vector<bool> visited(V, false); // Visited array initialized to false

	cout << "DFS Traversal starting from node 0:\n";
	bfs(0, adj, visited);

	return 0;
}