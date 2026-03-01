//struct + array data mahasiswa
#include <iostream>
using namespace std;
struct mahasiswa {
    string nama;
    string nim;
    float ipk;
};
int main() {
    mahasiswa mhs[5];
    int indexMax = 0;
    for (int i = 0; i < 5; i++) {
        cout << "\ndata mahasiswa ke-" << i + 1 << endl;
        cout << "nama : ";
        getline(cin >> ws, mhs[i].nama);
        cout << "nim  : ";
        cin >> mhs[i].nim;
        cout << "ipk  : ";
        cin >> mhs[i].ipk;
    }
    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > mhs[indexMax].ipk) {
            indexMax = i;
        }
    }
    cout << "\nmahasiswa dengan ipk tertinggi" << endl;
    cout << "nama : " << mhs[indexMax].nama << endl;
    cout << "nim  : " << mhs[indexMax].nim << endl;
    cout << "ipk  : " << mhs[indexMax].ipk << endl;
    return 0;
}