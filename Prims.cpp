#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <climits>  // For INT_MAX
using namespace std;

class Graph {
    int V;
    list<pair<int, int>>* l;
    bool isUndir;

public:
    Graph(int V, bool isUndir = true) {
        this->V = V;
        l = new list<pair<int, int>>[V];
        this->isUndir = isUndir;
    }

    void addEdge(int u, int v, int wt) {
        l[u].push_back(make_pair(v, wt));
        if (isUndir) {
            l[v].push_back(make_pair(u, wt));
        }
    }

    void prims(int src) {
        vector<int> key(V, INT_MAX);
        vector<int> parent(V, -1);
        vector<bool> inMST(V, false);

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        key[src] = 0;
        pq.push({0, src});

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            if (inMST[u]) continue;
            inMST[u] = true;

            for (auto it = l[u].begin(); it != l[u].end(); ++it) {
                int v = it->first;
                int weight = it->second;
                if (!inMST[v] && weight < key[v]) {
                    key[v] = weight;
                    pq.push({key[v], v});
                    parent[v] = u;
                }
            }
        }

        int totalCost = 0;
        cout << "Edges in MST:\n";
        for (int i = 1; i < V; ++i) {
            cout << parent[i] << " - " << i << " with weight " << key[i] << "\n";
            totalCost += key[i];
        }
        cout << "Minimum cost is = " << totalCost << endl;
    }
};

int main() {
    Graph graph(4);
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 15);
    graph.addEdge(0, 3, 30);
    graph.addEdge(1, 3, 40);
    graph.addEdge(2, 3, 50);

    graph.prims(0);

    return 0;
}
