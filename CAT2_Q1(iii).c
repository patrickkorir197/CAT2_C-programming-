#include <stdio.h>

int main() {
    int scores[2][4] = {
        {65, 92, 35, 70},
        {84, 72, 59, 67}
    };

    printf("Elements of the scores array:\n");

    for (int i = 0; i < 2; i++) {           // Loop through rows
        for (int j = 0; j < 4; j++) {       // Loop through columns
            printf("%d ", scores[i][j]);    // Print each element
        }
        printf("\n");                       // Move to next line after each row
    }

    return 0;
}