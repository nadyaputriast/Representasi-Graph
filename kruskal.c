#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Minimum Spanning Tree (MST) using Kruskal Algorithm\n");
    printf("===================================================\n");

    int jumlahvertex;
    printf("Masukkan jumlah vertex: ");
    scanf("%d", &jumlahvertex);

    int matriks[jumlahvertex][jumlahvertex];
    for (int i = 0; i < jumlahvertex; i++) 
    {
        for (int j = 0; j < jumlahvertex; j++) 
        {
            matriks[i][j] = 0; // Inisialisasi matriks adjacency dengan 0
        }
    }

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
    printf("\n");

    // Array untuk menyimpan semua edge
    int edges[jumlahvertex * (jumlahvertex - 1) / 2][3];
    int edgeCount = 0;

    // Memasukkan semua edge yang memiliki bobot > 0 ke dalam array edges
    for (int i = 0; i < jumlahvertex; i++) 
    {
        for (int j = i + 1; j < jumlahvertex; j++) 
        {
            if (matriks[i][j] > 0) 
            {
                edges[edgeCount][0] = i; // src
                edges[edgeCount][1] = j; // dest
                edges[edgeCount][2] = matriks[i][j]; // weight
                edgeCount++;
            }
        }
    }

    // Sorting semua edge berdasarkan bobot dengan bubble sort
    for (int i = 0; i < edgeCount - 1; i++) 
    {
        for (int j = 0; j < edgeCount - i - 1; j++) 
        {
            if (edges[j][2] > edges[j + 1][2]) 
            {
                // Swap
                int temp[3];
                temp[0] = edges[j][0];
                temp[1] = edges[j][1];
                temp[2] = edges[j][2];
                edges[j][0] = edges[j + 1][0];
                edges[j][1] = edges[j + 1][1];
                edges[j][2] = edges[j + 1][2];
                edges[j + 1][0] = temp[0];
                edges[j + 1][1] = temp[1];
                edges[j + 1][2] = temp[2];
            }
        }
    }

    // Array untuk menyimpan parent dari set (untuk Union-Find)
    int parent[jumlahvertex];

    for (int i = 0; i < jumlahvertex; i++) 
    {
        parent[i] = i; 
    }

    int mstWeight = 0;
    int mstEdgeCount = 0;
    int idx = 0;

    // Pilih edge dengan bobot terkecil dan tambahkan ke MST
    while (mstEdgeCount < jumlahvertex - 1 && idx < edgeCount) 
    {
        int u = edges[idx][0];
        int v = edges[idx][1];
        int weight = edges[idx][2];
        idx++;

        int uRoot = u;
        int vRoot = v;

        while (parent[uRoot] != uRoot) 
        {
            uRoot = parent[uRoot];
        }
        while (parent[vRoot] != vRoot) 
        {
            vRoot = parent[vRoot];
        }
        //selama parent[x] != x, ubah x = parent[x]
        
        if (uRoot != vRoot) 
        {
            printf("%d - %d bobot %d total MST = %d\n", u + 1, v + 1, weight, mstWeight + weight);
            mstWeight += weight;
            parent[vRoot] = uRoot; 
            mstEdgeCount++;
        }
    }

    return 0;
}