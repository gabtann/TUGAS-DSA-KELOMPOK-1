#include <stdio.h>

#define MAX 100000

// Dua stack menggunakan array biasa
int stack1[MAX], top1 = -1;
int stack2[MAX], top2 = -1;

// Fungsi push
void push1(int value) {
    stack1[++top1] = value;
}

void push2(int value) {
    stack2[++top2] = value;
}

// Fungsi pop
int pop1() {
    return stack1[top1--];
}

int pop2() {
    return stack2[top2--];
}

// Fungsi cek apakah stack kosong
int isEmpty2() {
    return top2 == -1;
}

// Fungsi untuk memindahkan elemen dari stack1 ke stack2 jika stack2 kosong
void shiftStacks() {
    if (isEmpty2()) {
        while (top1 >= 0) {
            push2(pop1());
        }
    }
}

// Fungsi enqueue
void enqueue(int value) {
    push1(value);
}

// Fungsi dequeue
void dequeue() {
    shiftStacks();
    pop2();
}

// Fungsi untuk print elemen paling depan queue
void printFront() {
    shiftStacks();
    printf("%d\n", stack2[top2]);
}

// Main
int main() {
    int q, type, value;
    scanf("%d", &q);

    while (q--) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &value);
            enqueue(value);
        } else if (type == 2) {
            dequeue();
        } else if (type == 3) {
            printFront();
        }
    }

    return 0;
}
