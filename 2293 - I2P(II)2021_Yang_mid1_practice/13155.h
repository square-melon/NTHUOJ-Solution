#include <stdio.h>
#include <stdlib.h>
#define max(a, b) a > b ? a : b

struct Node {
    int id;
    struct Node *next;
};

struct Graph {
    int vertices_num;
    struct Node **adjLists;
};

struct Graph* createGraph(int);
void addEdge(struct Graph*, int, int);
int findMax(struct Graph*, int, int);
void freeGraph(struct Graph*);

struct Graph* createGraph(int n) {
    struct Graph *newGraph = (struct Graph*)malloc(sizeof(struct Graph));
    newGraph->vertices_num = n;
    newGraph->adjLists = (struct Node**)malloc(sizeof(struct Node*) * n);
    for (int i = 0; i < n; i++) newGraph->adjLists[i] = NULL;
    return newGraph;
}

void addEdge(struct Graph *g, int u, int v) {
    struct Node *cur = (struct Node*)malloc(sizeof(struct Node));
    cur->id = v;
    cur->next = g->adjLists[u];
    g->adjLists[u] = cur;
    struct Node *curr = (struct Node*)malloc(sizeof(struct Node));
    curr->id = u;
    curr->next = g->adjLists[v];
    g->adjLists[v] = curr;
}

int findMax(struct Graph *g, int a, int b) {
    int sol = a;
    for (struct Node *it = g->adjLists[a]; it; it = it->next) {
        if (it->id == b) continue;
        else sol = max(sol, findMax(g, it->id, a));
    }
    return sol;
}

void freeGraph(struct Graph *g) {
    for (int i = 0; i < g->vertices_num; i++) {
        struct Node *cur = g->adjLists[i];
        while (cur) {
            struct Node* byebye = cur;
            cur = cur->next;
            free(byebye);
        }
    }
    free(g->adjLists);
    free(g);
}