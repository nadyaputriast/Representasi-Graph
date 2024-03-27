#include <stdio.h>

// Fungsi untuk mencetak matriks insidensi ke layar
void cetakMatriksInsidensi(int matriksInsidensi[][100], int jumlahSimpul) {
    printf("Matriks Insidensi Graf:\n"); // Menampilkan pesan bahwa kita akan mencetak matriks insidensi
    for (int i = 0; i < jumlahSimpul; ++i) { // Melooping setiap baris dalam matriks insidensi
        for (int j = 0; j < jumlahSimpul; ++j) { // Melooping setiap nilai dalam baris
            printf("%d ", matriksInsidensi[i][j]); // Mencetak nilai
        }
        printf("\n"); // Mencetak baris baru setelah setiap baris matriks tercetak
    }
}

// Fungsi untuk menampilkan hubungan bersisian dari setiap edge yang ditambahkan
void cetakSemuaHubunganBersisian(int edgeList[][2], int jumlahEdge) {
    printf("Hubungan bersisian dari setiap edge:\n"); // Menampilkan pesan bahwa kita akan menampilkan hubungan bersisian
    for (int i = 0; i < jumlahEdge; ++i) { // Meloopi setiap edge dalam list edge
        printf("Sisi (%d, %d) bersisian dengan simpul %d dan simpul %d.\n", edgeList[i][0], edgeList[i][1], edgeList[i][0], edgeList[i][1]); // Menampilkan informasi hubungan bersisian untuk setiap edge
    }
}

int main() {
    int jumlahSimpul; // Jumlah simpul
    printf("Masukkan jumlah simpul: "); // Meminta pengguna untuk memasukkan jumlah simpul
    scanf("%d", &jumlahSimpul); // Membaca jumlah simpul yang dimasukkan pengguna

    int edgeList[100][2]; // Array untuk menyimpan setiap edge yang ditambahkan
    int jumlahEdge = 0; // Jumlah edge yang sudah ditambahkan

    // Inisialisasi matriks insidensi dengan ukuran jumlahSimpul x jumlahSimpul, awalnya diisi dengan 0
    int matriksInsidensi[100][100] = {0}; // Membuat matriks insidensi dengan ukuran maksimal 100x100 dan diisi dengan 0

    char pilihanTambahEdge;
    do {
        int simpulAsal, simpulTujuan;
        printf("Masukkan simpul asal dan simpul tujuan untuk tambahkan edge (misalnya: 1 2): "); // Meminta pengguna untuk memasukkan simpul asal dan tujuan untuk menambahkan edge
        scanf("%d %d", &simpulAsal, &simpulTujuan); // Membaca simpul asal dan tujuan yang dimasukkan pengguna

        // Pastikan simpul yang dimasukkan oleh pengguna valid
        if (simpulAsal >= 1 && simpulAsal <= jumlahSimpul && simpulTujuan >= 1 && simpulTujuan <= jumlahSimpul) { // Memeriksa apakah simpul yang dimasukkan valid
            // Tambahkan edge ke dalam array
            edgeList[jumlahEdge][0] = simpulAsal; // Menambahkan simpul asal ke dalam array edgeList
            edgeList[jumlahEdge][1] = simpulTujuan; // Menambahkan simpul tujuan ke dalam array edgeList
            jumlahEdge++; // Menaikkan jumlah edge yang sudah ditambahkan
        } else {
            printf("Simpul yang dimasukkan tidak valid.\n"); // Menampilkan pesan kesalahan jika simpul yang dimasukkan tidak valid
        }

        printf("Ingin menambahkan edge lain? (y/n): "); // Meminta pengguna apakah ingin menambahkan edge lain
        scanf(" %c", &pilihanTambahEdge); // Membaca pilihan pengguna
    } while (pilihanTambahEdge == 'y' || pilihanTambahEdge == 'Y'); // Melakukan loop jika pengguna ingin menambahkan edge lain

    // Mengisi matriks insidensi sesuai dengan edge yang ditambahkan
    for (int i = 0; i < jumlahEdge; ++i) { // Meloopi setiap edge dalam list edge
        int simpulAsal = edgeList[i][0]; // Mengambil simpul asal dari edge
        int simpulTujuan = edgeList[i][1]; // Mengambil simpul tujuan dari edge

        // Mengatur nilai 1 untuk simpulAsal -> simpulTujuan dan simpulTujuan -> simpulAsal
        matriksInsidensi[simpulAsal - 1][simpulTujuan - 1] = 1; // Mengatur nilai 1 untuk edge dari simpul asal ke tujuan
        matriksInsidensi[simpulTujuan - 1][simpulAsal - 1] = 1; // Mengatur nilai 1 untuk edge dari simpul tujuan ke asal (karena graf tak berarah)
    }

    // Tampilkan matriks insidensi yang telah dibuat
    cetakMatriksInsidensi(matriksInsidensi, jumlahSimpul); // Memanggil fungsi untuk mencetak matriks insidensi

    // Tampilkan hubungan bersisian dari setiap edge yang ditambahkan
    cetakSemuaHubunganBersisian(edgeList, jumlahEdge); // Memanggil fungsi untuk mencetak hubungan bersisian dari setiap edge

    return 0;
}
