#include <stdio.h>

int main()
{
    printf("Rekontruksi Kode pada Graph Pohon\n");
    printf("==================================\n");

    int banyakKode;
    printf("Masukkan banyaknya kode: ");
    scanf("%d", &banyakKode);

    int banyakVertex = banyakKode + 2;
    int kode[banyakKode];
    int vertex[banyakVertex];
    int edge[banyakVertex - 1][2];

    for(int i = 0; i < banyakVertex; i++)
    {
        vertex[i] = 0;
    }

    printf("Masukkan kode (pisah antarkarakter dengan spasi): ");
    for(int i = 0; i < banyakKode; i++)
    {
        scanf("%d", &kode[i]);
    }

    //mencari frekuensi vertex 
    for(int i = 0; i < banyakKode; i++)
    {
        vertex[kode[i] - 1] += 1;
    }

    //mencari edge (wita)
    int terkecil = 0; 
    for(int i = 0; i < banyakKode; i++)
    {
        for(int j = 0; j < banyakVertex; j++)
        {
            if(vertex[j] == 0)
            {
                vertex[j] = -1;
                edge[terkecil][1] = j + 1;
                edge[terkecil][0] = kode[i];
                vertex[kode[i] - 1]--;
                terkecil++;
                break;
            }
        }
    }

    //mencari 2 angka terakhir
    int k = 0;
    int n1, n2;
    for(int i = 0;  i < banyakVertex; i++)
    {
        if(vertex[i] == 0 && k == 0)
        {
            n1 = i + 1;
            k++;
        }
        else if(vertex[i] == 0 && k == 1)
        {
            n2 = i + 1;
        }
    }

    edge[banyakVertex - 2][0] = n1;
    edge[banyakVertex - 2][1] = n2;

    printf("Hasil rekontruksi kode prufer: \n");
    for(int i = 0; i < banyakVertex - 1; i++)
    {
        printf("%d %d\n", edge[i][0], edge[i][1]);
    }

    return 0;
}