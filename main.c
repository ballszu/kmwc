#include <stdio.h>
#include <stdbool.h>

int var = 0, m;
int minterms[20]; // Global variable

// Updated function with a different parameter name
bool contains(int arr[], int target) {
    for (int i = 0; i < m; i++) {
        if (arr[i] == target) {
            return true; // Target found
        }
    }
    return false; // Target not found
}

int main() {
    // Getting the input from the user
    printf("-------------------------------\n");
    printf("Welcome to the Kmap Solver!\n");
    printf("-------------------------------\n");
    printf("How many variables are in the Expression?\n");
    printf("(Values Ranging from 2 to 4) = ");
    while (var > 4 || var < 2) {
        scanf("%d", &var);
        if (var > 4 || var < 2)
            printf("Please Enter a valid input! ");
    }
    printf("-------------------------------\n");
    printf("How many minterms are there?\n");
    scanf("%d", &m);
    printf("Enter the minterms below\n");
    for (int i = 0; i < m; i++) {
        scanf("%d", &minterms[i]);
    }
    printf("-------------------------------\n");

    if (var == 2) {
        // For 2 variables, the K-map is 2x2
        int kmap2[2][2] = {{0, 0}, {0, 0}}; // Initialize to 0

        // Fill the K-map based on minterms
        for (int i = 0; i < m; i++) {
            int minterm = minterms[i];
            if (minterm < 4) {
                int row = minterm / 2;  // Calculate row index
                int col = minterm % 2;  // Calculate column index
                kmap2[row][col] = 1;   // Set the cell to 1
            }
        }

        // Print the K-map
        printf("K-map:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                printf("%d ", kmap2[i][j]);
            }
            printf("\n");
        }
    }
    return 0;
}
