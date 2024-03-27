#include <stdio.h>

#define MAX_VERTICES 100

int adjacency_matrix[MAX_VERTICES][MAX_VERTICES];

// Inisialisasi matriks adjacency dengan 0
void initialize_matrix(int vertices) {
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            adjacency_matrix[i][j] = 0;
        }
    }
}

// Menambahkan sisi ke matriks adjacency
void add_edge(int from, int to) {
    adjacency_matrix[from][to] = 1;
}

// Mencetak matriks adjacency
void print_adjacency_matrix(int vertices) {
    printf("Matriks Adjacency:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacency_matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int vertices, edges, from, to;

    printf("Masukkan jumlah simpul (vertices): ");
    scanf("%d", &vertices);

    printf("Masukkan jumlah sisi (edges): ");
    scanf("%d", &edges);

    initialize_matrix(vertices);

    printf("Masukkan sisi-sisi (from to):\n");
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &from, &to);
        add_edge(from, to);
    }

    print_adjacency_matrix(vertices);

    return 0;
}
