#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

struct Edge {
    char src, dest;
    int weight;
};

struct Subset {
    int parent, rank;
};

class Graph {
    int V;
    vector<Edge> edges;
    int steps;

public:
    Graph(int v) : V(v), steps(0) {}

    void addEdge(char src, char dest, int weight) {
        Edge edge = {src, dest, weight};
        edges.push_back(edge);
    }

    int find(Subset subsets[], int i) {
       
        if (subsets[i].parent != i) {
            steps++;
            subsets[i].parent = find(subsets, subsets[i].parent);
        }
        return subsets[i].parent;
    }

    void Union(Subset subsets[], int x, int y) {
        steps++;
        int xroot = find(subsets, x);
        int yroot = find(subsets, y);

        if (subsets[xroot].rank < subsets[yroot].rank) {
            steps++;
            subsets[xroot].parent = yroot;
        } else if (subsets[xroot].rank > subsets[yroot].rank) {
            steps++;
            subsets[yroot].parent = xroot;
        } else {
            steps++;
            subsets[yroot].parent = xroot;
            subsets[xroot].rank++;
        }
    }

    static bool compareEdges(const Edge &a, const Edge &b) {
        return a.weight < b.weight;
    }

    void KruskalMST() {
        vector<Edge> result;
        int e = 0, i = 0;
        int totalWeight = 0;
        sort(edges.begin(), edges.end(), compareEdges);
        Subset *subsets = new Subset[V];
        for (int v = 0; v < V; ++v) {
            steps++;
            subsets[v].parent = v;
            subsets[v].rank = 0;
        }
        while (e < V - 1 && i < edges.size()) {
            Edge next_edge = edges[i++];
            int x = find(subsets, next_edge.src - 'a');
            int y = find(subsets, next_edge.dest - 'a');
            steps +=2;
            if (x != y) {
                result.push_back(next_edge);
                Union(subsets, x, y);
                e++;
               
                totalWeight += next_edge.weight;
            }
        }
        cout << "Edges of MST are:" << endl;
        for (i = 0; i < result.size(); ++i)
            cout << result[i].src << " -- " << result[i].dest << " == " << result[i].weight << endl;
        cout << "Total weight of MST: " << totalWeight << endl;
        cout << "Number of steps executed: " << steps << endl;
    }
};

int main() {
    int V, E;
    cout << "Enter the number of vertices and edges: ";
    cin >> V >> E;
    Graph graph(V);
    cout << "Enter edges (src, dest, weight):" << endl;
    for (int i = 0; i < E; ++i) {
        char src, dest;
        int weight;
        cin >> src >> dest >> weight;
        graph.addEdge(src, dest, weight);
    }
    graph.KruskalMST();
    return 0;
}