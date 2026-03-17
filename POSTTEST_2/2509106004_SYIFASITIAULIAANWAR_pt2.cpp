#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

// swap pakai pointer
void swapData(Kereta *a, Kereta *b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

// tampil data (pakai pointer)
void tampilData(Kereta *arr, int n) {
    cout << "\n=== Jadwal Kereta ===\n";
    for (int i = 0; i < n; i++) {
        cout << (arr + i)->nomor << " | "
             << (arr + i)->nama << " | "
             << (arr + i)->asal << " - "
             << (arr + i)->tujuan << " | "
             << (arr + i)->harga << endl;
    }
}

// tambah data
void tambahData(Kereta *arr, int &n) {
    cout << "\nTambah Data Kereta\n";
    cout << "Nomor   : "; cin >> arr[n].nomor;
    cin.ignore();
    cout << "Nama    : "; getline(cin, arr[n].nama);
    cout << "Asal    : "; getline(cin, arr[n].asal);
    cout << "Tujuan  : "; getline(cin, arr[n].tujuan);
    cout << "Harga   : "; cin >> arr[n].harga;
    n++;
}

// sorting nomor (biar jump search aman)
void sortNomor(Kereta *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((arr + i)->nomor > (arr + j)->nomor) {
                swapData(&arr[i], &arr[j]);
            }
        }
    }
}

// linear search berdasarkan rute
void cariRute(Kereta *arr, int n) {
    string asal, tujuan;
    bool ketemu = false;

    cin.ignore();
    cout << "Masukkan asal   : "; getline(cin, asal);
    cout << "Masukkan tujuan : "; getline(cin, tujuan);

    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "Ditemukan: " << (arr + i)->nama << endl;
            ketemu = true;
        }
    }

    if (!ketemu) {
        cout << "Data tidak ditemukan\n";
    }
}

// jump search berdasarkan nomor
int jumpSearch(Kereta *arr, int n, int key) {
    int step = sqrt(n);
    int prev = 0;

    while ((arr + (step < n ? step : n) - 1)->nomor < key) {
        prev = step;
        step += sqrt(n);
        if (prev >= n) return -1;
    }

    for (int i = prev; i < (step < n ? step : n); i++) {
        if ((arr + i)->nomor == key) {
            return i;
        }
    }
    return -1;
}

// selection sort berdasarkan harga
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

// merge sort berdasarkan nama
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

    // data awal
    data[0] = {101, "Argo", "Jakarta", "Surabaya", 300000};
    data[1] = {102, "Taksaka", "Yogyakarta", "Jakarta", 250000};
    data[2] = {103, "Matarmaja", "Malang", "Jakarta", 200000};

    int pilih;

    do {
        cout << "\n=== MENU ===\n";
        cout << "1. Tampil Data\n";
        cout << "2. Tambah Data\n";
        cout << "3. Cari Rute (Linear)\n";
        cout << "4. Cari Nomor (Jump)\n";
        cout << "5. Urut Nama (Merge Sort)\n";
        cout << "6. Urut Harga (Selection Sort)\n";
        cout << "0. Keluar\n";
        cout << "Pilih: ";
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
            cout << "Masukkan nomor: "; cin >> key;

            sortNomor(data, n); // biar urut dulu
            int hasil = jumpSearch(data, n, key);

            if (hasil != -1)
                cout << "Ditemukan: " << data[hasil].nama << endl;
            else
                cout << "Tidak ditemukan\n";
        }
        else if (pilih == 5) {
            mergeSort(data, 0, n - 1);
            cout << "Data diurutkan berdasarkan nama\n";
            tampilData(data, n);
        }
        else if (pilih == 6) {
            sortHarga(data, n);
            cout << "Data diurutkan berdasarkan harga\n";
            tampilData(data, n);
        }

    } while (pilih != 0);

    return 0;
}