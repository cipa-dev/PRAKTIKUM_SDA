#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};
void swapData(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
} 
void tampilData(Kereta *arr, int n) {
    cout << "\n--- JADWAL KERETA ---\n\n";
    cout << left << setw(10) << "nomor"
        << setw(15) << "nama"
        << setw(15) << "asal"
        << setw(15) << "tujuan"
        << setw(10) << "harga" << endl;
    cout << string(65, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << (arr + i)->nomor
            << setw(15) << (arr + i)->nama
            << setw(15) << (arr + i)->asal
            << setw(15) << (arr + i)->tujuan
            << setw(10) << (arr + i)->harga << endl;
    }
}
void tambahData(Kereta *arr, int &n) {
    cout << "\ntambah data kereta\n";
    cout << "nomor   : "; cin >> arr[n].nomor;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "nama    : "; getline(cin, arr[n].nama);
    cout << "asal    : "; getline(cin, arr[n].asal);
    cout << "tujuan  : "; getline(cin, arr[n].tujuan);
    cout << "harga   : "; cin >> arr[n].harga;
    n++; 
}
//harus diurutkan dulu biar jump search bisa jalan
void sortNomor(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr + i)->nomor > (arr + j)->nomor) {
                swapData(&arr[i], &arr[j]);
            }
        }
    }
}
void cariRute(Kereta *arr, int n) {
    string asal, tujuan;
    bool ketemu = false;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "masukkan asal   : ";
    getline(cin, asal);
    cout << "masukkan tujuan : ";
    getline(cin, tujuan);
    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }
    if (!ketemu) {
        cout << "data tidak ditemukan!\n";
    }
}
int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n); //besar langkah/loncatan
    int prev = 0;
    //proses loncat per blok sampai ketemu range yg mngkin ada datanya
    while ((arr + (step < n ? step : n) - 1)->nomor < key) {
        prev = step; //simpan posisi sebelumnya
        step += sqrt(n); //lompat lagi sejauh akar n
        //kalo uda lewat semua data
        if (prev >= n)
            return -1;
    }
    //kalo ketemu bloknya, dicek satu per satu (linear search)
    for (int i = prev; i < (step < n ? step : n); i++) {
        if ((arr + i)->nomor == key) {
            return i; //ketemu
        }
    }
    return -1; //ga ketemu
}
void sortHarga(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + minIndex)->harga) {
                minIndex = j;
            }
        }
        swapData(&arr[i], &arr[minIndex]);
    }
}
void merge(Kereta *arr, int l, int m, int r) {
    Kereta temp[100];
    int i = l, j = m + 1, k = 0;
    while (i <= m && j <= r) {
        if ((arr + i)->nama < (arr + j)->nama) {
            temp[k++] = *(arr + i++);
        } else {
            temp[k++] = *(arr + j++);
        }
    }
    while (i <= m) temp[k++] = *(arr + i++);
    while (j <= r) temp[k++] = *(arr + j++);
    for (int x = 0; x < k; x++) {
        *(arr + l + x) = temp[x];
    }
}
void mergeSort(Kereta *arr, int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}
int main() {
    Kereta data[100];
    int n = 3;
    data[0] = {101, "caca", "jakarta", "surabaya", 300000};
    data[1] = {102, "cibel", "yogyakarta", "jakarta", 250000};
    data[2] = {103, "kai", "malang", "jakarta", 200000};
    int pilih;
    do {
        cout << "\n--- MENU ---\n";
        cout << "1. tampil data\n";
        cout << "2. tambah data\n";
        cout << "3. cari rute\n";
        cout << "4. cari nomor\n";
        cout << "5. urut nama\n";
        cout << "6. urut harga\n";
        cout << "0. keluar\n";
        cout << "pilih: ";
        cin >> pilih;
        if (pilih == 1) {
            tampilData(data, n);
        }
        else if (pilih == 2) {
            tambahData(data, n);
        }
        else if (pilih == 3) {
            cariRute(data, n);
        }
        else if (pilih == 4) {
            int key;
            cout << "masukkan nomor: ";
            cin >> key;
            sortNomor(data, n);
            int hasil = jumpSearch(data, n, key);
            if (hasil != -1)
                cout << "ditemukan: " << data[hasil].nama << endl;
            else
                cout << "tidak ditemukan!\n";
        }
        else if (pilih == 5) {
            mergeSort(data, 0, n - 1);
            cout << "data diurutkan berdasarkan nama\n";
            tampilData(data, n);
        }
        else if (pilih == 6) {
            sortHarga(data, n);
            cout << "data diurutkan berdasarkan harga\n";
            tampilData(data, n);
        }
    } while (pilih != 0);
    return 0;
}