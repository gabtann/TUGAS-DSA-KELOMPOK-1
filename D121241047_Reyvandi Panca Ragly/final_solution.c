#include <stdbool.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

bool dfs(Node** adj_list, int node, int dest, bool* visited) {
    if (node == dest) return true;
    visited[node] = true;
    for (Node* cur = adj_list[node]; cur; cur = cur->next) {
        if (!visited[cur->val] && dfs(adj_list, cur->val, dest, visited)) {
            return true;
        }
    }
    return false;
}

bool validPath(int n, int** edges, int edgesSize, int* edgesColSize, int source, int destination) {
    if (source == destination) return true;

    Node** adj_list = (Node**)calloc(n, sizeof(Node*));
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0], v = edges[i][1];
        Node* nodeU = (Node*)malloc(sizeof(Node));
        nodeU->val = v; nodeU->next = adj_list[u]; adj_list[u] = nodeU;

        Node* nodeV = (Node*)malloc(sizeof(Node));
        nodeV->val = u; nodeV->next = adj_list[v]; adj_list[v] = nodeV;
    }

    bool* visited = (bool*)calloc(n, sizeof(bool));
    bool result = dfs(adj_list, source, destination, visited);

    for (int i = 0; i < n; i++) {
        Node* cur = adj_list[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }

    free(adj_list);
    free(visited);
    return result;
}
