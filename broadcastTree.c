#include <stdio.h>

void adj(int k, int n, int a[10][10]);

int main() {
    int a[10][10], n, root;
    int i, j;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter connection of %d --> %d: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("Enter root node: ");
    scanf("%d", &root);

    adj(root, n, a);

    return 0;
}

void adj(int k, int n, int a[10][10]) {
    int j;

    printf("Adjacent nodes of root node %d:\n", k);

    for (j = 1; j <= n; j++) {
        if (a[k][j] == 1 || a[j][k] == 1) {
            printf("%d\t", j);
        }
    }

    printf("\n");
}
