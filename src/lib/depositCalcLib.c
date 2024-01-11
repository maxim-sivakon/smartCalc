#include "depositCalcLib.h"

void calculateDeposit(double depositAmount, int term, double interestRate, double taxRate, int paymentsFrequency,
                      int interestCapitalization, change replenishmentsWithdrawals[], int changesNum,
                      int startYear, int startMonth, int startDay, double *profitResult, double *taxResult, double *totalResult) {
    
    date currentDate = {startDay, startMonth, startYear};
    double totalAmount = depositAmount;
    double rate = interestRate / 100;
    double totalProfit = 0;
    double currentProfit = 0;

    for (int i = 1; i <= term; i++) {
        int daysInTerm = monthDays(currentDate);

        for (int j = 1; j <= daysInTerm; j++) {
            for (int k = 0; k < changesNum; k++) {
                if (replenishmentsWithdrawals[k].changeDate.day == currentDate.day &&
                    replenishmentsWithdrawals[k].changeDate.month == currentDate.month &&
                    replenishmentsWithdrawals[k].changeDate.year == currentDate.year) {
                    totalAmount += replenishmentsWithdrawals[k].changeAmount;
                }
            }

            currentProfit += totalAmount * (1 + rate / yearDays(currentDate)) - totalAmount;

            if (paymentsFrequency == 2) {
                endOfPeriod(interestCapitalization, &totalAmount, &totalProfit, &currentProfit);
            }

            currentDate.day += 1;
            normalizeDate(&currentDate);
        }

        if (paymentsFrequency == 0) {
            endOfPeriod(interestCapitalization, &totalAmount, &totalProfit, &currentProfit);
        }

        if (paymentsFrequency == 3 && (i % 12 == 0 || i == term)) {
            endOfPeriod(interestCapitalization, &totalAmount, &totalProfit, &currentProfit);
        }
    }

    if (paymentsFrequency == 1) {
        endOfPeriod(interestCapitalization, &totalAmount, &totalProfit, &currentProfit);
    }

    *profitResult = totalProfit;
    *totalResult = totalAmount;
    *taxResult = taxRate / 100 * totalProfit;
}

int yearDays(date thisDate) {
    int days = 365;
    if ((thisDate.year % 4 == 0 && thisDate.year % 100 != 0) ||
            thisDate.year % 400) {
        days = 366;
    }
    return days;
}

int monthDays(date thisDate) {
    char monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int days = monthDays[thisDate.month - 1];
    if (yearDays(thisDate) == 366 && thisDate.month == 2) {
        days += 1;
    }

    return days;
}

void normalizeDate(date *thisDate) {
    if (thisDate->day > monthDays(*thisDate)) {
        thisDate->day = 1;
        thisDate->month += 1;
    }
    if (thisDate->month > 12) {
        thisDate->month = 1;
        thisDate->year += 1;
    }
}

void endOfPeriod(int interestCapitalization, double *totalAmount, double *totalProfit, double *currentProfit) {
    if (interestCapitalization) {
        *totalAmount += *currentProfit;
    }

    *totalProfit += *currentProfit;
    *currentProfit = 0;
}
