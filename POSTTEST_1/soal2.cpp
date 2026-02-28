//struct + array data mahasiswa
#include <iostream>
using namespace std;
struct mahasiswa {
    string nama;
    string nim;
    float ipk;
};
int main() {
    mahasiswa data[5];
    int maxIndex = 0;
    for (int i = 0; i < 5; i++) {
        cout << "\ndata mahasiswa ke-" << i + 1 << endl;
        cout << "nama : ";
        getline(cin >> ws, data[i].nama);
        cout << "NIM  : ";
        cin >> data[i].nim;
        cout << "IPK  : ";
        cin >> data[i].ipk;
    }
    for (int i = 1; i < 5; i++) {
        if (data[i].ipk > data[maxIndex].ipk) {
            maxIndex = i;
        }
    }
    cout << "\nmahasiswa dengan IPK tertinggi" << endl;
    cout << "nama : " << data[maxIndex].nama << endl;
    cout << "NIM  : " << data[maxIndex].nim << endl;
    cout << "IPK  : " << data[maxIndex].ipk << endl;
    return 0;
}