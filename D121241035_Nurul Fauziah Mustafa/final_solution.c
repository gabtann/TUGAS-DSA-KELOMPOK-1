#include <stdio.h>
#include <string.h>
#define MAX 100

char stack[MAX];
int top = -1;

void push(char letter) {
    if (top < MAX - 1) {
        top++;
        stack[top] = letter;
    }
}

char pop() {
    if (top >= 0) {
        char letter = stack[top];
        top--;
        return letter;
    }
    return '\0';
}

void reverse(char *text) {
    int i = 0;
    while (text[i] != '\0') {
        push(text[i]);
        i++;
    }

    i = 0;
    while (top >= 0) {
        text[i] = pop();
        i++;
    }
}

int main() {
    char kata[MAX];
    printf("Masukkan kata: ");
    fgets(kata, MAX, stdin);

    kata[strcspn(kata, "\n")] = '\0';

    reverse(kata);
    printf("Hasil dibalik: %s\n", kata);
    return 0;
}
