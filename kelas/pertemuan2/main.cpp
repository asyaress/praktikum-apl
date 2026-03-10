#include <iostream>
#include <string>

using namespace std;

// Contoh deklarasi
// int bilangan[5];
// string nama[4];
// float nilai[10];

// Deklarasi + Inisialisasi langsung

// struct Mahasiswa
// {
//     int nim;
//     string nama;
//     float nilai;
// };

struct date
{
    int month;
    int day;
    int year;
};

struct mahasiswa
{
    string name;
    struct date birthday;
};

int main()
{
    // int angka[3];

    // angka[0] = 10;
    // angka[1] = 19;
    // angka[2] = 30;

    // string buah[5] = {"Jeruk", "Mangga", "Nanas", "Apel"};
    // buah[4] = "Rambutan";

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << buah[i] << endl;
    // }

    // cout << buah[0] << endl;
    // cout << angka[2] << endl;
    // cout << endl;
    // // For each perulangan
    // for (string x : buah)
    // {
    //     cout << x << endl;
    // }

    // const int MAX_MAHASISWA = 100;
    // int panjang = 0;
    // int pilihan, index;
    // string namaBaru;
    // string mahasiswa[MAX_MAHASISWA];

    // do
    // {
    //     cout << "\n = MENU PROGRAM DATA MAHASISWA =" << endl;
    //     cout << "1. Tampilkan Mahasiswa" << endl;
    //     cout << "2. Tambah Mahasiswa" << endl;
    //     cout << "3. Ubah Mahasiswa" << endl;
    //     cout << "4. Hapus Mahasiswa" << endl;
    //     cout << "5. Keluar" << endl;
    //     cout << "Pilihan: ";
    //     cin >> pilihan;
    //     switch (pilihan)
    //     {
    //     case 1:
    //         if (panjang == 0)
    //         {
    //             cout << "Data mahasiswa masih kosong." << endl;
    //         }
    //         else
    //         {
    //             cout << "Daftar mahasiswa:" << endl;
    //             for (int i = 0; i < panjang; i++)
    //             {
    //                 cout << i + 1 << ". " << mahasiswa[i] << endl;
    //             }
    //         }
    //         break;
    //     case 2:
    //         if (panjang >= MAX_MAHASISWA)
    //         {
    //             cout << "Data penuh, tidak bisa menambah mahasiswa lagi." << endl;
    //         }
    //         else
    //         {
    //             cout << "Masukkan nama mahasiswa: ";
    //             cin >> ws;
    //             getline(cin, namaBaru);
    //             mahasiswa[panjang] = namaBaru;
    //             panjang++;
    //             cout << "Mahasiswa berhasil ditambahkan." << endl;
    //         }
    //         break;
    //     case 3:
    //         if (panjang == 0)
    //         {
    //             cout << "Data mahasiswa masih kosong." << endl;
    //             break;
    //         }

    //         cout << "Masukkan nomor mahasiswa yang ingin diubah (1-" << panjang << "): ";
    //         cin >> index;

    //         if (index < 1 || index > panjang)
    //         {
    //             cout << "Nomor tidak valid." << endl;
    //         }
    //         else
    //         {
    //             cout << "Masukkan nama baru: ";
    //             cin >> ws;
    //             getline(cin, namaBaru);
    //             mahasiswa[index - 1] = namaBaru;
    //             cout << "Data mahasiswa berhasil diubah." << endl;
    //         }
    //         break;
    //     case 4:
    //         if (panjang == 0)
    //         {
    //             cout << "Data mahasiswa masih kosong." << endl;
    //             break;
    //         }

    //         cout << "Masukkan nomor mahasiswa yang ingin dihapus (1-" << panjang << "): ";
    //         cin >> index;

    //         if (index < 1 || index > panjang)
    //         {
    //             cout << "Nomor tidak valid." << endl;
    //         }
    //         else
    //         {
    //             for (int i = index - 1; i < panjang - 1; i++)
    //             {
    //                 mahasiswa[i] = mahasiswa[i + 1];
    //             }
    //             panjang--;
    //             cout << "Data mahasiswa berhasil dihapus." << endl;
    //         }
    //         break;
    //     case 5:
    //         cout << "Program selesai." << endl;
    //         break;
    //     default:
    //         cout << "Pilihan tidak valid." << endl;
    //     }
    // } while (pilihan != 5);

    // int matriks[3][3] = {
    //     {1, 2, 3}, // Baris ke-0
    //     {4, 5, 6}, // Baris ke-1
    //     {7, 8, 9}  // Baris ke-2
    // };

    // // Mengakses elemen
    // cout << matriks[0][1] << endl; // 2
    // cout << matriks[2][0] << endl; // 7

    // // Menampilkan seluruh matriks dengan nested loop
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 3; j++)
    //     {
    //         cout << matriks[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // // Menampilkan dengan range-based for
    // for (auto &baris : matriks)
    // {
    //     for (auto &elemen : baris)
    //     {
    //         cout << elemen << " ";
    //     }
    //     cout << endl;
    // }

    // int nilai[2][2][2] = {
    //     {{80, 85}, {75, 90}}, // Kelas A
    //     {{88, 92}, {70, 78}}  // Kelas B
    // };

    // cout << " = DATA NILAI MAHASISWA =\n\n";
    // for (int k = 0; k < 2; k++)
    // {
    //     cout << "Kelas " << char('A' + k) << endl;
    //     for (int m = 0; m < 2; m++)
    //     {
    //         cout << " Mahasiswa " << m + 1 << endl;
    //         cout << " UTS : " << nilai[k][m][0] << endl;
    //         cout << " UAS : " << nilai[k][m][1] << endl;
    //     }
    //     cout << endl;
    // }

    // Mahasiswa mhs;

    // // Mengisi field(assignment)
    // mhs.nim = 2501234;
    // mhs.nama = "Bintang";
    // mhs.nilai = 88.5;
    // // Membaca field(akses)
    // cout << "NIM : " << mhs.nim << endl;
    // cout << "Nama : " << mhs.nama << endl;
    // cout << "Nilai : " << mhs.nilai << endl;

    struct mahasiswa mhs[10];

    mhs[0].name = "Ihsan";
    mhs[0].birthday.day = 30;
    mhs[0].birthday.month = 1;
    mhs[0].birthday.year = 2007;
    return 0;
}