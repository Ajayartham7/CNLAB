#include <stdio.h>
#include <string.h>
#define MAX 100

void characterCountFraming(char data[], int frameSize[], int numFrames) {
    char framedData[MAX];
    int index = 0; // Index for input data
    int pos = 0;   // Index for framedData

    // Add each frame with a count byte
    for (int i = 0; i < numFrames; i++) {
        int count = frameSize[i] + 1; // +1 for the count byte itself
        framedData[pos++] = count;
        for (int j = 0; j < frameSize[i]; j++) {
            framedData[pos++] = data[index++];
        }
    }

    // Display the transmitted framed data
    printf("\nTransmitted Framed Data (Character Count Framing):\n");
    for (int i = 0; i < pos; i++) {
        printf("%d ", framedData[i]);
    }

    // Simulate receiver side
    printf("\n\nReceiver Side (Extracted Frames):\n");
    int i = 0;
    while (i < pos) {
        int count = framedData[i];
        printf("Frame of %d characters: ", count - 1); // Exclude count byte
        for (int j = 1; j < count; j++) {
            printf("%d ", framedData[i + j]);
        }
        printf("\n");
        i += count;
    }
}

int main() {
    // Example input data
    char data[MAX];
    int frameSize[MAX], numFrames;

    printf("Enter total number of frames: ");
    scanf("%d", &numFrames);

    int totalData = 0;

    // Read frame sizes
    for (int i = 0; i < numFrames; i++) {
        printf("Enter size of frame %d: ", i + 1);
        scanf("%d", &frameSize[i]);
        totalData += frameSize[i];
    }

    // Read data bytes
    printf("Enter %d data bytes (as integers):\n", totalData);
    for (int i = 0; i < totalData; i++) {
        scanf("%d", (int *)&data[i]);
    }

    // Perform Character Count Framing
    characterCountFraming(data, frameSize, numFrames);

    return 0;
}


