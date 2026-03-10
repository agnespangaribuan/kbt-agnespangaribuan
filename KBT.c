#include <stdio.h> // Untuk input/output (printf, scanf, fgets)
#include <stdlib.h> // Untuk utilitas umum (exit)
#include <string.h> // Untuk fungsi manipulasi string (strcpy)

// Definisi struktur untuk menyimpan data tiket
struct Ticket {
    int idTicket;
    char namaPenumpang[50];
    char jenisKendaraan[20];
    char destinasiTujuan[50];
    char jadwalKeberangkatan[10]; // Format HH.MM
    int hargaTiket;
};

// Data perjalanan yang tersedia (hardcoded)
// KBT EKONOMI
char ekonomi_tujuan1[] = "Sitoluama - Medan";
char ekonomi_jadwal1[] = "08.00";
int ekonomi_harga1 = 90000;

char ekonomi_tujuan2[] = "Sitoluama - Siantar";
char ekonomi_jadwal2[] = "14.00";
int ekonomi_harga2 = 50000;

char ekonomi_tujuan3[] = "Sitoluama - Parapat";
char ekonomi_jadwal3[] = "10.00";
int ekonomi_harga3 = 30000;

// KBT EKSEKUTIF
char eksekutif_tujuan1[] = "Sitoluama - Medan";
char eksekutif_jadwal1[] = "09.00";
int eksekutif_harga1 = 120000;

char eksekutif_tujuan2[] = "Sitoluama - Siantar";
char eksekutif_jadwal2[] = "10.00";
int eksekutif_harga2 = 80000;

char eksekutif_tujuan3[] = "Sitoluama - Parapat";
char eksekutif_jadwal3[] = "11.00";
int eksekutif_harga3 = 50000;

int main() {
    // Array untuk menyimpan data tiket, maksimal 3
    struct Ticket daftarTiket[3];
    int jumlahTiketTerdaftar = 0; // Menghitung berapa banyak tiket yang sudah terdaftar
    int pilihan;

    do {
        printf("\n============================================\n");
        printf("  SISTEM TICKETING KOPERASI BINTANG TAPANULI\n");
        printf("============================================\n");
        printf("1. Tampilkan Daftar Perjalanan\n");
        printf("2. Input Data Pemesanan Tiket\n");
        printf("3. Tampilkan Data Tiket yang Dimasukkan\n");
        printf("4. Keluar\n");
        printf("--------------------------------------------\n");
        printf("Masukkan pilihan Anda: ");
        scanf("%d", &pilihan);

        // Membersihkan buffer input setelah scanf
        while (getchar() != '\n'); 

        switch (pilihan) {
            case 1:
                printf("\n============================================\n");
                printf("          DAFTAR PERJALANAN KBT\n");
                printf("============================================\n");
                printf("--------------------------------------------\n");
                printf("             KBT EKONOMI\n");
                printf("--------------------------------------------\n");
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", ekonomi_tujuan1, ekonomi_jadwal1, ekonomi_harga1);
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", ekonomi_tujuan2, ekonomi_jadwal2, ekonomi_harga2);
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", ekonomi_tujuan3, ekonomi_jadwal3, ekonomi_harga3);
                printf("--------------------------------------------\n");
                printf("             KBT EKSEKUTIF\n");
                printf("--------------------------------------------\n");
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", eksekutif_tujuan1, eksekutif_jadwal1, eksekutif_harga1);
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", eksekutif_tujuan2, eksekutif_jadwal2, eksekutif_harga2);
                printf("Tujuan: %-20s Jadwal: %-8s Harga: Rp%d\n", eksekutif_tujuan3, eksekutif_jadwal3, eksekutif_harga3);
                printf("============================================\n");
                break;

            case 2:
                if (jumlahTiketTerdaftar < 3) {
                    printf("\n============================================\n");
                    printf("        INPUT DATA PEMESANAN TIKET\n");
                    printf("============================================\n");
                    
                    printf("ID Tiket: ");
                    scanf("%d", &daftarTiket[jumlahTiketTerdaftar].idTicket);
                    while (getchar() != '\n'); // Membersihkan buffer

                    printf("Nama Penumpang: ");
                    fgets(daftarTiket[jumlahTiketTerdaftar].namaPenumpang, sizeof(daftarTiket[jumlahTiketTerdaftar].namaPenumpang), stdin);
                    daftarTiket[jumlahTiketTerdaftar].namaPenumpang[strcspn(daftarTiket[jumlahTiketTerdaftar].namaPenumpang, "\n")] = 0; // Hapus newline

                    printf("Jenis Kendaraan (EKONOMI/EKSEKUTIF): ");
                    fgets(daftarTiket[jumlahTiketTerdaftar].jenisKendaraan, sizeof(daftarTiket[jumlahTiketTerdaftar].jenisKendaraan), stdin);
                    daftarTiket[jumlahTiketTerdaftar].jenisKendaraan[strcspn(daftarTiket[jumlahTiketTerdaftar].jenisKendaraan, "\n")] = 0;

                    printf("Destinasi Tujuan (misal: Sitoluama - Medan): ");
                    fgets(daftarTiket[jumlahTiketTerdaftar].destinasiTujuan, sizeof(daftarTiket[jumlahTiketTerdaftar].destinasiTujuan), stdin);
                    daftarTiket[jumlahTiketTerdaftar].destinasiTujuan[strcspn(daftarTiket[jumlahTiketTerdaftar].destinasiTujuan, "\n")] = 0;

                    printf("Jadwal Keberangkatan (HH.MM): ");
                    fgets(daftarTiket[jumlahTiketTerdaftar].jadwalKeberangkatan, sizeof(daftarTiket[jumlahTiketTerdaftar].jadwalKeberangkatan), stdin);
                    daftarTiket[jumlahTiketTerdaftar].jadwalKeberangkatan[strcspn(daftarTiket[jumlahTiketTerdaftar].jadwalKeberangkatan, "\n")] = 0;

                    printf("Harga Tiket: Rp");
                    scanf("%d", &daftarTiket[jumlahTiketTerdaftar].hargaTiket);
                    while (getchar() != '\n'); // Membersihkan buffer
                    
                    jumlahTiketTerdaftar++;
                    printf("\nTiket berhasil ditambahkan!\n");
                } else {
                    printf("\nMaaf, kapasitas pemesanan sudah penuh (maksimal 3 tiket).\n");
                }
                break;

            case 3:
                printf("\n============================================\n");
                printf("          DATA TIKET TERDAFTAR\n");
                printf("============================================\n");
                if (jumlahTiketTerdaftar == 0) {
                    printf("Belum ada tiket yang terdaftar.\n");
                } else {
                    for (int i = 0; i < jumlahTiketTerdaftar; i++) {
                        printf("\n--- Tiket %d ---\n", i + 1);
                        printf("ID Tiket        : %d\n", daftarTiket[i].idTicket);
                        printf("Nama Penumpang  : %s\n", daftarTiket[i].namaPenumpang);
                        printf("Jenis Kendaraan : %s\n", daftarTiket[i].jenisKendaraan);
                        printf("Destinasi Tujuan: %s\n", daftarTiket[i].destinasiTujuan);
                        printf("Jadwal Berangkat: %s\n", daftarTiket[i].jadwalKeberangkatan);
                        printf("Harga Tiket     : Rp%d\n", daftarTiket[i].hargaTiket);
                    }
                }
                printf("============================================\n");
                break;

            case 4:
                printf("\nTerima kasih telah menggunakan Sistem Ticketing KBT. Sampai jumpa!\n");
                break;

            default:
                printf("\nPilihan tidak valid. Silakan coba lagi.\n");
                break;
        }
    } while (pilihan != 4);

    return 0;
}
