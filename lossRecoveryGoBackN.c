#include <stdio.h>

int main() {
    int w, i, f, frames[50];

    printf("Enter window size: ");
    scanf("%d", &w);

    printf("\nEnter number of frames to transmit: ");
    scanf("%d", &f);

    printf("\nEnter %d frames: ", f);
    for (i = 1; i <= f; i++) {
        scanf("%d", &frames[i]);
    }

    printf("\nWith sliding window protocol and Go-Back-N loss recovery, ");
    printf("the frames will be sent in the following manner ");
    printf("(assuming no corruption of frames)\n\n");

    int base = 1;
    int nextSeqNum = 1;

    while (base <= f) {
        printf("Sending frames: ");
        for (i = base; i < base + w && i <= f; ++i) {
            printf("%d ", frames[i]);
        }

        printf("\nEnter the last acknowledged frame number: ");
        int ack;
        scanf("%d", &ack);

        if (ack < nextSeqNum) {
            printf("Duplicate or delayed ACK received. Ignoring...\n\n");
            continue;
        }

        base = ack + 1;
        nextSeqNum = base;

        if (base <= f) {
            printf("Acknowledgment received. Sliding window to frames %d to %d\n\n",
                   base, base + w - 1 <= f ? base + w - 1 : f);
        }
    }

    printf("\nAcknowledgment of all frames sent is received by sender.\n");

    return 0;
}
