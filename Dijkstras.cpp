// Dijkstras Algorithm: A shortest path algorithm between source to all other nodes in a graph.
// vector<int> dist;
// pq<int, int> = <dist, vertex>; dist 1st coz it sorts by first value by default(maxHeap).
// we need minHeap => priority_queue<int, vector<int>, greater<int>> pq;
// Apply BFS & do edge relaxation.
// Edge Relaxation: dist[v] > dist[u]+wt(u,v) then dist[v] = dist[u]+wt(u,v).

#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include <climits>
using namespace std;

class Edge{
    public:
    int v;
    int wt;
    Edge(int v, int wt){
        this->v = v;
        this->wt = wt;
    }
};

//TC => O((V+E)logV) similar to nlogn. Useful in +ve weight edges.
void dijkstras(int src, vector<vector<Edge>> graph, int V){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;  //minHeap.
    vector<int> dist(V, INT_MAX);

    dist[src] = 0;
    pq.push(make_pair(0, src));  // (dist, veretx).

    while(pq.size() > 0){
        int u = pq.top().second;  //front element.
        pq.pop();

        vector<Edge> edges = graph[u];  //loop in neighbors of u(popped vertex).
        for(Edge e : edges){  
            if(dist[e.v] > dist[u] + e.wt){
                dist[e.v] = dist[u] + e.wt;
                pq.push(make_pair(dist[e.v], e.v));
            }
        }
    }
    for(int d : dist){
        cout<<d<<" ";
    }
    cout<<endl;
}

int main(){

    int V=6;
    vector<vector<Edge>> graph(V);

    graph[0].push_back(Edge(1,2));
    graph[0].push_back(Edge(2,4));

    graph[1].push_back(Edge(2,1));
    graph[1].push_back(Edge(3,7));

    graph[2].push_back(Edge(4,3));
    
    graph[3].push_back(Edge(5,1));

    graph[4].push_back(Edge(3,2));
    graph[4].push_back(Edge(5,5));

    dijkstras(0, graph, V);

    return 0;
}