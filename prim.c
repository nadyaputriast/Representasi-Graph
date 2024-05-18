#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Minimum Spanning Tree (MST) using Prim Algorithm\n");
    printf("=================================================\n");

    int jumlahvertex;

    printf("Masukkan jumlah vertex: ");
    scanf("%d", &jumlahvertex);

    int matriks[jumlahvertex][jumlahvertex];
    for (int i = 0; i < jumlahvertex; i++) 
    {
        for (int j = 0; j < jumlahvertex; j++) 
        {
            matriks[i][j] = 0; // Inisialisasi matriks dengan 0
        }
    }

    // Meminta input bobot edge antar vertex
    printf("Masukkan bobot edge antar vertex (0 jika tidak terhubung):\n");
    for (int i = 0; i < jumlahvertex; i++) 
    {
        for (int j = i + 1; j < jumlahvertex; j++) 
        {
            int bobot;
            printf("Masukkan bobot edge dari vertex %d ke vertex %d: ", i + 1, j + 1);
            scanf("%d", &bobot);
            // Simpan bobot edge dalam matriks adjacency
            matriks[i][j] = matriks[j][i] = bobot;
        }
    }

    // Variabel untuk algoritma MST
    int mst = 0;
    int tree[jumlahvertex - 1][3];
    int visited[jumlahvertex];

    for (int i = 0; i < jumlahvertex; i++) 
        visited[i] = 0;
    visited[0] = 1;

    int k = 0; // Counter untuk edge MST
    while (k < jumlahvertex - 1) 
    {
        int min_bobot = -1;
        int min_vertex1, min_vertex2;

        // Mencari edge terkecil yang belum dipilih
        for (int i = 0; i < jumlahvertex; i++) 
        {
            if (visited[i] == 1) 
            {
                for (int j = 0; j < jumlahvertex; j++) 
                {
                    if (matriks[i][j] != 0 && visited[j] == 0) 
                    {
                        if (min_bobot == -1 || matriks[i][j] < min_bobot) 
                        {
                            min_bobot = matriks[i][j];
                            min_vertex1 = i;
                            min_vertex2 = j;
                        }
                    }
                }
            }
        }

        // Menyimpan edge dengan bobot terkecil ke dalam MST
        tree[k][0] = min_vertex1 + 1; // vertex1 (diindeks dari 1)
        tree[k][1] = min_vertex2 + 1; // vertex2 (diindeks dari 1)
        tree[k][2] = min_bobot;       // bobot
        mst += min_bobot;

        // Tandai vertex yang sudah dipilih
        visited[min_vertex2] = 1;
        k++;

        // Output langkah pembentukan MST
        printf("%d - %d bobot %d, total MST: %d\n", tree[k - 1][0], tree[k - 1][1], tree[k - 1][2], mst);
    }

    return 0;
}