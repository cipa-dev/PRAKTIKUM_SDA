//array dan pointer - operasi dasar
#include <iostream>
using namespace std;
int main() {
    int data[7] = {2, 3, 5, 7, 11, 13, 17};
    int *awal, *akhir, temp;
    cout << "--- array sebelum dibalik ---" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "index ke-" << i
            << " | nilai: " << data[i]
            << " | alamat: " << &data[i] << endl;
    }
    awal = data;
    akhir = data + 6;
    while (awal < akhir) {
        temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
    cout << "\n--- array sesudah dibalik ---" << endl;
    for (int i = 0; i < 7; i++) {
        cout << "index ke-" << i
            << " | nilai: " << data[i]
            << " | alamat: " << &data[i] << endl;
    }
    return 0;
}