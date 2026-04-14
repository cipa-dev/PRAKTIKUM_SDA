#include <iostream>
#include <string>
#include <limits>
#include <iomanip>
#include <cstdlib>
using namespace std;

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};
struct Tiket {
    string namaPenumpang;
    string asal;
    string tujuan;
    Tiket* next;
};
struct Queue {
    Tiket* front;
    Tiket* rear;
};
struct Stack {
    Tiket* top;
};
int counterPenumpang = 1;
void initQueue(Queue *q) {
    q->front = q->rear = NULL;
}
bool kosongQ(Queue *q) {
    return q->front == NULL;
}
void enqueue(Queue *q, Tiket t) {
    Tiket* baru = new Tiket;
    *baru = t;
    baru->next = NULL;
    if (kosongQ(q)) {
        q->front = q->rear = baru;
    } else {
        q->rear->next = baru;
        q->rear = baru;
    }
}
Tiket dequeue(Queue *q) {
    Tiket t;
    if (kosongQ(q)) {
        cout << "antrian kosong!\n";
        return t;
    }
    Tiket* hapus = q->front;
    t = *hapus;
    q->front = q->front->next;
    if (q->front == NULL) {
        q->rear = NULL;
    }
    delete hapus;
    return t;
}
void tampilQueue(Queue *q) {
    if (kosongQ(q)) {
        cout << "antrian kosong\n";
        return;
    }
    cout << "\n--- ANTRIAN PENUMPANG ---\n\n";
    cout << left << setw(20) << "Nama"
        << setw(15) << "Asal"
        << setw(15) << "Tujuan" << endl;
    cout << string(50, '-') << endl;
    Tiket* temp = q->front;
    while (temp != NULL) {
        cout << left << setw(20) << temp->namaPenumpang
            << setw(15) << temp->asal
            << setw(15) << temp->tujuan << endl;
        temp = temp->next;
    }
}
void initStack(Stack *s) {
    s->top = NULL;
}
bool kosongS(Stack *s) {
    return s->top == NULL;
}
void push(Stack *s, Tiket t) {
    Tiket* baru = new Tiket;
    *baru = t;
    baru->next = s->top;
    s->top = baru;
}
void pop(Stack *s) {
    if (kosongS(s)) {
        cout << "riwayat kosong!\n";
        return;
    }
    Tiket* hapus = s->top;
    cout << "hapus transaksi: " << hapus->namaPenumpang << endl;
    s->top = s->top->next;
    delete hapus;
}
void tampilStack(Stack *s) {
    if (kosongS(s)) {
        cout << "riwayat kosong\n";
        return;
    }
    cout << "\n--- RIWAYAT TRANSAKSI ---\n\n";
    cout << left << setw(20) << "Nama"
        << setw(15) << "Asal"
        << setw(15) << "Tujuan" << endl;
    cout << string(50, '-') << endl;
    Tiket* temp = s->top;
    while (temp != NULL) {
        cout << left << setw(20) << temp->namaPenumpang
            << setw(15) << temp->asal
            << setw(15) << temp->tujuan << endl;
        temp = temp->next;
    }
}
void peek(Queue *q, Stack *s) {
    cout << "\n--- PEEK ---\n";
    if (!kosongQ(q)) {
        cout << "depan antrian: " << q->front->namaPenumpang << endl;
    } else {
        cout << "antrian kosong\n";
    }
    if (!kosongS(s)) {
        cout << "transaksi terakhir: " << s->top->namaPenumpang << endl;
    } else {
        cout << "riwayat kosong\n";
    }
}
void tampilData(Kereta *arr, int n) {
    cout << "\n--- JADWAL KERETA ---\n\n";
    cout << left << setw(10) << "Nomor"
        << setw(15) << "Nama"
        << setw(15) << "Asal"
        << setw(15) << "Tujuan"
        << setw(10) << "Harga" << endl;
    cout << string(65, '-') << endl;
    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << arr[i].nomor
            << setw(15) << arr[i].nama
            << setw(15) << arr[i].asal
            << setw(15) << arr[i].tujuan
            << setw(10) << arr[i].harga << endl;
    }
}
int main() {
    Kereta data[3] = {
        {101, "caca", "jakarta", "surabaya", 300000},
        {102, "cibel", "yogyakarta", "jakarta", 250000},
        {103, "kai", "malang", "jakarta", 200000}
    };
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);
    int pilih;
    do {
        system("cls");
        cout << "--- MENU ---\n";
        cout << "1. tampil data \n";
        cout << "2. beli tiket\n";
        cout << "3. proses tiket\n";
        cout << "4. tampil antrian penumpang\n";
        cout << "5. tampil riwayat transaksi\n";
        cout << "6. hapus riwayat terakhir\n";
        cout << "7. peek\n";
        cout << "0. keluar\n";
        cout << "pilih: ";
        cin >> pilih;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        system("cls");
        if (pilih == 1) {
            tampilData(data, 3);
        }
        else if (pilih == 2) {
            Tiket t;
            tampilData(data, 3);
            int nomor;
            cout << "pilih nomor kereta: ";
            if (!(cin >> nomor)) {
                cout << "input harus angka!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            } else {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                bool ketemu = false;
                for (int i = 0; i < 3; i++) {
                    if (data[i].nomor == nomor) {
                        t.namaPenumpang = "Penumpang" + to_string(counterPenumpang++);
                        t.asal = data[i].asal;
                        t.tujuan = data[i].tujuan;
                        enqueue(&q, t);
                        cout << "tiket berhasil dipesan untuk "
                            << t.namaPenumpang << endl;
                        ketemu = true;
                        break;
                    }
                }
                if (!ketemu) {
                    cout << "nomor tidak ditemukan!\n";
                }
            }
        }
        else if (pilih == 3) {
            if (!kosongQ(&q)) {
                Tiket t = dequeue(&q);
                cout << "diproses: "
                    << t.namaPenumpang << " ("
                    << t.asal << " -> "
                    << t.tujuan << ")\n";
                push(&s, t);
            } else {
                cout << "antrian kosong!\n";
            }
        }
        else if (pilih == 4) {
            tampilQueue(&q);
        }
        else if (pilih == 5) {
            tampilStack(&s);
        }
        else if (pilih == 6) {
            pop(&s);
        }
        else if (pilih == 7) {
            peek(&q, &s);
        }
        cout << "\ntekan enter untuk lanjut...";
        cin.get();
    } while (pilih != 0);
    return 0;
}