//pointer pada fungsi 
#include <iostream>
using namespace std;
void tukarNilai(int *a, int *b) {
    int sementara = *a;
    *a = *b;
    *b = sementara;
}
int main() {
    int x, y;
    cout << "masukkan nilai x: ";
    cin >> x;
    cout << "masukkan nilai y: ";
    cin >> y;
    cout << "\nsebelum ditukar" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    tukarNilai(&x, &y);
    cout << "\nsesudah ditukar" << endl;
    cout << "x = " << x << ", y = " << y << endl;
    return 0;
}