#include <stdio.h>
#include <string.h>
#define MAX 100

// Stack untuk karakter
char stack[MAX];
int top = -1;

// Fungsi push ke stack
void push(char c) {
    if (top < MAX - 1) {
        stack[++top] = c;
    }
}

// Fungsi pop dari stack
char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0'; // return null character jika kosong
}

// Fungsi untuk membalikkan string menggunakan stack
void reverse(char *str) {
    int len = strlen(str);

    // Push semua karakter ke stack
    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    // Pop karakter dan simpan kembali ke string
    for (int i = 0; i < len; i++) {
        str[i] = pop();
    }
}

int main() {
    char str[MAX];

    printf("Masukkan string: ");
    scanf("%s", str);  // Membaca string tanpa spasi

    reverse(str);

    printf("Hasil dibalik: %s\n", str);

    return 0;
}
