#include <stdio.h>

int main() {
    printf("Coloring Graph using Greedy Algorithm.\n");
    printf("======================================\n\n");

    int matrix[15][15]; // Matriks ketetanggaan
    int degree[15][2] = {0}; // Derajat
    int color[15] = {0}; // Warna
    int vertices;

    printf("Input jumlah vertex: ");
    scanf("%d", &vertices);
    printf("\n");

    printf("Masukkan urutan simpul dalam derajat yang diinginkan:\n");
    for(int i = 1; i <= vertices; i++)
    {
        printf("Urutan %d: ", i);
        scanf("%d", &degree[i][0]);
    }

    for (int i = 1; i <= vertices; i++) 
    {
        for (int j = 1; j <= vertices; j++) 
        {
            if (i != j) 
            {
                printf("Jika vertex %d dan vertex %d berhubungan, ketik 1, jika tidak ketik 0: ", i, j);
                scanf("%d", &matrix[i][j]);
            }
            else 
            {
                matrix[i][j] = 0;
            }
        }
    }

    // Algoritma Greedy untuk pewarnaan
    int available[15] = {0}; // Array untuk menandai ketersediaan warna
    for (int i = 1; i <= vertices; i++) 
    {
        int vertex = degree[i][0];
        // Reset ketersediaan warna
        for (int j = 1; j <= vertices; j++) 
        {
            available[j] = 1;
        }
        // Cek warna tetangga dan tandai warna yang tidak tersedia
        for (int j = 1; j <= vertices; j++) 
        {
            if (matrix[vertex][j] == 1 && color[j] != 0) 
            {
                available[color[j]] = 0;
            }
        }
        // Temukan warna yang tersedia dan berikan ke simpul
        for (int j = 1; j <= vertices; j++) 
        {
            if (available[j] == 1) 
            {
                color[vertex] = j;
                break;
            }
        }
    }
    printf("\n");

    printf("Tampilkan graph dalam matriks ketetanggaan: \n\n");
    for (int i = 1; i <= vertices; i++) 
    {
        for (int j = 1; j <= vertices; j++) 
        {
            printf("%d", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("Hasil pewarnaan dengan algoritma Greedy: \n");
    for (int i = 1; i <= vertices; i++) 
    {
        printf("Simpul %d: Warna %d\n", i, color[i]);
    }

    return 0;
}