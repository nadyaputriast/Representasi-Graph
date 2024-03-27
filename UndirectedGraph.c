#include <stdio.h>

int main() 
{
    printf("Program Matriks Ketetanggaan - Graf Tidak berarah (Undirected Graph)\n\n");

    int a[7][7];
    int baris;

    printf("Input banyak vertex: ");
    scanf("%d", &baris);

    for(int i = 1; i <= baris; i++)
    {
        for(int j = i + 1; j <= baris; j++) // Loop hanya di atas diagonal utama
        {
            printf("Jika vertex %d dan vertex %d terhubung, tulis 1, jika tidak tulis 0: ", i, j);
            scanf("%d", &a[i][j]);
            a[j][i] = a[i][j]; // Simetris
        }
    }

    printf("\nMatriks ketetanggaan untuk Graf Tidak Berarah (Undirected Graph):\n\n");
    for(int i = 1; i <= baris; i++)
    {
        for(int j = 1; j <= baris; j++)
        {
            if(a[i][j] == 1)
                printf("1 ");
            else
                printf("0 ");
        }
        printf("\n");
    }

    int terhubung = 1; 
    for(int i = 1; i <= baris; i++) 
    {
        for(int j = 1; j <= baris; j++) 
        {
            if (a[i][j] == 0 && i != j) // Periksa koneksi antara dua vertex
            {
                terhubung = 0; 
                printf("\nVertex %d tidak terhubung dengan vertex %d.", i, j);
            }
        }
    }

    if (terhubung) 
    {
        printf("\nSemua vertex terhubung.\n");
    } 
    else 
    {
        printf("\nTidak semua vertex terhubung.\n");
    }

    return 0;
}