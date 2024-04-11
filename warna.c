#include <stdio.h>

int main() 
{
    printf("Coloring Graph using Welsh-Powell Algorithm.\n");
    printf("============================================\n\n");

    int matriks[15][15]; //matriks ketetanggaan
    int T[15] = {0, 0, 0, 0, 0, 0, 0}; //
    int degree[15][2] = {0}; //derajat
    int color[15] = {0}; //warna
    int kolom, baris, hitung, awal, akhir;

    printf("Input banyak vertex: ");
    scanf("%d", &baris);
    kolom = baris;

    for (int i = 1; i <= baris; i++) 
    {
        degree[i][0] = i; // vertex ke-i
        for (int j = 1; j <= baris; j++) 
        {
            if (i != j) 
            {
                printf("Jika vertex %d dan vertex %d berhubungan, ketik 1, jika tidak ketik 0: ", i, j);
                scanf("%d", &matriks[i][j]);
                if (matriks[i][j] == 1) 
                {
                    degree[i][1]++; // derajat vertex ke-i
                }
            } 
            else 
            {
                matriks[i][j] = 0;
            }
        }
    }

    printf("\nTampilkan graph dalam matriks ketetanggaan: \n\n");
    for (int i = 1; i <= baris; i++) 
    {
        for (int j = 1; j <= baris; j++) 
        {
            printf("%d", matriks[i][j]);
        }
        printf("\n");
    }

    /*
    printf("\nTampilkan derajat vertex: \n");
    for (int i = 1; i <= baris; i++) 
    {
        printf("Derajat vertex ke-%d adalah %d\n", i, d[i][1]);
    }
    */

    /* Mengurutkan derajat Bubble sort */
    int temp = 0;
    for (int i = 1; i <= baris; i ++) 
    {
        for (int j = i + 1; j <= baris; j++) 
        {
            if (degree[i][1] < degree[j][1]) 
            {
                temp = degree[i][1];
                degree[i][1] = degree[j][1];
                degree[j][1] = temp;
                temp = degree[i][0];
                degree[i][0] = degree[j][0];
                degree[j][0] = temp;
            }
        }
    }

    printf("\nTampilkan urutan vertex sesuai derajat terbesar: \n");
    for (int i = 1; i <= baris; i++) 
    {
        printf("Derajat vertex ke-%d adalah %d\n", degree[i][0], degree[i][1]);
    }

    /* Pewarnaan dengan mencari derajat terbesar yang masih belum memiliki warna */
    int warna = 1;
    color[degree[1][0]] = warna;
    int total = 1;

    for (int i = 1; i <= baris; i++) 
    {
        T[i] = matriks[degree[1][0]][i];
    }

    while (total < baris)
    {
        for(int i = 1; i <= baris; i++)
        {
            if((color[degree[i][0]] == 0) && (T[degree[i][0]] == 0))
            {
                color[degree[i][0]] = warna;
                total++;
                for(int j = 1; j <= baris; j++)
                {
                    if(T[j] == 0)
                    {
                        T[j] = T[j] + matriks[degree[i][0]][j];
                    }
                }
            }
        }
        warna++;
        for(int j = 1; j <= baris; j++)
        {
            T[j] = 0;
        }
    }
    printf("\n");

    printf("Hasil pewarnaan vertex dengan algoritma Welsh-Powell: \n");
    for (int i = 1; i <= baris; i++) 
    {
        printf("Warna vertex ke-%d adalah %d\n", i, color[i]);
    }
    printf("\n");

    printf("Total warna yang diperlukan untuk graph tersebut adalah %d warna.", warna - 1);

    return 0;
}