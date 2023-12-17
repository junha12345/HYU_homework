#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "bank_account.hpp"
#include "bank_account.cpp"
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
        break;
      case 'D':
		// TODO
        break;
      case 'P':
		// TODO
        break;
      case 'A':
		// TODO
        break;
      case 'Q':
		// TODO
        break;
      default:
        cerr<<"Undefined command"<<endl;
        exit(1);
    }
  }
}

