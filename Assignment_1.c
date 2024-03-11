#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Report {
    char month[20];
    double sales;
};

double calcAvg(double sales[], int numM) {
    double sum=0, avg;
    int i;
    for(i=0; i<numM; i++) {
        sum += sales[i];
    }
    avg = sum/numM;
    return avg;
}

void sortReport(struct Report data[], int numM) {
    int i, j;
    struct Report temp;
    for(i=0; i<numM-1; i++) {
        for (j=i+1; j<numM; j++) {
            if (data[i].sales < data[j].sales) {
                temp = data[i];
                data[i] = data[j];
                data[j] = temp;
            }
        }
    }
}

void main() {
    double sales[12], min, max, avg, movingAvg;
    struct Report report[12];
    int i, j, maxM, minM;
    const char *months[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    for(i=0; i<12; i++) {
        scanf("%lf", &sales[i]);
        strcpy(report[i].month, months[i]);
        report[i].sales = sales[i];
    }
    printf("Monthly sales report fot 2022:-\n");
    printf("\nMonth \t Sales\n");
    for(i=0; i<12; i++) {
        printf("%s $%.2lf\n", report[i].month, report[i].sales);
    }
    min = sales[0];
    max = sales[0];
    avg = calcAvg(sales, 12);
    for(i=1; i<12; i++) {
        if(sales[i]<min) {
            min = sales[i];
            minM = i;
        }
        if(sales[i]>max) {
            max = sales[i];
            maxM = i;
        }
    }
    sortReport(report, 12);
    printf("\nSales Summary:-\n");
    printf("\nMinimum sales: $%.2lf (%s)\n", min, months[minM]);
    printf("Maximum sales: $%.2lf (%s)\n", max, months[maxM]);
    printf("Average sales: $%.2lf\n", avg);

    printf("\nSix-Month Moving Average Report:\n");
    for(i=0; i<6; i++) {
        movingAvg = 0;
        for(j=0; j<6; j++) {
            movingAvg += sales[i+j];
        }
        movingAvg /= 6;
        printf("%s-%s: $%.2lf\n", months[i], months[i+5], movingAvg);
    }
    printf("\nSales Report (Highest to Lowest):\n");
    for(i=0; i<12; i++) {
        printf("%s $%.2lf\n", report[i].month, report[i].sales);
    }
}