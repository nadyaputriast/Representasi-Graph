#include <stdio.h>
#include <stdlib.h>

#define MAX_EDGES 100

// Struct to represent an edge list
typedef struct {
    int src[MAX_EDGES];
    int dest[MAX_EDGES];
    int num_edges;
} EdgeList;

// Function to initialize an empty edge list
void initEdgeList(EdgeList *edgeList) {
    edgeList->num_edges = 0;
}

// Function to add an edge to the edge list
void addEdge(EdgeList *edgeList, int src, int dest) {
    if (edgeList->num_edges < MAX_EDGES) {
        edgeList->src[edgeList->num_edges] = src;
        edgeList->dest[edgeList->num_edges] = dest;
        edgeList->num_edges++;
    } else {
        printf("Edge list is full, cannot add more edges.\n");
    }
}

// Function to print the edge list
void printEdgeList(EdgeList *edgeList) {
    printf("Edge List:\n");
    for (int i = 0; i < edgeList->num_edges; i++) {
        printf("%d -> %d\n", edgeList->src[i], edgeList->dest[i]);
    }
}

int main() {
    EdgeList edgeList;
    initEdgeList(&edgeList);

    // Adding some example edges
    addEdge(&edgeList, 0, 1);
    addEdge(&edgeList, 1, 2);
    addEdge(&edgeList, 2, 3);
    addEdge(&edgeList, 3, 0);

    // Printing the edge list
    printEdgeList(&edgeList);

    return 0;
}
