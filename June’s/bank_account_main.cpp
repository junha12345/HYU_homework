#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "bank_account.hpp"
using namespace std;

int main(void) {
    string command;
    vector<BankAccount*> accounts;
    vector<BankAccount*>::iterator it;
    bool quitEntered = false;
    while (!quitEntered && getline(cin, command)) {
        BankAccount* a;
        string name, type, file_name;
        unsigned int balance;
        double interest_rate;
        vector<BankAccount*>::iterator last;
        int n_years_later;
        char op = command[0];
        istringstream iss(command.substr(1));
        switch (op) {
        case 'C':
            // TODO
            iss >> name >> type >> balance >> interest_rate;
            if (type == "checking") {
                a = new BankAccount(name, type, balance, interest_rate);
            }
            else if (type == "savings") {
                a = new SavingsAccount(name, type, balance, interest_rate);
            }
            accounts.push_back(a);
            break;
        case 'D':
            // TODO
            iss >> name;
            for (BankAccount* acc : accounts) {
                if (acc->name() == name) {
                        delete acc;
                    }
            }
            break;
        case 'P':
            // TODO
            for (BankAccount* acc : accounts) {
                cout << acc->name() << "      " << acc->type() << "      " << acc->balance() << "      " << acc->interest_rate() << endl;
            }
            break;
        case 'A':
            // TODO
            iss >> n_years_later;
            for (BankAccount* acc : accounts) {
                unsigned int expected_balance = acc->compute_expected_balance(n_years_later);
                cout << acc->name() << "      " << acc->type()
                    << "      " << expected_balance << "      " << acc->interest_rate() << endl;
            }
            break;
        case 'Q':
            // TODO
            quitEntered = true;
            break;
        default:
            cerr << "Undefined command" << endl;
            exit(1);
        }
    }
    for (BankAccount* acc : accounts) {
        delete acc;
    }
    accounts.clear();
}


