#include <stdio.h>

int main(void) {
    int data[100], div[20], rem[20];
    int datalen = 0, divlen = 0, i, j, k;
    char ch;

    printf("Enter the data: ");
    while ((ch = getchar()) != '\n')
        data[datalen++] = ch - '0';

    printf("Enter the divisor: ");
    while ((ch = getchar()) != '\n')
        div[divlen++] = ch - '0';

    for (i = 0; i < divlen - 1; i++)
        data[datalen + i] = 0;

    for (i = 0; i < divlen; i++)
        rem[i] = data[i];

    k = divlen;

    while (k <= datalen + divlen - 1) {
        if (rem[0] == 1) {
            for (i = 0; i < divlen; i++)
                rem[i] ^= div[i];
        }
        for (i = 0; i < divlen - 1; i++)
            rem[i] = rem[i + 1];
        rem[i] = data[k++];
    }

    for (i = 0; i < divlen - 1; i++)
        data[datalen + i] = rem[i];

    printf("\nThe data to be sent is:\n");
    for (i = 0; i < datalen + divlen - 1; i++)
        printf("%d", data[i]);

    return 0;
}
