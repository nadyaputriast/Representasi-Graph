#include <stdio.h>
#include <limits.h>

#define inf INT_MAX

int main() 
{
    printf("Shortest Path using Bellman Ford Algorithm\n");
    printf("==========================================\n");

    int vertex, edge;
    printf("Masukkan banyak vertex: ");
    scanf("%d", &vertex);

    printf("Masukkan banyak edge: ");
    scanf("%d", &edge);

    int edges[edge][3];
    int min_vertex = inf;

    printf("Masukkan pasangan edge dan bobotnya (u v w) dimana u -> v dengan bobot w:\n");
    for(int i = 0; i < edge; i++) 
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        edges[i][0] = u;
        edges[i][1] = v;
        edges[i][2] = w;
        if (u < min_vertex) min_vertex = u;
        if (v < min_vertex) min_vertex = v;
    }

    int source;
    printf("Masukkan vertex asal: ");
    scanf("%d", &source);

    int dist[vertex];
    for(int i = 0; i < vertex; i++) 
        dist[i] = inf;
    dist[source] = 0;

    for(int i = 0; i < vertex - 1; i++) 
        for(int j = 0; j < edge; j++) 
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int w = edges[j][2];
            if(dist[u - min_vertex] != inf && dist[u - min_vertex] + w < dist[v - min_vertex])
                dist[v - min_vertex] = dist[u - min_vertex] + w;
        }

    // Mengecek apakah graf memiliki siklus negatif
    for(int i = 0; i < edge; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        int w = edges[i][2];
        if(dist[u - min_vertex] != inf && dist[u - min_vertex] + w < dist[v - min_vertex]) 
        {
            printf("Graf ini memiliki siklus negatif\n");
            return 0;
        }
    }

    printf("\nVertex\tJarak dari vertex asal\n");
    for(int i = 0; i < vertex; i++) 
    {
        printf("%d\t\t", i + min_vertex);
        if(dist[i] == inf) 
            printf("∞\n");
        else 
            printf("%d\n", dist[i]);
    }

    return 0;
}