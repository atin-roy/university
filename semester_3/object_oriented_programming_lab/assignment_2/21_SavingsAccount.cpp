#include <cmath>
#include <ctime>
#include <iostream>
#include <vector>

using namespace std;

class SavingsAccount {
private:
  static int sequence;
  string name;
  const int uid;
  double balance;
  static constexpr double rate = 4.0;

public:
  SavingsAccount(string name, double balance)
      : name(name), balance(balance), uid(++sequence) {}

  void withdraw(double amount) {
    if (amount > balance) {
      cout << "Insufficient Balance!" << endl;
    } else if (balance - amount < 1000) {
      cout << "Account must have a minimum balance of Rs. 1000!" << endl;
    } else {
      balance -= amount;
      cout << "Withdrawal of Rs." << amount << " successful!" << endl;
    }
  }

  void deposit(double amount) {
    balance += amount;
    cout << "Deposit of Rs." << amount << " successful!" << endl;
  }

  double calculateInterest() const { return (rate / 100) * balance; }

  void display() const {
    cout << "Account " << uid << ":" << endl;
    cout << "Name - " << name << endl;
    cout << "Balance - " << balance << endl;
    cout << endl;
  }

  static int numberOfAccounts() { return sequence; }
};

int SavingsAccount::sequence = 0;

string randomName() {
  string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  string name = "";

  int length = rand() % 10 + 1;
  name += capital[rand() % 26];
  for (int i = 1; i < length; i++) {
    name += lower[rand() % 26];
  }
  return name;
}

vector<SavingsAccount> createAccounts(int num) {
  vector<SavingsAccount> accounts;
  for (int i = 0; i < num; i++) {
    accounts.emplace_back(randomName(), rand() % 90001 + 1000);
  }
  return accounts;
}

double depositInterest(vector<SavingsAccount> &accounts) {
  double totalInterest = 0;
  for (auto &account : accounts) {
    double interest = account.calculateInterest();
    account.deposit(interest);
    totalInterest += interest;
  }
  return totalInterest;
}

void displayAccounts(const vector<SavingsAccount> &accounts) {
  for (const auto &account : accounts) {
    account.display();
  }
}

int main() {
  srand(static_cast<unsigned>(time(0)));
  vector<SavingsAccount> accounts = createAccounts(10);

  cout << "Information of all accounts before depositing interest:\n";
  displayAccounts(accounts);

  double totalInterest = depositInterest(accounts);

  cout << "\nInformation of all accounts after depositing interest:\n";
  displayAccounts(accounts);

  cout << "Total Interest Deposited: Rs. " << totalInterest << endl;

  return 0;
}
