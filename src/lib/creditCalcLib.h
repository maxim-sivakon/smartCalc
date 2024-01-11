#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#ifndef CREDITCALC_H
#define CREDITCALC_H

double calculateAnnuityPayment(double totalLoan, int term, double interestRate);

double calculateDifferentiatedPayment(double totalLoan, int term, double interestRate, int month);

double calculateAnnuityTotalPayment(double totalLoan, int term, double interestRate);

double calculateDifferentiatedTotalPayment(double totalLoan, int term, double interestRate);

double calculateLoanOverpayment(double totalLoan, double totalPayment);

#endif // CREDITCALC_H

#ifdef __cplusplus
}
#endif
