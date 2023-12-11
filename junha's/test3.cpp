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
    vector<BankAccount*> accounts; // 포인터로 저장해서 가볍게, 대신 iterator 필수
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
            // name, type, amount, interest_rate : create account
            // TODO
            int amount;
            double value;
            iss >> type >> name >> amount >> value;
            cout << type << " " << name << " " << amount << " " << value << endl;
            accounts.push_back(new BankAccount(type, name, amount, value));
            break;
        case 'D':
            // name, delete the account whose account name is name
            // TODO
            break;
        case 'P':
            // print the name, amount, and interest rate of every current account as standard
            // TODO
            break;
        case 'A':
            // <num_years> print after yearse
            // TODO
            break;
        case 'Q':
            // quit a program
            // TODO
            exit(1);
            break;
        default:
            cerr << "Undefined command" << endl;
            exit(1);
        }
    }
}

