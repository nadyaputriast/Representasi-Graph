#include <stdio.h>

void kode(); 

int main() 
{
    printf("Pemberian Kode pada Graph Pohon\n");
    printf("===============================\n");
    kode();
    return 0;
}

void kode() 
{
    int v, i, j, e, min, a; //v = vertex, e = edge, min = minimum, a = index minimum
    printf("Masukkan Jumlah Vertex: ");
    scanf("%d", &v);
    e = v - 1;
    int edge[e][2], derajat[v + 1];

    for (i = 1; i <= v; i++) 
    {
        derajat[i] = 0;
    }

    printf("Antar edge dipisah dengan enter.\n");
    for (i = 0; i < e; i++) 
    {
        printf("Masukkan edge ke-%d: \n", i + 1);
        scanf("%d %d", &edge[i][0], &edge[i][1]);
        derajat[edge[i][0]]++;
        derajat[edge[i][1]]++;
    }
    printf("\n");

    printf("Total derajat untuk setiap vertex-nya: \n");
    for (i = 1; i <= v; i++) 
    {
        printf("Derajat vertex ke-%d -> %d\n", i, derajat[i]);
    }
    printf("\n");
    
    printf("Kode Prufer: ");
    for (i = 0; i < v - 2; i++) 
    {
        min = 999;
        for (j = 0; j < e; j++) 
        {
            if (derajat[edge[j][0]] && derajat[edge[j][1]] != 0) 
            {
                if (derajat[edge[j][0]] == 1) 
                {
                    if (min > edge[j][0]) 
                    {
                        min = edge[j][0];
                        a = j;
                    }
                }
                else if (derajat[edge[j][1]] == 1) 
                {
                    if (min > edge[j][1]) 
                    {
                        min = edge[j][1];
                        a = j;
                    }
                }
            }
        }
        
        derajat[edge[a][0]]--;
        derajat[edge[a][1]]--;

        if (derajat[edge[a][0]] == 0) 
        {
            printf("%d ", edge[a][1]);
        } 
        else 
        {
            printf("%d ", edge[a][0]);
        }
    }
}

/*

Pemberian kode pada graph pohon
A. Hitung manual
1. Mencari vertex berderajat 1 dengan inisial nama vertex paling kecil/angka paling kecil (V_t)
2. Cari vertex yang terhubung dengan V_t (V_h)
3. Gunakan V_h sebagai kode
4. Hapus edge yang menghubungkan V_t dengan V_h
5. Ulangi langkah 1-4 sampai tersisa 1 buah edge pada graph

Contoh Matriks Ketetanggaan:
0 1 1 0 0 0 0 
1 0 0 1 1 1 0
1 0 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 0
0 1 0 0 0 0 1
0 0 0 0 0 1 0

Kode pada pohon: 12226
*/