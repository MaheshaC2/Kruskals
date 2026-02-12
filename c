#include <stdio.h>

int parent[20];

int find(int x) {
    while (parent[x] != x)
        x = parent[x];
    return x;
}

void unite(int a, int b) {
    parent[a] = b;
}

int main() {
    int n, e;
    printf("Enter vertices and edges: ");
    scanf("%d %d", &n, &e);

    int u[e], v[e], w[e];
    printf("Enter edges (u v w):\n");
    for (int i = 0; i < e; i++)
        scanf("%d %d %d", &u[i], &v[i], &w[i]);

    for (int i = 0; i < n; i++)
        parent[i] = i;

    // sort edges by weight
    for (int i = 0; i < e; i++)
        for (int j = i + 1; j < e; j++)
            if (w[i] > w[j]) {
                int t=w[i]; w[i]=w[j]; w[j]=t;
                t=u[i]; u[i]=u[j]; u[j]=t;
                t=v[i]; v[i]=v[j]; v[j]=t;
            }

    int total = 0;
    printf("\nMST edges:\n");

    for (int i = 0; i < e; i++) {
        int a = find(u[i]);
        int b = find(v[i]);
        if (a != b) {
            printf("%d -- %d  (%d)\n", u[i], v[i], w[i]);
            total += w[i];
            unite(a, b);
        }
    }

    printf("Total weight = %d\n", total);
    return 0;
}
