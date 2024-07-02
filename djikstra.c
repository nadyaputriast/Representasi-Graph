#include <stdio.h>
#include <stdlib.h>

int main() 
{
    printf("Algoritma Djikstra\n");
    printf("===================\n");

    int n, start;
    printf("Masukan Jumlah Vertex : ");
    scanf("%d", &n);
    int G[n][n], tempGraf[n][n], jarak[n], visit[n], temp[n], count;
    printf("Masukan Matrix Graf : \n");
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            scanf("%d", &G[i][j]);
        }
    }
    printf("Masukan Vertex Asal : ");
    scanf("%d", &start);

    int inf = 999; 

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (G[i][j] == 0) {
                tempGraf[i][j] = inf;
            } else {
                tempGraf[i][j] = G[i][j];
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        jarak[i] = tempGraf[start][i];
        temp[i] = start;
        visit[i] = 0;
    }
    jarak[start] = 0;
    visit[start] = 1;

    count = 1; 

    // proses untuk menghitung vertex yang dikunjungi
    int jarakmin, nextvertex;
    while (count < n - 1) {
        jarakmin = inf;
        for (int i = 1; i <= n; i++) {
            // jika jarak lebih kecil dari jarak minimum dan vertex belum dikunjungi
            // maka jarak minimum adalah jarak yang sudah dibandingkan sebelumnya dengan jarakmin
            if (jarak[i] < jarakmin && visit[i] != 1) {
                jarakmin = jarak[i];
                nextvertex = i; // untuk memberikan vertex pada jarak minimum
            }
        }

        visit[nextvertex] = 1;
        for (int i = 1; i <= n; i++) {
            if (visit[i] != 1) {
                if (jarakmin + tempGraf[nextvertex][i] < jarak[i]) {
                    jarak[i] = jarakmin + tempGraf[nextvertex][i];
                    temp[i] = nextvertex;
                }
            }
        }
        count++;
    }
    // menampilkan jalur dan jarak untuk setiap vertex
    for (int i = 1; i <=n; i++) {
        if (i != start) {
            printf("\nHasil jarak untuk vertex ke-%d adalah %d\n", i, jarak[i]);

            int j = i;
            printf("%d<-", i);
            while (j != start) {
                j = temp[j];
                printf("%d", j);
                if (j != start) {
                    printf("<-");
                }
            }
        }
    }
    printf("\nTotal Jaraknya adalah %d\n", jarak[n]);
    return 0;
}