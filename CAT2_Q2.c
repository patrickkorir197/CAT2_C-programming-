#include <stdio.h>

int main() {
    float hours, rate;        // input variables
    float gross_pay, taxes, net_pay;

    // Ask user for input
    printf("Enter hours worked in a week: ");
    scanf("%f", &hours);

    printf("Enter hourly wage: ");
    scanf("%f", &rate);

    // Calculate gross pay
    if (hours <= 40) {
        gross_pay = hours * rate;
    } else {
        gross_pay = (40 * rate) + ((hours - 40) * rate * 1.5);
    }

    // Calculate taxes
    if (gross_pay <= 600) {
        taxes = gross_pay * 0.15;
    } else {
        taxes = (600 * 0.15) + ((gross_pay - 600) * 0.20);
    }

    // Calculate net pay
    net_pay = gross_pay - taxes;

    // Display results
    printf("\nGross Pay: $%.2f\n", gross_pay);
    printf("Taxes:     $%.2f\n", taxes);
    printf("Net Pay:   $%.2f\n", net_pay);

    return 0;
}