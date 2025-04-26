#include <string>

class BankAccount {
public:
    using String = std::string;
    BankAccount(size_t balance, String name);
    BankAccount();
    ~BankAccount();

    size_t getBalance() const;
    void setBalance(size_t balance);

    size_t getInterest() const;
private:
    size_t _balance;
    String _name;
    size_t calInterest() const;
};