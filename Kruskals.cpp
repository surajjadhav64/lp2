#include<iostream>
#include<vector>
#include<algorithm>
#include<tuple> // Required for std::tuple
using namespace std;

class DSU {
    vector<int> parent;
    vector<int> rank;

public:
    DSU(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unite(int x, int y) {
        int xroot = find(x);
        int yroot = find(y);

        if (xroot != yroot) {
            if (rank[xroot] < rank[yroot]) {
                parent[xroot] = yroot;
            } else if (rank[xroot] > rank[yroot]) {
                parent[yroot] = xroot;
            } else {
                parent[yroot] = xroot;
                rank[xroot]++;
            }
        }
    }
};

class Graph {
    int V;
    vector<tuple<int, int, int>> edges; // wt, u, v

public:
    Graph(int V) {
        this->V = V;
    }

    void addEdge(int u, int v, int wt) {
        edges.push_back(make_tuple(wt, u, v));
    }

    void kruskal() {
        sort(edges.begin(), edges.end());  // Sort edges by weight
        DSU dsu(V);
        int totalCost = 0;

        for (auto edge : edges) {
            int wt = get<0>(edge);
            int u = get<1>(edge);
            int v = get<2>(edge);

            if (dsu.find(u) != dsu.find(v)) {
                dsu.unite(u, v);
                totalCost += wt;
                cout << "Edge: " << u << " - " << v << " with weight " << wt << endl;
            }
        }

        cout << "Total cost of MST: " << totalCost << endl;
    }
};

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 15);
    g.addEdge(0, 3, 30);
    g.addEdge(1, 3, 40);
    g.addEdge(2, 3, 50);

    g.kruskal();

    return 0;
}
 