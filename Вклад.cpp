#include <iostream>

class Deposit {
private:
    double interestRate;
    int term;
    bool canDepositWithdraw;

public:
    Deposit(double rate, int t, bool canDW) : interestRate(rate), term(t), canDepositWithdraw(canDW) {}

    void deposit(double amount) {
        if (canDepositWithdraw) {
            std::cout << "Внести " << amount << " рублей." << std::endl;
        }
        else {
            std::cout << "Невозможно внести деньги на этот счет." << std::endl;
        }
    }

    void withdraw(double amount) {
        if (canDepositWithdraw) {
            std::cout << "Снять " << amount << " рублей." << std::endl;
        }
        else {
            std::cout << "Невозможно вывести деньги с этого счета." << std::endl;
        }
    }

    double calculateIncome() {
        return 0.0; // Implement income calculation logic here
    }

    friend std::ostream& operator<<(std::ostream& os, const Deposit& deposit) {
        os << "Процентная ставка: " << deposit.interestRate << "%" << std::endl;
        os << "Срок: " << deposit.term << " года" << std::endl;
        os << "Ввод/вывод средств: " << (deposit.canDepositWithdraw ? "Допустим" : "Недопустим") << std::endl;
        return os;
    }
};

int main() {
    setlocale(LC_ALL, "ru");
    Deposit deposit(5.0, 3, true);

    std::cout << deposit;

    deposit.deposit(100);
    deposit.withdraw(50);

    return 0;
}
