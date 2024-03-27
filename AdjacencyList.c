#include <stdio.h>

int main() {
    int vertices, edges;

    printf("Masukkan jumlah vertek: ");
    scanf("%d", &vertices);

    printf("Masukkan jumlah sisi: ");
    scanf("%d", &edges);

    int adj[vertices][vertices];

    printf("Masukkan daftar sisi:\n");
    for (int i = 0; i < edges; ++i) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        adj[src - 1][dest - 1] = 1;
        adj[dest - 1][src - 1] = 1;
    }

    printf("\nAdjacency List:\n");
    for (int i = 0; i < vertices; ++i) {
        printf("Vertex %d: ", i + 1);
        for (int j = 0; j < vertices; ++j) {
            if (adj[i][j] == 1) {
                printf("%d ", j + 1);
            }
        }
        printf("\n");
    }

    return 0;
}
