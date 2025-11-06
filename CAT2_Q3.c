#include <stdio.h>
#include <stdlib.h>

// Function prototypes
void writeIntegersToFile();
void processIntegers();
void displayFiles();

int main() {
    writeIntegersToFile();   // Step 1: Input and write integers to input.txt
    processIntegers();       // Step 2: Read, compute, and write results to output.txt
    displayFiles();          // Step 3: Display both files

    return 0;
}

// Function 1: Prompts user for 10 integers and writes to input.txt
void writeIntegersToFile() {
    FILE *fp;
    int num;

    fp = fopen("input.txt", "w");
    if (fp == NULL) {
        printf("Error: Cannot open input.txt for writing.\n");
        exit(1);
    }

    printf("Enter 10 integers:\n");
    for (int i = 0; i < 10; i++) {
        printf("Number %d: ", i + 1);
        scanf("%d", &num);
        fprintf(fp, "%d\n", num);
    }

    fclose(fp);
    printf("\nNumbers successfully written to input.txt\n\n");
}

// Function 2: Reads from input.txt, calculates sum & average, writes to output.txt
void processIntegers() {
    FILE *fin, *fout;
    int num, count = 0;
    float sum = 0, avg;

    fin = fopen("input.txt", "r");
    if (fin == NULL) {
        printf("Error: Cannot open input.txt for reading.\n");
        exit(1);
    }

    fout = fopen("output.txt", "w");
    if (fout == NULL) {
        printf("Error: Cannot open output.txt for writing.\n");
        fclose(fin);
        exit(1);
    }

    while (fscanf(fin, "%d", &num) == 1) {
        sum += num;
        count++;
    }

    if (count > 0)
        avg = sum / count;
    else
        avg = 0;

    fprintf(fout, "Sum = %.2f\nAverage = %.2f\n", sum, avg);

    fclose(fin);
    fclose(fout);

    printf("Sum and average successfully written to output.txt\n\n");
}

// Function 3: Displays contents of both input.txt and output.txt
void displayFiles() {
    FILE *fp;
    char ch;

    printf("Contents of input.txt:\n");
    fp = fopen("input.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open input.txt.\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);

    printf("\nContents of output.txt:\n");
    fp = fopen("output.txt", "r");
    if (fp == NULL) {
        printf("Error: Cannot open output.txt.\n");
        return;
    }
    while ((ch = fgetc(fp)) != EOF)
        putchar(ch);
    fclose(fp);
}