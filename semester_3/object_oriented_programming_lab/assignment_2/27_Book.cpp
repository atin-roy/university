#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Book {
  string isbn;
  string title;
  string author;
  float price;

public:
  Book() : isbn(""), title(""), author(""), price(0.0) {}

  Book(string isbn, string title, string author, float price)
      : isbn(isbn), title(title), author(author), price(price){};

  Book(const Book &other)
      : isbn(other.isbn), title(other.title), author(other.author),
        price(other.price) {}
  std::string getISBN() const { return isbn; }

  std::string getTitle() const { return title; }

  std::string getAuthor() const { return author; }

  float getPrice() const { return price; }

  void setISBN(const std::string &newIsbn) { isbn = newIsbn; }

  void setTitle(const std::string &newTitle) { title = newTitle; }

  void setAuthor(const std::string &newAuthor) { author = newAuthor; }

  void setPrice(float newPrice) { price = newPrice; }

  string randomISBN() {
    string opts = "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string isbn = "";

    for (int i = 0; i < 10; i++) {
      isbn += opts[rand() % 36];
    }
    return isbn;
  }

  string randomBookName() {
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
};

class BookStore {
  vector<Book> bookList;
  int numberOfBooks;

public:
  BookStore(int n = 0) : numberOfBooks(n) {}

  BookStore(const BookStore &other)
      : bookList(other.getBookList()), numberOfBooks(other.getNumberOfBooks()) {
  }

  void addBook(const Book &book) { bookList.emplace_back(book); }

  void setBookList(const std::vector<Book> &newBookList) {
    bookList = newBookList;
    numberOfBooks = bookList.size();
  }

  std::vector<Book> getBookList() const { return bookList; }

  void setNumberOfBooks(int newNumberOfBooks) {
    if (newNumberOfBooks >= 0) {
      numberOfBooks = newNumberOfBooks;
    } else {
      std::cerr << "Number of books cannot be negative." << std::endl;
    }
  }

  int getNumberOfBooks() const { return numberOfBooks; }

  vector<string> books() const {
    unordered_set<string> set;
    for (auto &x : bookList) {
      set.insert(x.getISBN());
    }

    vector<string> isbns;
    for (auto x : set) {
      isbns.push_back(x);
    }

    return isbns;
  }

  int noOfCopies(string isbn) {
    int copies = 0;
    for (auto x : bookList) {
      if (x.getISBN() == isbn) {
        copies++;
      }
    }

    return copies;
  }

  float totalPrice() {
    float price = 0.0;

    for (auto x : bookList) {
      price += x.getPrice();
    }

    return price;
  }

  void printBookCopies() const {
    unordered_map<string, int> copiesMap;
    unordered_map<string, string> titleMap;

    for (const auto &x : bookList) {
      copiesMap[x.getISBN()]++;
      titleMap[x.getISBN()] = x.getTitle();
    }

    for (const auto &entry : copiesMap) {
      cout << "Title: " << titleMap[entry.first]
           << ", Number of Copies: " << entry.second << endl;
    }
  }
};
int main() {
  BookStore store;

  store.addBook(Book("1234567890", "The C++ Programming Language",
                     "Bjarne Stroustrup", 1550.0));
  store.addBook(Book("1234567890", "The C++ Programming Language",
                     "Bjarne Stroustrup", 1550.0));
  store.addBook(Book("0987654321", "Effective C++", "Scott Meyers", 2045.0));
  store.addBook(Book("0987654321", "Effective C++", "Scott Meyers", 2045.0));
  store.addBook(Book("0987654321", "Effective C++", "Scott Meyers", 2045.0));

  store.printBookCopies();

  return 0;
}
