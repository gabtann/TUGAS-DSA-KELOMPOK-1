#include <stdio.h>

#define MAX 100000

// Dua stack untuk membuat antrian
int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

// Fungsi untuk memasukkan data ke antrian
void enqueue(int nilai) {
    stack1[++top1] = nilai;
}

// Fungsi untuk memindahkan data dari stack1 ke stack2
void pindah() {
    while (top1 >= 0) {
        stack2[++top2] = stack1[top1--];
    }
}

// Fungsi untuk menghapus data terdepan dari antrian
void dequeue() {
    if (top2 == -1) {
        pindah(); // Pindah data jika stack2 kosong
    }
    if (top2 >= 0) {
        top2--; // Hapus data paling atas di stack2
    }
}

// Fungsi untuk melihat data terdepan dari antrian
void tampilDepan() {
    if (top2 == -1) {
        pindah(); // Pindah data jika stack2 kosong
    }
    if (top2 >= 0) {
        printf("%d\n", stack2[top2]); // Tampilkan elemen paling atas di stack2
    }
}

int main() {
    int q, perintah, data;

    // Input jumlah perintah
    scanf("%d", &q);

    while (q--) {
        scanf("%d", &perintah);
        if (perintah == 1) {
            scanf("%d", &data);
            enqueue(data);
        } else if (perintah == 2) {
            dequeue();
        } else if (perintah == 3) {
            tampilDepan();
        }
    }

    return 0;
}
