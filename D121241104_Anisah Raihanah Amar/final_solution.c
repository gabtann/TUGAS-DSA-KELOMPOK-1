#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
    Node* tail;
} LinkedList;

Node* createNode(int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;

    if (list->tail == NULL) {
        list->tail = newNode;
    }
}

void printList(Node* head) {
    printf("\nIsi linked list:\n");
    while (head) {
        printf("%d\n", head->data);
        head = head->next;
    }
}

int main() {
    int n, x;
    LinkedList list;
    list.head = NULL;
    list.tail = NULL;

    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Masukkan data ke-%d: ", i + 1);
        scanf("%d", &x);
        insertAtHead(&list, x);
    }

    printList(list.head);

    return 0;
}
