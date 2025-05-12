#include <stdio.h>
#include <stdlib.h>

// Definisi struktur untuk node linked list
typedef struct SinglyLinkedListNode {
    int data;
    struct SinglyLinkedListNode* next;
} SinglyLinkedListNode;

// Fungsi untuk membuat node baru
SinglyLinkedListNode* create_singly_linked_list_node(int node_data) {
    SinglyLinkedListNode* node = (SinglyLinkedListNode*)malloc(sizeof(SinglyLinkedListNode));
    node->data = node_data;
    node->next = NULL;
    return node;
}

// Fungsi untuk mencetak linked list
void print_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        printf("%d\n", node->data);
        node = node->next;
    }
}

// Fungsi untuk membebaskan memori linked list
void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;
        free(temp);
    }
}

// Fungsi untuk menyisipkan node di depan head
SinglyLinkedListNode* insertNodeAtHead(SinglyLinkedListNode* llist, int data) {
    // Buat node baru dengan data yang diberikan
    SinglyLinkedListNode* new_node = create_singly_linked_list_node(data);
    
    // Set pointer next dari node baru ke head lama
    new_node->next = llist;
    
    // Kembalikan node baru sebagai head baru
    return new_node;
}

int main() {
    SinglyLinkedListNode* head = NULL;
    int n, data;

    // Input jumlah elemen
    printf("Masukkan jumlah elemen: ");
    scanf("%d", &n);

    // Input elemen dan sisipkan ke linked list
    for (int i = 0; i < n; i++) {
        printf("Masukkan elemen ke-%d: ", i + 1);
        scanf("%d", &data);
        head = insertNodeAtHead(head, data);
    }

    // Cetak linked list
    printf("\nIsi linked list:\n");
    print_singly_linked_list(head);

    // Bebaskan memori
    free_singly_linked_list(head);

    return 0;
}
