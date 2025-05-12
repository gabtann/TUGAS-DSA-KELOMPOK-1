#include <stdio.h>
#include <stdlib.h>

// Definisi struktur Node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Fungsi untuk melakukan preorder traversal
void preOrder(struct Node* root) {
    if (root == NULL)
        return;

    printf("%d ", root->data);   // Kunjungi root
    preOrder(root->left);        // Subtree kiri
    preOrder(root->right);       // Subtree kanan
}

int main() {
    // Membuat tree:
    //     1
    //      \
    //       2
    //        \
    //         5
    //        / \
    //       3   6
    //        \
    //         4

    struct Node* root = createNode(1);
    root->right = createNode(2);
    root->right->right = createNode(5);
    root->right->right->left = createNode(3);
    root->right->right->right = createNode(6);
    root->right->right->left->right = createNode(4);

    // Cetak preorder traversal
    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");

    return 0;
}
