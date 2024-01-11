#ifdef __cplusplus
extern "C" {
#endif

#include <math.h>

#ifndef CREDITСALC_H
#define CREDITСALC_H

double calculateAnnuityPayment(double totalLoan, int term, double interestRate);

double calculateDifferentiatedPayment(double totalLoan, int term, double interestRate, int month);

double calculateAnnuityTotalPayment(double totalLoan, int term, double interestRate);

double calculateDifferentiatedTotalPayment(double totalLoan, int term, double interestRate);

double calculateLoanOverpayment(double totalLoan, double totalPayment);

#endif // CREDITСALC_H

#ifdef __cplusplus
}
#endif
