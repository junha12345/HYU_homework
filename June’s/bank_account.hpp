#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <cmath>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
public:
    BankAccount(const string& name, string& type, unsigned int balance, double interest_rate) : name_(name),balance_(balance), interest_rate_(interest_rate){};
    virtual ~BankAccount() {};

    // Compute simple interest rate
    virtual unsigned int compute_expected_balance(unsigned int n_years_later) const {
        return balance_ * (1 + interest_rate_ * n_years_later);
    }
    virtual const char* type() const { return "checking"; }
    const unsigned int& balance() const { return balance_; }
    const string& name() const { return name_; }
    const double& interest_rate() const { return interest_rate_; }

protected:
    string name_;
    unsigned int balance_;
    double interest_rate_;
};

class SavingsAccount : public BankAccount {
public:
    SavingsAccount(const string& name, string& type, int balance, double interest_rate):BankAccount(name,type,balance,interest_rate) {};
    virtual ~SavingsAccount() {};

    virtual const char* type() const { return "savings"; }
    // Compute compound interest rate
    virtual unsigned int compute_expected_balance(unsigned int n_years_later) const {
        return balance_ * pow(1 + interest_rate_, n_years_later);
    }
};

#endif