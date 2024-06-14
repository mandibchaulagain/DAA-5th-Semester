#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

#define V 6

int minDistance(int dist[], bool sptSet[]) {
    int min = INT_MAX, min_index;
   
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_index = v;

    return min_index;
}

void printSolution(int dist[], int parent[], int steps) {
    printf("Vertex \t Distance from Source \t Path\n");
    for (int i = 0; i < V; i++) {
        printf("%c \t %d \t\t\t ", 'a' + i, dist[i]);
        int j = i;
        while (parent[j] != -1) {
            printf("%c <- ", 'a' + j);
            j = parent[j];
        }
        printf("%c\n", 'a' + j);
    }
    printf("Total steps: %d\n", steps);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V];    
    int parent[V];  
    bool sptSet[V];
    int steps = 0; // Variable to count steps
   
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false, parent[i] = -1;
   
    dist[src] = 0;
   
    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        steps++; // Increment steps when selecting next vertex
       
        sptSet[u] = true;
       
        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                parent[v] = u;
                steps++;
            }
        }
    }
   
    printSolution(dist, parent, steps);
}

int main() {

    int graph[V][V] = {
        {0, 4, 2, 0, 0, 0},
        {0, 0, 1, 5, 0, 0},
        {0, 0, 0, 8, 10, 0},
        {0, 0, 0, 0, 2, 6},
        {0, 0, 0, 0, 0, 3},
        {0, 0, 0, 0, 0, 0}
    };

    dijkstra(graph, 0);
    return 0;
}
