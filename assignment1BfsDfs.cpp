#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void DFS(int node, const vector<vector<int>>& adj, vector<bool>& visited) {
    visited[node] = true;
    cout << node << " ";
    for (int neighbor : adj[node]) {
        if (!visited[neighbor]) {
            DFS(neighbor, adj, visited);
        }
    }
}

void BFS(int start, const vector<vector<int>>& adj, vector<bool>& visited) {
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        cout << node << " ";

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
}

int main() {
    int v, e;
    cout << "Enter the number of vertices: ";
    cin >> v;
    cout << "Enter the number of edges: ";
    cin >> e;

    vector<vector<int>> adj(v);
    cout << "Enter " << e << " edges (as pairs of vertices):" << endl;
    for (int i = 0; i < e; ++i) {
        int u, vtx;
        cin >> u >> vtx;
        adj[u].push_back(vtx);
        adj[vtx].push_back(u); // undirected graph
    }

    int choice;
    do {
        cout << "\n--- Menu ---\n";
        cout << "1. DFS Traversal\n";
        cout << "2. BFS Traversal\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                vector<bool> visited(v, false);
                int start;
                cout << "Enter starting node for DFS: ";
                cin >> start;
                cout << "DFS Traversal: ";
                DFS(start, adj, visited);
                cout << endl;
                break;
            }
            case 2: {
                vector<bool> visited(v, false);
                int start;
                cout << "Enter starting node for BFS: ";
                cin >> start;
                cout << "BFS Traversal: ";
                BFS(start, adj, visited);
                cout << endl;
                break;
            }
            case 3:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 3);

    return 0;
}


// Time Complexity	Space Complexity
// DFS	O(v + e)	O(v)
// BFS	O(v + e)	O(v)