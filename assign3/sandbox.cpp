/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"
#include <iostream>

void sandbox() {
  // STUDENT TODO: Construct an instance of your class!
  BankAccount var{1000, "Jin An"};
  std::cout << "Balance: " << var.getBalance() << '\n';
  std::cout << "Interest: " << var.getInterest() << '\n';
  var.setBalance(10000);
  std::cout << "Balance: " << var.getBalance() << '\n';
  std::cout << "Interest: " << var.getInterest() << '\n';
}