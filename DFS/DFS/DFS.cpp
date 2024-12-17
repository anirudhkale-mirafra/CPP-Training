#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector < vector <int>>&adjList, vector<bool>&visited) {
	visited[node] = true;
    cout << node << " ";// process the current node

	for(int neighbor : adjList[node]) {
		if (!visited[neighbor]) {
            dfs(neighbor, adjList, visited);
        }
    }
}

int main() {
    int V = 5; // Number of vertices
    vector<vector<int>> adj(V); // Adjacency list

    
    adj[0] = { 1, 2 };
    adj[1] = { 0, 3, 4 };
    adj[2] = { 0 };
    adj[3] = { 1 };
    adj[4] = { 1 };

    vector<bool> visited(V, false);

    cout << "DFS Traversal starting from node 0:\n";
    dfs(0, adj, visited);

    return 0;
}