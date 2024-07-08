/*! \mainpage Sistem Manajemen Nilai Akhir Mata Kuliah
*
* \section intro_sec Pengantar
* Selamat Datang di Nilai Akhir Mata Kuliah
* Sistem ini dirancang untuk mengelola informasi nilai
*
* \section setup_ Struktur Kode
* Terdiri dari 3 kelas:
* - \b MataKuliah: berisi presensi, activity, exercise, dan tugas akhir. 
* - \b Pemrograman: berisi rekap nilai mata kuliah pemrograman
* - \b Jaringan: berisi rekap nilai mata kuliah jaringan
*
* \section setup_sec Setup dan Konfigurasi
* Untuk menjalankan sistem ini, diperlukan compiler yang mendukung standar C++11 atau lebih tinggi.
* Kompilasi dan jalankan file ini menggunakan compiler pilihan anda....
*
*\section author_sec Tentang Pengembang
* Sistem ini dikembangkan oleh M.Irfan Fauzi
*/

#include <iostream> 
using namespace std; 
/**
 * @class MataKuliah
 * @brief Kelas yang merepresentasikan sebuah matakuliah.
 */
class MataKuliah 
{ 
private: // isi dengan access modifier yang dibutuhkan 
 
    float presensi, activity, exercise, tugas_akhir,rerata;
    string status;
    
    // tambahkan dengan variabel lain yang dibutuhkan dibawah ini 
 
public: 
MataKuliah() 
{ 
    
    presensi = 0.0; 
    activity = 0.0;
    exercise = 0.0;
    tugas_akhir = 0.0;
    status = " ";
    rerata = 0.0;
    // isi dengan inisialisasi variabel yang dibutuhkan dibawah ini 
} 
virtual void namaMataKuliah() {return; }
virtual void cekKelulusan();
virtual void inputNilai();
virtual void hitungNilaiAkhir();  
// tambahkan virtual fungsi lain yang dibutuhkan dibawah ini 
 
void setPresensi(float nilai) 
{ 
    this->presensi = nilai; 
} 
float getPresensi() 
{ 
    return presensi; 
} 
 
// tambahkan setter dan getter lain yang dibutuhkan dibawah ini 
}; 
 
 /**
 * @class Pemrograman
 * @brief Kelas yang merepresentasikan sebuah pemrograman.
 */
class Pemrograman : public MataKuliah 
{ 
    // isi disini untuk mengisi kelas pemrograman 
    public:

    float presensi, activity, exercise, tugas_akhir,rerata;
    string status;

    void inputNilai() override{
    
    
    cout << "Masukan nilai presensi: ";
    cin >> presensi;

    cout << "Masukan nilai activity: ";
    cin >> activity;

     cout << "Masukan nilai exercise: ";
    cin >> exercise;

    cout << "Masukan nilai tugas akhir: ";
    cin >> tugas_akhir;
    }

    void hitungNilaiAkhir()override{
    rerata = (presensi+activity+exercise+tugas_akhir) / 4.0;
    }

    void cekKelulusan() override{
    if (rerata >= 75) {
        status = "Selamat anda dintakan Lulus";
    }
    else {
        status = "Anda dinyatakan Tidak Lulus ";
    }

    cout << "Status kelulusan: " << status << endl;
    }
}; 
 
 /**
 * @class Jaringan
 * @brief Kelas yang merepresentasikan sebuah jaringan.
 */
class Jaringan : public MataKuliah 
{ 
    // isi disini untuk mengisi kelas jaringan 
    public:

    float presensi, activity, exercise, tugas_akhir,rerata;
    string status;

    void inputNilai() override{
    

    cout << "Masukan nilai presensi: ";
    cin >> presensi;

    cout << "Masukan nilai activity: ";
    cin >> activity;

     cout << "Masukan nilai exercise: ";
    cin >> exercise;

    cout << "Masukan nilai tugas akhir: ";
    cin >> tugas_akhir;
    }

    void hitungNilaiAkhir() override{
    rerata = (presensi+activity+exercise+tugas_akhir) / 4.0;
    }

    void cekKelulusan() override{
    if (rerata >= 75) {
        status = "Selamat anda dintakan Lulus";
    }
    else {
        status = "Anda dinyatakan Tidak Lulus ";
    }

    cout << "Status kelulusan: " << status << endl;
    }
}; 
 
int main() 
{ 
    char pilih; 
    MataKuliah *mataKuliah; 
    Pemrograman pemrograman; 
    Jaringan jaringan; 
 
    // isi disini untuk menentukan mata kuliah yang dipilih 

    do{
        cout << "\nPilih Mata Kuliah:\n";
        cout << "1. Pemrograman\n";
        cout << "2. Jaringan\n";
        cout << "3. Exit\n";
        cout << "Pilih: ";

        cin >> pilih;

    switch (pilih) {
    case 1:
        mataKuliah = new Pemrograman();
        mataKuliah->inputNilai();
        mataKuliah->hitungNilaiAkhir();
        mataKuliah->cekKelulusan();
        break;
    case 2:
        mataKuliah = new Jaringan();
        mataKuliah->inputNilai();
        mataKuliah->hitungNilaiAkhir();
        mataKuliah->cekKelulusan();
        break;
    case 3:
        cout << "Exiting..." << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
    
} while (pilih != 3);

return 0;
    
} 