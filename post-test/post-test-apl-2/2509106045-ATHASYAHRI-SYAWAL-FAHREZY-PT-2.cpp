#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct WaktuDetail // nested struct nya
{
    string jamTidur;
    string jamBangun;
};

struct SleepTracker
{
    WaktuDetail waktu; // dimasukkan kesini
    int rating;
    string gangguan;
    float durasi;
    string status;
};

struct User
{
    string username;
    string password;
};

int main()
{
    User listUser[50]; // batasin user
    int jumlahUser = 0;

    SleepTracker riwayat[100]; // batasin riwayat
    int jumlahData = 0;

    int pilihanAwal, pilihanMenu;
    bool sedangLogin = false;
    string userAktif = "";
    bool programJalan = true;

    while (programJalan)
    {
        if (!sedangLogin)
        {
            string inputMenuAwal;
            cout << "\n===============================" << endl;
            cout << "   SELAMAT DATANG DI SLEEPY    " << endl;
            cout << "===============================" << endl;
            cout << "1. Register (Daftar Akun)" << endl;
            cout << "2. Login" << endl;
            cout << "3. Keluar Program" << endl;
            cout << "Pilih: ";
            cin >> inputMenuAwal;

            if (inputMenuAwal == "1")
                pilihanAwal = 1;
            else if (inputMenuAwal == "2")
                pilihanAwal = 2;
            else if (inputMenuAwal == "3")
                pilihanAwal = 3;
            else
            {
                cout << "Input menu tidak valid. Pilih 1, 2, atau 3." << endl;
                continue;
            }

            switch (pilihanAwal)
            {
            case 1:
                // kasih batasan data user dan cek
                if (jumlahUser >= 50)
                {
                    cout << "Kapasitas user penuh!" << endl;
                    break;
                }
                // register
                cout << "\n--- REGISTER ---" << endl;
                cout << "Masukkan Username Baru: ";
                cin >> listUser[jumlahUser].username;
                cout << "Masukkan Password Baru: ";
                cin >> listUser[jumlahUser].password;
                jumlahUser++;
                cout << "Registrasi Berhasil! Silahkan Login." << endl;
                break;

            case 2:
            {
                // loginnya
                string logUser, logPass;
                int percobaan = 0;
                bool ditemukan = false;

                while (percobaan < 3)
                {
                    cout << "\n--- LOGIN (Percobaan " << percobaan + 1 << "/3) ---" << endl;
                    cout << "Username: ";
                    cin >> logUser;
                    cout << "Password: ";
                    cin >> logPass;

                    ditemukan = false;
                    for (int i = 0; i < jumlahUser; i++)
                    {
                        if (listUser[i].username == logUser && listUser[i].password == logPass)
                        {
                            ditemukan = true;
                            userAktif = logUser;
                            break;
                        }
                    }

                    if (ditemukan)
                    {
                        sedangLogin = true;
                        cout << "Login Berhasil! Halo, " << userAktif << endl;
                        break;
                    }

                    percobaan++;
                    cout << "Username atau password salah!" << endl;
                }

                // gagal 3 kali mati programnya
                if (percobaan == 3)
                {
                    cout << "Gagal login 3 kali. Program berhenti." << endl;
                    programJalan = false;
                }
                break;
            }
            case 3:
                cout << "Program Berhenti. Sampai Jumpa!" << endl;
                programJalan = false;
                break;
            }
        }
        else
        {
            string inputMenuUtama;
            bool tampilTabel = false;
            bool inputData = false;
            bool modeUpdate = false;
            int indeksData = -1;

            cout << "\n=== APLIKASI SLEEP TRACKER (User: " << userAktif << ") ===" << endl;
            cout << "1. Tambah Catatan Tidur (Create)" << endl;
            cout << "2. Lihat Riwayat Tidur (Read - Tabel)" << endl;
            cout << "3. Ubah Catatan (Update)" << endl;
            cout << "4. Hapus Catatan (Delete)" << endl;
            cout << "5. Logout" << endl;
            cout << "Pilih: ";
            cin >> inputMenuUtama;

            if (inputMenuUtama == "1")
                pilihanMenu = 1;
            else if (inputMenuUtama == "2")
                pilihanMenu = 2;
            else if (inputMenuUtama == "3")
                pilihanMenu = 3;
            else if (inputMenuUtama == "4")
                pilihanMenu = 4;
            else if (inputMenuUtama == "5")
                pilihanMenu = 5;
            else
            {
                cout << "Input menu tidak valid. Pilih 1, 2, 3, 4, atau 5." << endl;
                continue;
            }

            switch (pilihanMenu)
            {
            // create
            case 1:
                if (jumlahData >= 100)
                {
                    cout << "Kapasitas data penuh!" << endl;
                    break;
                }
                cout << "\n--- Tambah Data ---" << endl;
                indeksData = jumlahData;
                inputData = true;
                break;

            // read
            case 2:
                tampilTabel = true;
                break;

            // update
            case 3:
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                    break;
                }
                cout << "\n--- Ubah Data ---" << endl;
                tampilTabel = true;
                modeUpdate = true;
                break;

            // delete
            case 4:
            {
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                    break;
                }

                int indeks;
                cout << "Masukkan Nomor Data yang ingin dihapus: ";
                cin >> indeks;
                modeUpdate = true;

                if (cin.fail())
                {
                    cin.clear();
                    cin.ignore(10000, '\n');
                    cout << "Nomor data harus angka." << endl;
                    break;
                }

                if (indeks > 0 && indeks <= jumlahData)
                {
                    for (int i = indeks - 1; i < jumlahData - 1; i++)
                    {
                        riwayat[i] = riwayat[i + 1];
                    }
                    jumlahData--;
                    cout << "Data Berhasil Dihapus!" << endl;
                }
                else
                {
                    cout << "Nomor tidak valid!" << endl;
                }
                break;
            }

            // logout
            case 5:
                sedangLogin = false;
                userAktif = "";
                cout << "Berhasil Logout." << endl;
                break;
            }

            if (tampilTabel)
            {
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                }
                else
                {
                    const int lebarTabel = 90;
                    // penerapan iomanip
                    cout << "\n"
                         << setfill('=') << setw(lebarTabel) << "" << endl;
                    cout << setfill(' ') << left << setw(5) << "NO"
                         << setw(18) << "WAKTU"
                         << setw(9) << "RATING"
                         << setw(15) << "DURASI(JAM)"
                         << setw(12) << "STATUS"
                         << "GANGGUAN" << endl;
                    cout << setfill('-') << setw(lebarTabel) << "" << endl;
                    cout << fixed << setprecision(1);

                    for (int i = 0; i < jumlahData; i++)
                    {
                        string rangeWaktu = riwayat[i].waktu.jamTidur + "-" + riwayat[i].waktu.jamBangun;
                        cout << setfill(' ') << left << setw(5) << i + 1
                             << setw(18) << rangeWaktu
                             << setw(9) << riwayat[i].rating
                             << setw(15) << riwayat[i].durasi
                             << setw(12) << riwayat[i].status
                             << riwayat[i].gangguan << endl;
                    }
                    cout << setfill('=') << setw(lebarTabel) << "" << endl;
                    cout << setfill(' ');
                }
            }

            if (modeUpdate)
            {
                int indeks;
                bool validNomor = false;

                while (!validNomor)
                {
                    cout << "Masukkan Nomor Data yang ingin diubah: ";
                    cin >> indeks;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Nomor harus angka." << endl;
                    }
                    else if (indeks < 1 || indeks > jumlahData)
                    {
                        cout << "Nomor tidak valid!" << endl;
                    }
                    else
                    {
                        validNomor = true;
                    }
                }

                indeksData = indeks - 1;
                inputData = true;
                cout << "Masukkan data pengganti:" << endl;
            }

            if (inputData)
            {
                for (int bagian = 0; bagian < 2; bagian++)
                {
                    bool validJam = false;
                    while (!validJam)
                    {
                        string jam;

                        if (bagian == 0)
                            cout << "Jam Tidur (HH:MM): ";
                        else
                            cout << "Jam Bangun (HH:MM): ";

                        cin >> jam;

                        bool adaHuruf = false;
                        for (size_t i = 0; i < jam.length(); i++)
                        {
                            if ((jam[i] >= 'a' && jam[i] <= 'z') || (jam[i] >= 'A' && jam[i] <= 'Z'))
                            {
                                adaHuruf = true;
                                break;
                            }
                        }

                        if (adaHuruf || jam.length() != 5 || jam[2] != ':')
                        {
                            cout << "Jam harus format 00:00 (contoh 22:30)." << endl;
                        }
                        else
                        {
                            validJam = true;
                            if (bagian == 0)
                                riwayat[indeksData].waktu.jamTidur = jam;
                            else
                                riwayat[indeksData].waktu.jamBangun = jam;
                        }
                    }
                }

                bool validRating = false;
                while (!validRating)
                {
                    cout << "Rating Kualitas (1-5): ";
                    cin >> riwayat[indeksData].rating;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Rating harus angka 1 sampai 5." << endl;
                    }
                    else if (riwayat[indeksData].rating < 1 || riwayat[indeksData].rating > 5)
                    {
                        cout << "Rating hanya boleh 1 sampai 5." << endl;
                    }
                    else
                    {
                        validRating = true;
                    }
                }

                cout << "Gangguan: ";
                cin.ignore(10000, '\n');
                getline(cin, riwayat[indeksData].gangguan);
                if (riwayat[indeksData].gangguan.empty())
                {
                    riwayat[indeksData].gangguan = "-";
                }

                bool validDurasi = false;
                while (!validDurasi)
                {
                    cout << "Total Durasi (Jam): ";
                    cin >> riwayat[indeksData].durasi;

                    if (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(10000, '\n');
                        cout << "Durasi harus angka jam (contoh: 7 atau 7.5)." << endl;
                    }
                    else if (riwayat[indeksData].durasi <= 0)
                    {
                        cout << "Durasi harus lebih dari 0 jam." << endl;
                    }
                    else
                    {
                        validDurasi = true;
                    }
                }

                cout << "Status Tidur (isi bebas): ";
                cin >> riwayat[indeksData].status;

                if (modeUpdate)
                {
                    cout << "Data Berhasil Diperbarui!" << endl;
                }
                else
                {
                    jumlahData++;
                    cout << "Data berhasil disimpan!" << endl;
                }
            }
        }
    }

    return 0;
}
