#include <stdio.h>

void main() {
    int path[5][5], i, j, min, a[5][5], p;
    int st = 1, ed = 5, stp, edp, t[5], index;

    // Input the cost matrix
    printf("Enter cost matrix:\n");
    for (i = 1; i <= 5; i++) {
        for (j = 1; j <= 5; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    // Input the number of paths
    printf("Enter number of paths:\n");
    scanf("%d", &p);

    // Input all possible paths
    printf("Enter possible paths:\n");
    for (i = 1; i <= p; i++) {
        for (j = 1; j <= 5; j++) {
            scanf("%d", &path[i][j]);
        }
    }

    // Calculate the total cost for each path
    for (i = 1; i <= p; i++) {
        t[i] = 0;
        stp = st;

        for (j = 1; j <= 5; j++) {
            edp = path[i][j];
            t[i] += a[stp][edp];

            if (edp == ed)
                break;
            else
                stp = edp;
        }
    }

    // Find the minimum cost among all paths
    min = t[1];
    index = 1;

    for (i = 2; i <= p; i++) {
        if (min > t[i]) {
            min = t[i];
            index = i;
        }
    }

    // Output the minimum cost and corresponding path
    printf("Minimum cost: %d", min);
    printf("\nMinimum cost path: ");

    for (i = 1; i <= 5; i++) {
        printf("->%d", path[index][i]);
        if (path[index][i] == ed)
            break;
    }
}
