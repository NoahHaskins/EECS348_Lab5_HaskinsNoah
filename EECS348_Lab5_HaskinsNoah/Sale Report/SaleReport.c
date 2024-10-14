/*
Noah Haskins
3094077
Lab 5
10/13/2024
*/

#include <stdio.h>   // For standard I/O functions like printf, fscanf
#include <stdlib.h>  // For functions like qsort and memory allocation
#include <string.h>  // For string manipulation (though not directly used)

#define MONTHS 12  // Define the total number of months

// Array containing the names of the months
const char *MONTH_NAMES[MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Define a struct to hold a month and its corresponding sales value
struct Sale {
    const char *month;  // Name of the month
    double value;       // Sales value for that month
};

// Function prototypes to declare the functions used in the program
void monthlySalesReport(double sales[]);
void salesSummaryReport(double sales[]);
void sixMonthMovingAverageReport(double sales[]);
void salesReportSorted(double sales[]);

// Prototype for comparison function used in qsort
int compareDescending(const void *a, const void *b);

int main() {
    double sales[MONTHS];  // Array to hold sales data for 12 months
    FILE *file = fopen("sales.txt", "r");  // Open the sales data file for reading

    // Check if the file opened successfully
    if (file == NULL) {
        printf("Error: Unable to open input file.\n");
        return 1;  // Exit with error code
    }

    // Read the sales data from the file
    for (int i = 0; i < MONTHS; i++) {
        if (fscanf(file, "%lf", &sales[i]) != 1) {  // Read a double value
            printf("Error: Invalid data in input file.\n");
            fclose(file);  // Close the file before exiting
            return 1;  // Exit with error code
        }
    }
    fclose(file);  // Close the file after reading the data

    // Generate and print all reports
    monthlySalesReport(sales);
    salesSummaryReport(sales);
    sixMonthMovingAverageReport(sales);
    salesReportSorted(sales);

    return 0;  // Program executed successfully
}

// Report 1: Display the sales for each month
void monthlySalesReport(double sales[]) {
    printf("Monthly Sales Report for 2024\n");
    printf("Month        Sales\n");
    // Loop through each month and print its sales
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s $%.2f\n", MONTH_NAMES[i], sales[i]);
    }
    printf("\n");  // Print a new line after the report
}

// Report 2: Display the minimum, maximum, and average sales
void salesSummaryReport(double sales[]) {
    double min = sales[0], max = sales[0], sum = 0;  // Initialize min, max, and sum
    int minMonth = 0, maxMonth = 0;  // Store indices of the min and max months

    // Loop through the sales to find min, max, and calculate the sum
    for (int i = 0; i < MONTHS; i++) {
        sum += sales[i];  // Accumulate the sum of sales
        if (sales[i] < min) {  // Check for a new minimum
            min = sales[i];
            minMonth = i;
        }
        if (sales[i] > max) {  // Check for a new maximum
            max = sales[i];
            maxMonth = i;
        }
    }
    double average = sum / MONTHS;  // Calculate the average sales

    // Print the summary report
    printf("Sales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, MONTH_NAMES[minMonth]);
    printf("Maximum sales: $%.2f (%s)\n", max, MONTH_NAMES[maxMonth]);
    printf("Average sales: $%.2f\n\n", average);
}

// Report 3: Display six-month moving averages
void sixMonthMovingAverageReport(double sales[]) {
    printf("Six-Month Moving Average Report:\n");
    // Loop to calculate the moving average for each 6-month period
    for (int i = 0; i <= MONTHS - 6; i++) {
        double sum = 0;  // Reset the sum for each 6-month window
        // Sum the sales for the current 6-month period
        for (int j = 0; j < 6; j++) {
            sum += sales[i + j];
        }
        double average = sum / 6;  // Calculate the average for the current period
        // Print the moving average for the current 6-month window
        printf("%s-%s: $%.2f\n", MONTH_NAMES[i], MONTH_NAMES[i + 5], average);
    }
    printf("\n");  // Print a new line after the report
}

// Report 4: Display sales sorted from highest to lowest
void salesReportSorted(double sales[]) {
    struct Sale sortedSales[MONTHS];  // Create an array of Sale structs

    // Populate the array with sales data
    for (int i = 0; i < MONTHS; i++) {
        sortedSales[i].month = MONTH_NAMES[i];
        sortedSales[i].value = sales[i];
    }

    // Use qsort to sort the array in descending order by sales value
    qsort(sortedSales, MONTHS, sizeof(struct Sale), compareDescending);

    // Print the sorted sales report
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month        Sales\n");
    for (int i = 0; i < MONTHS; i++) {
        printf("%-12s $%.2f\n", sortedSales[i].month, sortedSales[i].value);
    }
    printf("\n");  // Print a new line after the report
}

// Comparison function for qsort (descending order)
int compareDescending(const void *a, const void *b) {
    // Cast the pointers to Sale structs and compare their values
    double valA = ((struct Sale *)a)->value;
    double valB = ((struct Sale *)b)->value;
    // Return a positive, negative, or zero value based on comparison
    return (valA < valB) - (valA > valB);  // Equivalent to: valB - valA
}
