//kompleksitas waktu analisis algoritma
#include <iostream>
using namespace std;
int cariMinimum(int data[], int jumlah, int &posisi) {
    int terkecil = data[0];
    posisi = 0;
    for (int i = 1; i < jumlah; i++) {
        if (data[i] < terkecil) {
            terkecil = data[i];
            posisi = i;
        }
    }
    return terkecil;
}
int main() {
    int angka[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int index;
    int hasil = cariMinimum(angka, 8, index);
    cout << "Nilai minimum  : " << hasil << endl;
    cout << "Posisi indeks  : " << index << endl;
    return 0;
}