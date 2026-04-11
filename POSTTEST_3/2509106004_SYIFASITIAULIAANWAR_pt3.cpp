#include <iostream>
#include <string>
#include <cmath>
#include <limits>
#include <iomanip>
#include <cstdlib>
using namespace std;
#define MAX 100

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
};
struct Queue {
    Tiket data[MAX];
    int front, rear;
};
void initQueue(Queue *q) {
    q->front = q->rear = -1;
}
bool kosongQ(Queue *q) {
    return q->front == -1;
}
bool penuhQ(Queue *q) {
    return q->rear == MAX - 1;
}
void enqueue(Queue *q, Tiket t) {
    if (penuhQ(q)) {
        cout << "antrian penuh!\n";
        return;
    }
    if (kosongQ(q)) q->front = 0;
    q->rear++;
    *(q->data + q->rear) = t;
}
Tiket dequeue(Queue *q) {
    Tiket t;
    if (kosongQ(q)) {
        cout << "antrian kosong!\n";
        return t;
    }
    t = *(q->data + q->front);
    for (int i = q->front; i < q->rear; i++) {
        *(q->data + i) = *(q->data + i + 1);
    }
    q->rear--;
    if (q->rear < q->front) {
        q->front = q->rear = -1;
    }
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
    for (int i = q->front; i <= q->rear; i++) {
        cout << left << setw(20) << (q->data + i)->namaPenumpang
            << setw(15) << (q->data + i)->asal
            << setw(15) << (q->data + i)->tujuan << endl;
    }
}
struct Stack {
    Tiket data[MAX];
    int top;
};
void initStack(Stack *s) {
    s->top = -1;
}
bool kosongS(Stack *s) {
    return s->top == -1;
}
bool penuhS(Stack *s) {
    return s->top == MAX - 1;
}
void push(Stack *s, Tiket t) {
    if (penuhS(s)) {
        cout << "riwayat penuh!\n";
        return;
    }
    s->top++;
    *(s->data + s->top) = t;
}
void pop(Stack *s) {
    if (kosongS(s)) {
        cout << "riwayat kosong!\n";
        return;
    }
    cout << "hapus transaksi: "
        << (s->data + s->top)->namaPenumpang << endl;
    s->top--;
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
    for (int i = s->top; i >= 0; i--) {
        cout << left << setw(20) << (s->data + i)->namaPenumpang
            << setw(15) << (s->data + i)->asal
            << setw(15) << (s->data + i)->tujuan << endl;
    }
}
void peek(Queue *q, Stack *s) {
    cout << "\n--- PEEK ---\n";
    if (!kosongQ(q)) {
        cout << "depan antrian: "
            << (q->data + q->front)->namaPenumpang << endl;
    } else {
        cout << "antrian kosong\n";
    }
    if (!kosongS(s)) {
        cout << "transaksi terakhir: "
            << (s->data + s->top)->namaPenumpang << endl;
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
        cout << left << setw(10) << (arr + i)->nomor
            << setw(15) << (arr + i)->nama
            << setw(15) << (arr + i)->asal
            << setw(15) << (arr + i)->tujuan
            << setw(10) << (arr + i)->harga << endl;
    }
}
int main() {
    Kereta data[MAX];
    int n = 3;
    data[0] = {101, "caca", "jakarta", "surabaya", 300000};
    data[1] = {102, "cibel", "yogyakarta", "jakarta", 250000};
    data[2] = {103, "kai", "malang", "jakarta", 200000};
    Queue q;
    Stack s;
    initQueue(&q);
    initStack(&s);
    int pilih;
    do {
        system("cls"); // bersihkan layar
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
            tampilData(data, n);
        }
        else if (pilih == 2) {
            Tiket t;
            tampilData(data, n);
            int nomor;
            cout << "pilih nomor kereta: ";
            cin >> nomor;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            bool ketemu = false;
            for (int i = 0; i < n; i++) {
                if ((data + i)->nomor == nomor) {
                    cout << "nama penumpang: ";
                    getline(cin, t.namaPenumpang);
                    t.asal = (data + i)->asal;
                    t.tujuan = (data + i)->tujuan;
                    enqueue(&q, t);
                    ketemu = true;
                    break;
                }
            }
            if (!ketemu) {
                cout << "nomor tidak ditemukan!\n";
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