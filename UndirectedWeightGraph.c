#include <stdio.h>

void countWeight()
{
    int a[9][9]; 
    int baris; 

    printf("Input banyak vertex: ");
    scanf("%d", &baris);

    for(int i = 1; i <= baris; i++)
    {
        for(int j = i; j <= baris; j++) 
        {
            if(i != j) 
            {
                printf("Masukkan bobot edge antara vertex %d dan %d: ", i, j);
                scanf("%d", &a[i][j]);
                a[j][i] = a[i][j];
            }
            else
            {
                a[i][j] = 0; 
            }
        }
    }

    printf("\nMatriks ketetanggaan untuk Graf Berbobot Tidak Berarah (Undirected Weighted Graph):\n\n");
    for(int i = 1; i <= baris; i++)
    {
        for(int j = 1; j <= baris; j++)
        {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }

    int totalBobot = 0;
    for(int i = 1; i <= baris; i++)
    {
        for(int j = 1; j <= baris; j++)
        {
            totalBobot += a[i][j];
        }
    }

    printf("\nTotal bobot dari semua sisi dalam graf adalah: %d\n", totalBobot);
}

void checkingGraph()
{
    int a[9][9];
    int baris;

    printf("Input banyak vertex: ");
    scanf("%d", &baris);

    for(int i = 1; i <= baris; i++) 
    {
        for(int j = i; j <= baris; j++) 
        {
            if(i != j) 
            {
                printf("Masukkan bobot edge antara vertex %d dan %d: ", i, j);
                scanf("%d", &a[i][j]);
                a[j][i] = a[i][j];
            }
            else 
            {
                a[i][j] = 0; 
            }
        }
    }

    printf("\nMatriks ketetanggaan untuk Graf Berbobot Tidak Berarah (Undirected Weighted Graph):\n\n");
    for(int i = 1; i <= baris; i++) 
    {
        for(int j = 1; j <= baris; j++) {
            printf("%-4d", a[i][j]);
        }
        printf("\n");
    }

    int terhubung = 1; 
    for(int i = 1; i <= baris; i++) 
    {
        for(int j = 1; j <= baris; j++) 
        {
            if (a[i][j] == 0 && i != j) 
            {
                terhubung = 0; 
                printf("\nVertex %d tidak terhubung dengan vertex %d\n", i, j);
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
}

int main()
{
    printf("Program Graf Berbobot Tidak Berarah (Undirected Weight Graph).\nMatematika Diskrit II\n\n");
    int x;
    printf("Pilih progam mana yang ingin dijalankan (cukup ketik angkanya saja).\n");
    printf("(1) Menghitung total bobot dari suatu graf.\n");
    printf("(2) Mengecek apakah setiap vertex terhubung dengan vertex lain dengan bobot.\n");
    scanf("%d", &x);
    printf("\n");
    
    if(x == 1)
    {
        countWeight();
    }
    else
    {
        checkingGraph();
    }
    
    return 0;
}