#include <iostream>
using namespace std;
void tukarNilai(int *a, int *b) {
    int sementara = *a;
    *a = *b;
    *b = sementara;
}
int main() {
    int x, y;
    cout << "Masukkan nilai x: ";
    cin >> x;
    cout << "Masukkan nilai y: ";
    cin >> y;
    cout << "\nSebelum ditukar" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    tukarNilai(&x, &y);
    cout << "\nSesudah ditukar" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}