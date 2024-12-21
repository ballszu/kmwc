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
        int kmap2[2][2] = {0}; // Initialize 2x2 K-map
        int kmap4[4][4] = {0}; // Initialize 4x4 K-map

        // Fill the 2x2 K-map
        for (int i = 0; i < 4; i++) {
            if (contains(minterms, i)) {
                kmap2[i / 2][i % 2] = 1; // Mark as 1 if the minterm exists
            }
        }

        // Print the 4x4 K-map
        printf("2x2 K-map:\n");
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (kmap2[i][j] == -1)
                    printf("X ");
                else
                    printf("%d ", kmap2[i][j]);
            }
            printf("\n");
        }
        //CHECKING IF THE ANSWERR WILL HAVE ONE ONE TERM OR TWO

        int count=0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if(kmap2[i][j]==1){
                    count++;
                }
            }
        }
        //IF ONE TERM I.E A GROUP OF 2 ONLY
    if(count%2==0){
    //Now working with the algorithm,
    //checking groups of 4,
        if(m==4){
            printf("The expression is: 0\n");
        }
    //checking Groups of 2
        if((kmap2[0][0]==1&&kmap2[0][1]==1) && (kmap2[1][0]==0&&kmap2[1][1]==0)){
            printf("The expression is: A'\n");
        }
        if((kmap2[1][0]==1&&kmap2[1][1]==1) && (kmap2[0][0]==0&&kmap2[0][1]==0)){
            printf("The expression is: A\n");
        }
        if((kmap2[0][0]==1&&kmap2[1][0]==1) && (kmap2[0][1]==0&&kmap2[1][1]==0)){
            printf("The expression is: B'\n");
        }
        if((kmap2[0][1]==1&&kmap2[1][1]==1) && (kmap2[0][0]==0&&kmap2[1][0]==0)){
            printf("The expression is: B\n");
        }
    }
    else if(count==3){
    //checking groups of 2
        int visa;
        if((kmap2[0][0]==1&&kmap2[0][1]==1)){
            printf("The expression is: A'");
            visa=1;
        }
        else if((kmap2[1][0]==1&&kmap2[1][1]==1)){
            printf("The expression is: A");
            visa=2;
        }
        else if((kmap2[0][0]==1&&kmap2[1][0]==1)){
            printf("The expression is: B'");
            visa=3;
        }
        else if((kmap2[0][1]==1&&kmap2[1][1]==1)){
            printf("The expression is: B");
            visa=4;
        }
        printf(" + ");
        if((kmap2[0][0]==1&&kmap2[0][1]==1)&&visa!=1){
            printf("A'");
        }
        if((kmap2[1][0]==1&&kmap2[1][1]==1)&&visa!=2){
            printf("A");
        }
        if((kmap2[0][0]==1&&kmap2[1][0]==1)&&visa!=3){
            printf("B'");
        }
        if((kmap2[0][1]==1&&kmap2[1][1]==1)&&visa!=4){
            printf("B");
        }
    }
    else if(count==1){
        printf("The Expression is: ");
        if(kmap2[0][0]==1){
            printf("A'B'");
        }
        if(kmap2[0][1]==1){
            printf("A'B");
        }
        if(kmap2[1][0]==1){
            printf("AB'");
        }
        if(kmap2[1][1]==1){
            printf("AB");
        }
    }
    }
    return 0;
}
