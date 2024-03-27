#include <stdio.h>

int main() 
{
    printf("Program Matriks Ketetanggaan (Adjacency Matrix)\n\n");

    int x[25][25];
    int kolom, baris;
    printf("Masukkan banyaknya vertex: ");
    scanf("%d", &baris);
    kolom = baris;

    for(int a = 1; a <= baris; a++)
    {
        for(int b = 1; b <= kolom; b++)
        {
            if(a != b)
            {
                printf("Jika vertex %d dan vertex %d berhubungan, ketikkan angka 1 dan ketik angka 0 jika tidak: ", a, b);
                scanf("%d", &x[a][b]);
            }
            else
            {
                x[a][b] = 0;
            }
        }
    }

    printf("\nTampilan graph dalam matriks ketetanggannya adalah:\n");

    for(int a = 1; a <= baris; a++)
    {
        for(int b = 1; b <= kolom; b++)
        {
            printf("%d ", x[a][b]);
        }
        printf("\n");
    }

    return 0;
}
