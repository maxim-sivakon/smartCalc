#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>
#include <stdio.h>

#ifndef DEPOSITСALC_H
#define DEPOSITСALC_H

typedef struct {
    int day;
    int month;
    int year;
} date;

typedef struct {
    double changeAmount;
    date changeDate;
} change;

void calculateDeposit(double depositAmount, int term, double interestRate, double taxRate, int paymentsFrequency, int interestCapitalization,
                       change replenishmentsWithdrawals[], int changesNum, int startYear, int startMonth, int startDay,
                       double *profitResult, double *taxResult, double *totalResult);

int yearDays(date thisDate);

int monthDays(date thisDate);

void normalizeDate(date *thisDate);

void endOfPeriod(int interestCapitalization, double *totalAmount, double *totalProfit, double *currentProfit);

#endif // DEPOSITСALC_H

#ifdef __cplusplus
}
#endif
