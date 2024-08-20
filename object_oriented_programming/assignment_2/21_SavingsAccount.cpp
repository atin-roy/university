/*21. Create a simple class SavingsAccount for savings account used in banks as
follows: Each SavingsAccount object should have three data members to store the
account holder’s name, unique account number and balance of the account. Assume
account numbers are integers and generated sequentially. Note that once an
account number is allocated to an account, it does not change during the entire
operational period of the account. The bank also specifies a rate of interest
for all savings accounts created. Write relevant methods (such as withdraw,
deposit etc.) in the class. The bank restricts that each account must have a
minimum balance of Rs. 1000. Now create 100 SavingsAccount objects specifying
balance at random ranging from Rs. 1,000 to 1,00,000. Now, calculate the
interest for one year to be paid to each account and deposit the interest to the
corresponding balance. Also find out total amount of interest to be paid to all
accounts in one year.
*/

// todo name, uid(int -> sequentially), balance.
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
  static constexpr double rate = 4.0; // Interest rate

public:
  // Constructor to initialize a SavingsAccount object
  SavingsAccount(string name, double balance)
      : name(name), balance(balance), uid(++sequence) {}

  // Method to withdraw money from the account
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

  // Method to deposit money into the account
  void deposit(double amount) {
    balance += amount;
    cout << "Deposit of Rs." << amount << " successful!" << endl;
  }

  // Method to calculate interest for the account
  double calculateInterest() const {
    return (rate / 100) * balance; // Rate is assumed to be in percentage
  }

  // Method to display account details
  void display() const {
    cout << "Account " << uid << ":" << endl;
    cout << "Name - " << name << endl;
    cout << "Balance - " << balance << endl;
    cout << endl;
  }

  // Static method to get the number of accounts
  static int numberOfAccounts() { return sequence; }
};

// Initialize the static sequence number
int SavingsAccount::sequence = 0;

// Function to generate a random name for the account holder
string randomName() {
  string capital = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
  string lower = "abcdefghijklmnopqrstuvwxyz";
  string name = "";

  int length = rand() % 10 + 1; // Random length between 1 and 10
  name += capital[rand() % 26]; // First letter capitalized

  for (int i = 1; i < length; i++) {
    name += lower[rand() % 26]; // Subsequent letters in lowercase
  }
  return name;
}

// Function to create a vector of SavingsAccount objects
vector<SavingsAccount> createAccounts(int num) {
  vector<SavingsAccount> accounts;
  for (int i = 0; i < num; i++) {
    accounts.emplace_back(randomName(),
                          rand() % 90001 +
                              1000); // Random balance between 1000 and 100000
  }
  return accounts;
}

// Function to calculate and deposit interest for all accounts
double depositInterest(vector<SavingsAccount> &accounts) {
  double totalInterest = 0;
  for (auto &account : accounts) {
    double interest = account.calculateInterest();
    account.deposit(interest);
    totalInterest += interest;
  }
  return totalInterest;
}

// Function to display all accounts
void displayAccounts(const vector<SavingsAccount> &accounts) {
  for (const auto &account : accounts) {
    account.display();
  }
}

int main() {
  srand(static_cast<unsigned>(time(0))); // Seed the random number generator

  // Create 100 SavingsAccount objects
  vector<SavingsAccount> accounts = createAccounts(10);

  // Display information of all accounts before depositing interest
  cout << "Information of all accounts before depositing interest:\n";
  displayAccounts(accounts);

  // Calculate and deposit interest for one year
  double totalInterest = depositInterest(accounts);

  // Display information of all accounts after depositing interest
  cout << "\nInformation of all accounts after depositing interest:\n";
  displayAccounts(accounts);

  // Display the total interest deposited
  cout << "Total Interest Deposited: Rs. " << totalInterest << endl;

  return 0;
}
