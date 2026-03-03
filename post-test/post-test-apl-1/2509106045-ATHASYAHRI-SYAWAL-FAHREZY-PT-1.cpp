#include <iostream>
#include <string>

using namespace std;

int main()
{
    string namaInput, passwordInput;
    string namaBenar = "pares";
    string passwordBenar = "045";
    int percobaan = 0;
    bool loginBerhasil = false;

    while (percobaan < 3)
    {
        cout << "=== LOGIN ===" << endl;
        cout << "Masukkan nama    : ";
        cin >> namaInput;
        cout << "Masukkan password: ";
        cin >> passwordInput;

        if (namaInput == namaBenar && passwordInput == passwordBenar)
        {
            loginBerhasil = true;
            cout << "Login berhasil. Halo, " << namaInput << "!"
                 << endl;
            break;
        }
        else
        {
            percobaan++;
            cout << "Nama atau password salah. Percobaan " << percobaan << " dari 3."
                 << endl;
        }
    }

    if (!loginBerhasil)
    {
        cout << "Kamu wess salah 3 kali. Program dihentikan." << endl;
        return 0;
    }

    int pilihan;
    double nilaiPanjang;

    do
    {
        cout << "--- MENU KONVERSI PANJANG ---" << endl;
        cout << "1. Meter ke kilometer dan centimeter" << endl;
        cout << "2. Kilometer ke meter dan centimeter" << endl;
        cout << "3. Centimeter ke meter dan kilometer" << endl;
        cout << "4. Cabut" << endl;
        cout << "Pilih menu (1-4): ";
        cin >> pilihan;

        if (pilihan == 1)
        {
            cout << "Masukkan nilai meter: ";
            cin >> nilaiPanjang;
            double keKilometer = nilaiPanjang / 1000;
            double keCentimeter = nilaiPanjang * 100;
            cout << "Hasilnya: " << keKilometer << " km dan " << keCentimeter << " cm" << endl;
        }
        else if (pilihan == 2)
        {
            cout << "Masukkan nilai kilometer: ";
            cin >> nilaiPanjang;
            double keMeter = nilaiPanjang * 1000;
            double keCentimeter = nilaiPanjang * 100000;
            cout << "Hasilnya: " << keMeter << " m dan " << keCentimeter << " cm" << endl;
        }
        else if (pilihan == 3)
        {
            cout << "Masukkan nilai centimeter: ";
            cin >> nilaiPanjang;
            double keMeter = nilaiPanjang / 100;
            double keKilometer = nilaiPanjang / 100000;
            cout << "Hasilnya: " << keMeter << " m dan " << keKilometer << " km" << endl;
        }
        else if (pilihan == 4)
        {
            cout << "Thenkss." << endl;
        }
        else
        {
            cout << "Pilihan gak ada bro, diliat makanya." << endl;
        }
        cout << endl;

    } while (pilihan != 4);

    return 0;
}