//kompleksitas waktu analisis algoritma
#include <iostream>
using namespace std;
int main() {
    int angka[8] = {1, 1, 2, 3, 5, 8, 13, 21};
    int min = angka[0];
    int posisi = 0;
    for (int i = 1; i < 8; i++) {
        if (angka[i] < min) {
            min = angka[i];
            posisi = i;
        }
    }
    cout << "nilai minimum : " << min << endl;
    cout << "posisi index  : " << posisi << endl;
    return 0;
}