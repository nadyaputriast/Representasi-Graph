#include <stdio.h>

int main() {
    printf("Program Matriks Ketetanggaan (Adjacency Matrix).\n");

    int x[25][25]; 
    int kolom, baris; 

    printf("Masukkan banyaknya vertex (titik): ");
    scanf("%d", &baris);
    kolom = baris; 

    for(int a = 1; a <= baris; a++) {
        for(int b = 1; b <= kolom; b++) {
            if(a != b) {
                printf("Jika vertex %d dan vertex %d berhubungan, ketikkan angka 1 dan ketik angka 0 jika tidak: ", a, b);
                scanf("%d", &x[a][b]); 
            } else {
                x[a][b] = 0; 
            }
        }
    }

    printf("\nTampilan graph dalam matriks ketetanggaan adalah sebagai berikut:\n\n");
    for(int a = 1; a <= baris; a++) {
        for(int b = 1; b <= kolom; b++) {
            printf("%d ", x[a][b]);
        }
        printf("\n");
    }
    
// Proses penandaan komponen
    int component = 1;
    int marked[25] = {0}; 
    for(int i = 1; i <= baris; i++) {
        if(marked[i] == 0) {
            marked[i] = component; 
            for(int j = i + 1; j <= baris; j++) {
                if(x[i][j] == 1 && marked[j] == 0) {
                    marked[j] = component; 
                }
            }
            component++;
        }
    }

// Menampilkan graf dengan nomor komponen
    printf("\nTampilan graph dalam matriks ketetanggaan yang ditandai dengan nomor komponen terhubung sebagai berikut:\n\n");
    for(int a = 1; a <= baris; a++) {
        for(int b = 1; b <= kolom; b++) {
            if(x[a][b] == 1) {
                printf("%d ", marked[a]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }

// memeriksa apakah semua vertex dalam graf memiliki nomor komponen terhubung yang sama.
    int connected = 1; 
    for (int i = 1; i <= baris; i++) {
        for (int j = 1; j <= kolom; j++) {
            if (marked[i] != marked[j]) {
                connected = 0; 
                break;
            }
        }
        if (!connected) {
            break;
        }
    }

    if (connected) {
        printf("\nGraf adalah graf terhubung.\n");
    } else {
        printf("\nGraf adalah graf tidak terhubung.\n");
    }

    return 0;
}
