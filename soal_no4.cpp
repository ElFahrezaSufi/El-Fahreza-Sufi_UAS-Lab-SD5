#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Pelanggan {
    string nama;
    int berat;
    string jenis_layanan;
    int waktu_datang;
};

bool bandingkanPelanggan(const Pelanggan& a, const Pelanggan& b) {
    int prioritasA = (a.jenis_layanan == "express") ? 1 : 0;
    int prioritasB = (b.jenis_layanan == "express") ? 1 : 0;

    if (prioritasA != prioritasB) {
        return prioritasA > prioritasB;
    }

    return a.waktu_datang < b.waktu_datang;
}

int main() {
    int n;

    cout << "Masukkan jumlah pelanggan: ";
    cin >> n;

    vector<Pelanggan> daftar_pelanggan(n);

    for (int i = 0; i < n; ++i) {
        cout << "Data pelanggan ke-" << i + 1 << ":" << endl;
        cout << "  Nama: ";
        cin >> daftar_pelanggan[i].nama;
        cout << "  Berat (kg): ";
        cin >> daftar_pelanggan[i].berat;
        cout << "  Jenis Layanan (reguler/express): ";
        cin >> daftar_pelanggan[i].jenis_layanan;
        daftar_pelanggan[i].waktu_datang = i + 1;
    }

    sort(daftar_pelanggan.begin(), daftar_pelanggan.end(), bandingkanPelanggan);

    double total_waktu = 0;
    
    cout << "\nUrutan Pemrosesan:" << endl;

    for (const auto& p : daftar_pelanggan) {
        double waktu_proses_saat_ini;
        if (p.jenis_layanan == "express") {
            waktu_proses_saat_ini = p.berat * 5.0;
        } else {
            waktu_proses_saat_ini = p.berat * 10.0;
        }
        
        total_waktu += waktu_proses_saat_ini;
        
        cout << "- " << p.nama << " (Layanan: " << p.jenis_layanan 
             << ", Waktu Proses: " << fixed << setprecision(0) << waktu_proses_saat_ini << " menit)" << endl;
    }

    cout << "\nTotal waktu yang dibutuhkan untuk menyelesaikan semua cucian: " 
         << fixed << setprecision(0) << total_waktu << " menit" << endl;

    return 0;
}