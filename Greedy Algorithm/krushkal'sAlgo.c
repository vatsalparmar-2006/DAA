#include <stdio.h>

struct Edge {
    int source;
    int destination;
    int weight;
};

void sortEdges(struct Edge edges[], int E) {
    for (int i = 0; i < E - 1; i++) {
        for (int j = 0; j < E - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                struct Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

int find(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return find(parent, parent[i]);
}

void unionSet(int parent[], int u, int v) {
    parent[u] = v;
}

void kruskal(struct Edge edges[], int V, int E) {
    struct Edge mst[V - 1]; 
    int parent[V];
    int count = 0; 
    int totalCost = 0;  

    for (int i = 0; i < V; i++) {
        parent[i] = i;
    }

    sortEdges(edges, E);

    for (int i = 0; i < E && count < V - 1; i++) {
        int u = edges[i].source;
        int v = edges[i].destination;

        int ucomp = find(parent, u);
        int vcomp = find(parent, v);

        if (ucomp != vcomp) {
            mst[count] = edges[i];
            totalCost += edges[i].weight;
            count++;
            unionSet(parent, ucomp, vcomp);
        }
    }

    printf("Minimum Spanning Tree using Kruskal's Algorithm:\n");
    for (int i = 0; i < count; i++) {
        printf("Edge: %d -- %d | Weight: %d\n", mst[i].source, mst[i].destination, mst[i].weight);
    }

    printf("Total Minimum Cost: %d\n", totalCost);
}

int main() {
    int V = 4; 
    int E = 5; 

    struct Edge edges[] = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    kruskal(edges, V, E);

    return 0;
}

