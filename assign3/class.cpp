#include "class.h"

BankAccount::BankAccount(size_t balance, String name) {
    _balance = balance;
    _name = name;
}

BankAccount::BankAccount() {
    _balance = 0;
    _name = "None";
}

BankAccount::~BankAccount() {
}

size_t BankAccount::getBalance() const{
    return _balance;
}

void BankAccount::setBalance(size_t balance) {
    _balance = balance;
}

size_t BankAccount::calInterest() const{
    return _balance / 10;
}

size_t BankAccount::getInterest() const{
    return this->calInterest();
}