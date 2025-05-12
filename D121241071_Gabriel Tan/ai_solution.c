#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

int stack1[MAX], stack2[MAX];
int top1 = -1, top2 = -1;

void push1(int x) {
    stack1[++top1] = x;
}

int pop1() {
    return stack1[top1--];
}

void push2(int x) {
    stack2[++top2] = x;
}

int pop2() {
    return stack2[top2--];
}

int peek2() {
    return stack2[top2];
}

void enqueue(int x) {
    push1(x);
}

void transferStack1ToStack2() {
    while (top1 != -1) {
        push2(pop1());
    }
}

void dequeue() {
    if (top2 == -1) {
        transferStack1ToStack2();
    }
    pop2();
}

void printFront() {
    if (top2 == -1) {
        transferStack1ToStack2();
    }
    printf("%d\n", peek2());
}

int main() {
    int q, type, value;
    scanf("%d", &q);

    for (int i = 0; i < q; i++) {
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
