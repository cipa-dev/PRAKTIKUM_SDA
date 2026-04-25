#include <iostream>
#include <string>
using namespace std;
// sturktur buat circular linked list untuk data sembako di gudang
struct BarangNode {
    string namaBarang;
    int stok;
    BarangNode* next;
    // konstruktor untuk inisialisasi node baru
    BarangNode(string nama, int jumlah) {
        namaBarang = nama;
        stok = jumlah;
        next = nullptr;
    }
};
// fungsi buat tambah barang baru ke circular linked list
BarangNode* tambahBarang(BarangNode* head, string nama, int jumlah) {
    BarangNode* newNode = new BarangNode(nama, jumlah);
    // kalau list masih kosong, node baru jadi head dan menunjuk ke dirinya sendiri
    if (head == nullptr) {
        newNode->next = newNode; // circular
        return newNode;
    }
    // cari node terakhir yang nunjuk ke head
    BarangNode* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    // sambungin node baru ke akhir list dan buat dia nunjuk ke head
    temp->next = newNode;
    newNode->next = head; // circular
    return head;
}
// fungsi buat tampilkan semua barang dan stoknya dari circular linked list
void tampilkanStokSembako(BarangNode* head) {
    // kalau list kosong, kasih tau dan keluar
    if (head == nullptr) {
        cout << "Gudang kosong." << endl;
        return;
    }
    BarangNode* temp = head;
    // loop buat tampilkan data barang satu per satu
    // berhenti kalau sudah muter balik ke head lagi
    do {
        cout << "- " << temp->namaBarang 
            << ": " << temp->stok << endl;
        temp = temp->next; // lanjut ke node berikutnya
    } while (temp != head); // cek kalau sudah balik ke awal list
}
int main() {
    BarangNode* head = nullptr;
    // tambah data
    head = tambahBarang(head, "Beras", 50);
    head = tambahBarang(head, "Minyak Goreng", 30);
    head = tambahBarang(head, "Gula Pasir", 20);
    head = tambahBarang(head, "Tepung Terigu", 15);
    cout << "Daftar Stok Sembako:" << endl;
    // tampilkan isi list
    tampilkanStokSembako(head);
    return 0;
}