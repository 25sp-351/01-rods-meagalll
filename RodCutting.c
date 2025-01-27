#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int length;  // Length of the piece
    int value;   // Value of the piece
} RodCutPiece;

int main(int argc, char *argv[]) {
    // Ensure the correct number of arguments (only 1 argument, the rod length)
    if (argc != 2) {//Checks if the number of command-line arguments (argc) is not equal to 2.
        fprintf(stderr, "Usage: %s supplied rod length\n", argv[0]); 
        return 1;
    }

    // Convert the rod length argument from string to integer
    int suppliedRodLength = atoi(argv[1]);
    if (suppliedRodLength <= 0) {
        fprintf(stderr, "Rod length must be a positive integer.\n");
        return 1;
    }

    // Read piece lengths and values from standard input
    RodCutPiece cuts[150];  // Array to store up to 100 cuts
    int pieceCount = 0;

    int length, value;
    while (scanf("%d, %d", &length, &value) == 2) {
        cuts[pieceCount].length = length;
        cuts[pieceCount].value = value;
        pieceCount++;
    }

    // Variables to track the remaining rod length and total value
    int remainingLength = suppliedRodLength;
    int totalValue = 0;

    // Output the cutting list
    for (int i = 0; i < pieceCount; i++) {
        int pieceCountUsed = 0;

        // Determine how many times the current piece can fit into the remaining length
        while (remainingLength >= cuts[i].length) {
            pieceCountUsed++;
            remainingLength -= cuts[i].length;
            totalValue += cuts[i].value;
        }

        // If the piece was used, print its contribution
        if (pieceCountUsed > 0) {
            printf("%d @ %d = %d\n", pieceCountUsed, cuts[i].length, pieceCountUsed * cuts[i].value);
        }
    }

    // Output the remainder and the total value
    printf("Remainder: %d\n", remainingLength);
    printf("Value: %d\n", totalValue);

    return 0;
}
