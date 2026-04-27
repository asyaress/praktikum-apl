#include <iostream>
#include <string>
#include <iomanip>
#include <stdexcept>

using namespace std;

struct WaktuDetail
{
    string jamTidur;
    string jamBangun;
};

struct SleepTracker
{
    WaktuDetail waktu;
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

void tampilMenuAwal(const string &judul)
{
    cout << "\n===============================" << endl;
    cout << "   " << judul << endl;
    cout << "===============================" << endl;
    cout << "1. Register (Daftar Akun)" << endl;
    cout << "2. Login" << endl;
    cout << "3. Keluar Program" << endl;
}

void tampilMenuUtama(const string &userAktif)
{
    cout << "\n=== APLIKASI SLEEP TRACKER (User: " << userAktif << ") ===" << endl;
    cout << "1. Tambah Catatan Tidur (Create)" << endl;
    cout << "2. Lihat Riwayat Tidur (Read)" << endl;
    cout << "3. Ubah Catatan (Update)" << endl;
    cout << "4. Hapus Catatan (Delete)" << endl;
    cout << "5. Sorting Huruf Ascending (Gangguan A-Z) [Bubble Sort]" << endl;           // sorting huruf ascending pakai bubble sort
    cout << "6. Sorting Angka Descending (Durasi besar-kecil) [Selection Sort]" << endl; // sorting angka descending pakai selection sort
    cout << "7. Sorting Bebas (Jam Tidur awal-akhir) [Insertion Sort]" << endl;          // sorting angka jam tidur ascending pakai insertion
    cout << "8. Searching Data" << endl;
    cout << "9. Logout" << endl;
}

int bacaPilihanMenu(int minPilihan, int maxPilihan)
{
    while (true)
    {
        try
        {
            int pilihan;
            cout << "Pilih: ";
            cin >> pilihan;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Input harus angka.");
            }

            if (pilihan < minPilihan || pilihan > maxPilihan)
            {
                throw out_of_range("Pilihan tidak tersedia.");
            }

            return pilihan;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }
}

void registerUser(User listUser[], int &jumlahUser, int maxUser)
{
    if (jumlahUser >= maxUser)
    {
        cout << "Kapasitas user penuh!" << endl;
        return;
    }

    cout << "\n--- REGISTER ---" << endl;
    cout << "Masukkan Username Baru: ";
    cin >> listUser[jumlahUser].username;
    cout << "Masukkan Password Baru: ";
    cin >> listUser[jumlahUser].password;
    jumlahUser++;
    cout << "Registrasi Berhasil! Silahkan Login." << endl;
}

bool loginUser(const User listUser[], int jumlahUser, string &userAktif)
{
    string username;
    string password;
    int percobaan = 0;

    while (percobaan < 3)
    {
        cout << "\n--- LOGIN (Percobaan " << percobaan + 1 << "/3) ---" << endl;
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;

        for (int i = 0; i < jumlahUser; i++)
        {
            if (listUser[i].username == username && listUser[i].password == password)
            {
                userAktif = username;
                cout << "Login Berhasil! Halo, " << userAktif << endl;
                return true;
            }
        }

        percobaan++;
        cout << "Username atau password salah!" << endl;
    }

    return false;
}

bool validJam(const string &jam)
{
    if (jam.length() != 5 || jam[2] != ':')
    {
        return false;
    }

    if (jam[0] < '0' || jam[0] > '9' || jam[1] < '0' || jam[1] > '9')
    {
        return false;
    }

    if (jam[3] < '0' || jam[3] > '9' || jam[4] < '0' || jam[4] > '9')
    {
        return false;
    }

    int nilaiJam = (jam[0] - '0') * 10 + (jam[1] - '0');
    int nilaiMenit = (jam[3] - '0') * 10 + (jam[4] - '0');

    if (nilaiJam < 0 || nilaiJam > 23)
    {
        return false;
    }

    if (nilaiMenit < 0 || nilaiMenit > 59)
    {
        return false;
    }

    return true;
}

bool validJam(const string &jam, string &pesanError)
{
    if (!validJam(jam))
    {
        pesanError = "Format jam salah. Gunakan HH:MM (contoh 22:30).";
        return false;
    }

    pesanError = "";
    return true;
}

// Pointer Dereference (*) tujunanya agar rating itu selalu angka 1-5
void normalisasiRatingPointer(int *rating)
{
    if (*rating < 1)
    {
        *rating = 1;
    }
    else if (*rating > 5)
    {
        *rating = 5;
    }
}

// mengklasifikasikan status tidur dengan pointer
void evaluasiStatusReferensi(SleepTracker &data)
{
    if (data.durasi >= 7.0f && data.rating >= 4)
    {
        data.status = "Bugar";
    }
    else if (data.durasi >= 6.0f && data.rating >= 3)
    {
        data.status = "Cukup";
    }
    else
    {
        data.status = "Kurang";
    }
}

// dipakai untuk mengisi dan memvalidasi data tidur langsung ke objek SleepTracker asli lewat pointer (->)
void inputDataTidur(SleepTracker *data)
{
    string pesanError;

    while (true)
    {
        try
        {
            cout << "Jam Tidur (HH:MM): ";
            cin >> data->waktu.jamTidur;

            if (!validJam(data->waktu.jamTidur, pesanError))
            {
                throw invalid_argument(pesanError);
            }

            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    while (true)
    {
        try
        {
            cout << "Jam Bangun (HH:MM): ";
            cin >> data->waktu.jamBangun;

            if (!validJam(data->waktu.jamBangun, pesanError))
            {
                throw invalid_argument(pesanError);
            }

            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    while (true)
    {
        try
        {
            cout << "Rating Kualitas (1-5): ";
            cin >> data->rating;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Rating harus angka 1 sampai 5.");
            }

            if (data->rating < 1 || data->rating > 5)
            {
                throw out_of_range("Rating hanya boleh 1 sampai 5.");
            }

            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    normalisasiRatingPointer(&data->rating);

    cout << "Gangguan: ";
    cin.ignore(10000, '\n');
    getline(cin, data->gangguan);
    if (data->gangguan.empty())
    {
        data->gangguan = "-";
    }

    while (true)
    {
        try
        {
            cout << "Total Durasi (Jam): ";
            cin >> data->durasi;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Durasi harus angka (contoh: 7 atau 7.5).");
            }

            if (data->durasi <= 0)
            {
                throw out_of_range("Durasi harus lebih dari 0.");
            }

            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    evaluasiStatusReferensi(*data);
    cout << "Status Tidur Otomatis: " << data->status << endl;
}

void tampilBarisDataRekursif(const SleepTracker riwayat[], int index, int jumlahData)
{
    if (index >= jumlahData)
    {
        return;
    }

    string rangeWaktu = riwayat[index].waktu.jamTidur + "-" + riwayat[index].waktu.jamBangun;
    cout << setfill(' ') << left << setw(5) << index + 1
         << setw(18) << rangeWaktu
         << setw(9) << riwayat[index].rating
         << setw(15) << riwayat[index].durasi
         << setw(12) << riwayat[index].status
         << riwayat[index].gangguan << endl;

    tampilBarisDataRekursif(riwayat, index + 1, jumlahData);
}

void tampilTabelData(const SleepTracker riwayat[], int jumlahData)
{
    if (jumlahData == 0)
    {
        cout << "\nData masih kosong!" << endl;
        return;
    }

    const int lebarTabel = 90;
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

    tampilBarisDataRekursif(riwayat, 0, jumlahData);

    cout << setfill('=') << setw(lebarTabel) << "" << endl;
    cout << setfill(' ');
}

int pilihIndexData(int jumlahData, const string &pesanInput)
{
    while (true)
    {
        try
        {
            int nomor;
            cout << pesanInput;
            cin >> nomor;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Nomor harus angka.");
            }

            if (nomor < 1 || nomor > jumlahData)
            {
                throw out_of_range("Nomor tidak valid.");
            }

            return nomor - 1;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }
}

void tambahData(SleepTracker riwayat[], int &jumlahData, int maxData)
{
    if (jumlahData >= maxData)
    {
        cout << "Kapasitas data penuh!" << endl;
        return;
    }

    cout << "\n--- Tambah Data ---" << endl;
    inputDataTidur(&riwayat[jumlahData]);
    jumlahData++;
    cout << "Data berhasil disimpan!" << endl;
}

void ubahData(SleepTracker riwayat[], int jumlahData)
{
    if (jumlahData == 0)
    {
        cout << "\nData masih kosong!" << endl;
        return;
    }

    cout << "\n--- Ubah Data ---" << endl;
    tampilTabelData(riwayat, jumlahData);
    int index = pilihIndexData(jumlahData, "Masukkan nomor data yang ingin diubah: ");
    cout << "Masukkan data pengganti:" << endl;
    inputDataTidur(&riwayat[index]);
    cout << "Data berhasil diubah!" << endl;
}

void hapusData(SleepTracker riwayat[], int &jumlahData)
{
    if (jumlahData == 0)
    {
        cout << "\nData masih kosong!" << endl;
        return;
    }

    int index = pilihIndexData(jumlahData, "Masukkan nomor data yang ingin dihapus: ");

    for (int i = index; i < jumlahData - 1; i++)
    {
        riwayat[i] = riwayat[i + 1];
    }

    jumlahData--;
    cout << "Data berhasil dihapus!" << endl;
}

void tukarData(SleepTracker &a, SleepTracker &b)
{
    SleepTracker temp = a;
    a = b;
    b = temp;
}

// bubble sort sorting huruf secara ascending
void sortGangguanAscendingBubble(SleepTracker riwayat[], int jumlahData)
{
    for (int i = 0; i < jumlahData - 1; i++)
    {
        for (int j = 0; j < jumlahData - i - 1; j++)
        {
            if (riwayat[j].gangguan > riwayat[j + 1].gangguan)
            {
                tukarData(riwayat[j], riwayat[j + 1]);
            }
        }
    }
}

// selection sort sorting angka secara descending
void sortDurasiDescendingSelection(SleepTracker riwayat[], int jumlahData)
{
    for (int i = 0; i < jumlahData - 1; i++)
    {
        int indexMaks = i;

        for (int j = i + 1; j < jumlahData; j++)
        {
            if (riwayat[j].durasi > riwayat[indexMaks].durasi)
            {
                indexMaks = j;
            }
        }

        if (indexMaks != i)
        {
            tukarData(riwayat[i], riwayat[indexMaks]);
        }
    }
}

// insertion sort sorting angka ascending
void sortJamTidurAscendingInsertion(SleepTracker riwayat[], int jumlahData)
{
    for (int i = 1; i < jumlahData; i++)
    {
        SleepTracker kunci = riwayat[i];
        int j = i - 1;

        while (j >= 0 && riwayat[j].waktu.jamTidur > kunci.waktu.jamTidur)
        {
            riwayat[j + 1] = riwayat[j];
            j--;
        }

        riwayat[j + 1] = kunci;
    }
}

void tampilDataSingkat(const SleepTracker &data, int nomorData)
{
    cout << "Data ke-" << nomorData
         << " | Waktu: " << data.waktu.jamTidur << "-" << data.waktu.jamBangun
         << " | Rating: " << data.rating
         << " | Durasi: " << fixed << setprecision(1) << data.durasi
         << " | Status: " << data.status
         << " | Gangguan: " << data.gangguan << endl;
}

// sequential search untuk angka (rating)
int cariRatingSequential(const SleepTracker *riwayat, int jumlahData, int targetRating, int *hasilIndex, int maxHasil)
{
    int jumlahHasil = 0;

    for (int i = 0; i < jumlahData; i++)
    {
        if ((riwayat + i)->rating == targetRating && jumlahHasil < maxHasil)
        {
            *(hasilIndex + jumlahHasil) = i;
            jumlahHasil++;
        }
    }

    return jumlahHasil;
}

// binary search untuk kata/huruf (gangguan) pada data yang sudah terurut
int cariGangguanBinary(const SleepTracker *riwayatUrut, int jumlahData, const string *targetGangguan)
{
    int kiri = 0;
    int kanan = jumlahData - 1;

    while (kiri <= kanan)
    {
        int tengah = (kiri + kanan) / 2;
        string nilaiTengah = (riwayatUrut + tengah)->gangguan;

        if (nilaiTengah == *targetGangguan)
        {
            return tengah;
        }
        else if (nilaiTengah < *targetGangguan)
        {
            kiri = tengah + 1;
        }
        else
        {
            kanan = tengah - 1;
        }
    }

    return -1;
}

void prosesCariRatingSequential(const SleepTracker riwayat[], int jumlahData, int maxData)
{
    int targetRating = 0;

    while (true)
    {
        try
        {
            cout << "Masukkan rating yang dicari (1-5): ";
            cin >> targetRating;

            if (cin.fail())
            {
                cin.clear();
                cin.ignore(10000, '\n');
                throw invalid_argument("Input rating harus angka.");
            }

            if (targetRating < 1 || targetRating > 5)
            {
                throw out_of_range("Rating hanya boleh 1 sampai 5.");
            }

            break;
        }
        catch (const exception &e)
        {
            cout << e.what() << endl;
        }
    }

    int *hasilIndex = new int[maxData];
    int jumlahHasil = cariRatingSequential(riwayat, jumlahData, targetRating, hasilIndex, maxData);

    if (jumlahHasil == 0)
    {
        cout << "Data dengan rating " << targetRating << " tidak ditemukan." << endl;
    }
    else
    {
        cout << "Ditemukan " << jumlahHasil << " data dengan rating " << targetRating << ":" << endl;
        for (int i = 0; i < jumlahHasil; i++)
        {
            int indexAsli = hasilIndex[i];
            tampilDataSingkat(riwayat[indexAsli], indexAsli + 1);
        }
    }

    delete[] hasilIndex;
}

void prosesCariGangguanBinary(const SleepTracker riwayat[], int jumlahData)
{
    string targetGangguan;
    cout << "Masukkan gangguan yang dicari (harus sama persis): ";
    cin.ignore(10000, '\n');
    getline(cin, targetGangguan);

    if (targetGangguan.empty())
    {
        targetGangguan = "-";
    }

    SleepTracker *dataUrut = new SleepTracker[jumlahData];
    for (int i = 0; i < jumlahData; i++)
    {
        dataUrut[i] = riwayat[i];
    }

    sortGangguanAscendingBubble(dataUrut, jumlahData);
    int indexKetemu = cariGangguanBinary(dataUrut, jumlahData, &targetGangguan);

    if (indexKetemu == -1)
    {
        cout << "Gangguan \"" << targetGangguan << "\" tidak ditemukan." << endl;
    }
    else
    {
        int kiri = indexKetemu;
        int kanan = indexKetemu;

        while (kiri > 0 && dataUrut[kiri - 1].gangguan == targetGangguan)
        {
            kiri--;
        }

        while (kanan < jumlahData - 1 && dataUrut[kanan + 1].gangguan == targetGangguan)
        {
            kanan++;
        }

        cout << "Gangguan \"" << targetGangguan << "\" ditemukan pada " << (kanan - kiri + 1) << " data:" << endl;
        for (int i = kiri; i <= kanan; i++)
        {
            tampilDataSingkat(dataUrut[i], i + 1);
        }
    }

    delete[] dataUrut;
}

void menuSearching(SleepTracker riwayat[], int jumlahData, int maxData)
{
    if (jumlahData == 0)
    {
        cout << "\nData masih kosong!" << endl;
        return;
    }

    cout << "\n--- MENU SEARCHING ---" << endl;
    cout << "1. Cari Angka (Rating) [Sequential Search]" << endl;
    cout << "2. Cari Kata (Gangguan) [Binary Search]" << endl;
    cout << "3. Kembali ke Menu Utama" << endl;
    int pilihanSearch = bacaPilihanMenu(1, 3);

    if (pilihanSearch == 1)
    {
        prosesCariRatingSequential(riwayat, jumlahData, maxData);
    }
    else if (pilihanSearch == 2)
    {
        prosesCariGangguanBinary(riwayat, jumlahData);
    }
}

int main()
{
    const int MAX_USER = 50;
    const int MAX_DATA = 100;

    User listUser[MAX_USER];
    int jumlahUser = 0;

    SleepTracker riwayat[MAX_DATA];
    int jumlahData = 0;

    bool sedangLogin = false;
    bool programJalan = true;
    string userAktif = "";

    while (programJalan)
    {
        if (!sedangLogin)
        {
            tampilMenuAwal("SELAMAT DATANG DI SLEEPY");
            int pilihanAwal = bacaPilihanMenu(1, 3);

            if (pilihanAwal == 1)
            {
                registerUser(listUser, jumlahUser, MAX_USER);
            }
            else if (pilihanAwal == 2)
            {
                if (loginUser(listUser, jumlahUser, userAktif))
                {
                    sedangLogin = true;
                }
                else
                {
                    cout << "Gagal login 3 kali. Program berhenti." << endl;
                    programJalan = false;
                }
            }
            else
            {
                cout << "Program berhenti. Sampai jumpa!" << endl;
                programJalan = false;
            }
        }
        else
        {
            tampilMenuUtama(userAktif);
            int pilihanMenu = bacaPilihanMenu(1, 9);

            if (pilihanMenu == 1)
            {
                tambahData(riwayat, jumlahData, MAX_DATA);
            }
            else if (pilihanMenu == 2)
            {
                tampilTabelData(riwayat, jumlahData);
            }
            else if (pilihanMenu == 3)
            {
                ubahData(riwayat, jumlahData);
            }
            else if (pilihanMenu == 4)
            {
                hapusData(riwayat, jumlahData);
            }
            else if (pilihanMenu == 5)
            {
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                }
                else
                {
                    sortGangguanAscendingBubble(riwayat, jumlahData);
                    cout << "Data berhasil diurutkan berdasarkan gangguan (A-Z)." << endl;
                    tampilTabelData(riwayat, jumlahData);
                }
            }
            else if (pilihanMenu == 6)
            {
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                }
                else
                {
                    sortDurasiDescendingSelection(riwayat, jumlahData);
                    cout << "Data berhasil diurutkan berdasarkan durasi (besar-ke-kecil)." << endl;
                    tampilTabelData(riwayat, jumlahData);
                }
            }
            else if (pilihanMenu == 7)
            {
                if (jumlahData == 0)
                {
                    cout << "\nData masih kosong!" << endl;
                }
                else
                {
                    sortJamTidurAscendingInsertion(riwayat, jumlahData);
                    cout << "Data berhasil diurutkan berdasarkan jam tidur (awal-ke-akhir)." << endl;
                    tampilTabelData(riwayat, jumlahData);
                }
            }
            else if (pilihanMenu == 8)
            {
                menuSearching(riwayat, jumlahData, MAX_DATA);
            }
            else
            {
                sedangLogin = false;
                userAktif = "";
                cout << "Berhasil logout." << endl;
            }
        }
    }

    return 0;
}
