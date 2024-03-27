#include <stdio.h>

void CountDegree1()
{
    int a[9][9];
    int baris;
    
    printf("Input banyak vertex: ");
    scanf("%d", &baris);
    
    for(int i = 1; i <= baris; i++)
    {
        for(int j = 1; j <= baris; j++)
        {
            printf("Jika vertex %d dan vertex %d terhubung, tulis 1, jika tidak tulis 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    
    printf("\nDerajat dari setiap vertex: \n");
    for(int i = 1; i <= baris; i++)
    {
        int derajat = 0;
        for(int j = 1; j <= baris; j++)
        {
            derajat += a[i][j];
        }
        printf("d(%d): %d\n", i, derajat);
    }
}

void CountDegree2()
{    
    int x;
    printf("Input banyaknya titik: ");
    scanf("%d", &x);
    
    int a[x][x];
    printf("\nTulis matriks ketetanggaan dari graph yang ingin dihitung derajatnya: \n");

    for(int i = 1; i <= x; i++)
    {
        for(int j = 1; j <= x; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nDerajat dari setiap vertex: \n");
    for(int i = 1; i <= x; i++)
    {
        int derajat = 0;
        for(int j = 1; j <= x; j++)
        {
            derajat += a[i][j];
        }
        printf("d(%d): %d\n", i, derajat);
    }
}

void CheckingGraph()
{
    int banyak;
    printf("Berapa banyak simpul yang ingin dicek? ");
    scanf("%d", &banyak);
    
    int totalVertex = 0;
    printf("Masukkan simpul-simpulnya: \n");
    for(int i = 0; i < banyak; i++)
    {
        int vertex;
        scanf("%d", &vertex);
        totalVertex += vertex;
    }
    
    if(totalVertex % 2 == 0)
    {
        printf("Graph dapat dibuat dari simpul-simpul tersebut.");
    }
    else
    {
        printf("Graph tidak dapat dibuat dari simpul-simpul tersebut.");
    }
}

int main() 
{
    int x;
    printf("Program Menghitung Derajat Vertex.\nMatematika Diskrit II\n\n");

    printf("Pilih progam mana yang ingin dijalankan (cukup ketik angkanya saja).\n");
    printf("(1) Menghitung derajat vertex jika diketahui setiap titik apakah terhubung atau tidak.\n");
    printf("(2) Menghitung derajat vertex jika diketahui matriks ketetanggaannya.\n");
    printf("(3) Mengecek apakah graf dapat dibuat jika diketahui tiap titiknya berhubungan atau tidak.\n\n");
    
    scanf("%d", &x);
    
    if(x == 1)
    {
        CountDegree1();
    }
    else if(x == 2)
    {
        CountDegree2();
    }
    else
    {
        CheckingGraph();
    }
    
    return 0;
}