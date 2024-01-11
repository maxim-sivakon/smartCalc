#include "creditCalcLib.h"

double calculateAnnuityPayment(double totalLoan, int term, double interestRate) {
    double monthlyRate = interestRate / 12 / 100;
    double monthlyPayment = totalLoan * monthlyRate *
                             pow((1 + monthlyRate), term) /
                             (pow((1 + monthlyRate), term) - 1);
    return monthlyPayment;
}

double calculateDifferentiatedPayment(double totalLoan, int term, double interestRate, int month) {
    double loanRemain = totalLoan - (totalLoan / term) * (month - 1);
    double monthlyRate = interestRate / 12 / 100;

    return totalLoan / term + loanRemain * monthlyRate;
}

double calculateAnnuityTotalPayment(double totalLoan, int term, double interestRate) {
    double monthlyPayment = calculateAnnuityPayment(totalLoan, term, interestRate);
    return monthlyPayment * term;
}

double calculateDifferentiatedTotalPayment(double totalLoan, int term, double interestRate) {
    double totalPayment = 0.0;
    for (int i = 1; i <= term; i++) {
        totalPayment += calculateDifferentiatedPayment(totalLoan, term, interestRate, i);
    }

    return totalPayment;
}

double calculateLoanOverpayment(double totalLoan, double totalPayment) {
    return totalPayment - totalLoan;
}
