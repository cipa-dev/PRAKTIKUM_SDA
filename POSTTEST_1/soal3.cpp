#include <iostream>
using namespace std;
void balikArray(int *ptr, int n) {
    int *awal = ptr;
    int *akhir = ptr + n - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
}
int main() {
    int bilangan[7] = {2, 3, 5, 7, 11, 13, 17};
    cout << "array sebelum dibalik:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << bilangan[i] << " | alamat: " << (bilangan + i) << endl;
    }
    balikArray(bilangan, 7);
    cout << "\narray sesudah dibalik:" << endl;
    for (int i = 0; i < 7; i++) {
        cout << bilangan[i] << " | alamat: " << (bilangan + i) << endl;
    }
    return 0;
}