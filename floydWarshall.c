#include <stdio.h>
#include <limits.h>

#define inf 9999

int main() 
{
    printf("Shortest Path using Floyd-Warshall Algorithm\n");
    printf("============================================\n");

    int vertex;

    printf("Masukkan banyak vertex: ");
    scanf("%d", &vertex);

    int dist[vertex][vertex];

    printf("Masukkan matriks ketetanggaan (gunakan 9999 jika tidak terhubung):\n");
    for (int i = 0; i < vertex; i++) 
        for (int j = 0; j < vertex; j++) 
        {
            int value;
            scanf("%d", &value);
            if (value == 9999) 
                dist[i][j] = inf;
            else 
            {
                dist[i][j] = value;
            }
        }
    
    // Floyd-Warshall algorithm
    for (int k = 0; k < vertex; k++) 
        for (int i = 0; i < vertex; i++) 
            for (int j = 0; j < vertex; j++) 
            {
                if (dist[i][k] != inf && dist[k][j] != inf && dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];
            }
    printf("\n");

    printf("Jarak terpendek antara dua buah vertex:\n");
    printf("Vertex\t");
    for (int j = 0; j < vertex; j++) 
        printf("%d\t", j + 1);
    printf("\n");

    for (int i = 0; i < vertex; i++) 
    {
        printf("%d\t", i + 1);
        for (int j = 0; j < vertex; j++) 
        {
            if (dist[i][j] == inf) 
                printf("∞\t");
            else 
                printf("%d\t", dist[i][j]);
        }
        printf("\n");
    }

    return 0;
}