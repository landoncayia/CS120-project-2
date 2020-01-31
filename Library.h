#ifndef LC_PROJECT2_LIBRARY_H
#define LC_PROJECT2_LIBRARY_H
#include <memory>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;


// TODO: Implement optional stuff
// TODO: Implement smart pointers
// TODO: Implement functions

class Book {
private:
    int num;
    string title;
    string author;
    int pageCount;
    string isbn;
    bool isAvailable;
    optional<double> purchasePrice;

public:
    // Constructor
    Book(int num, string title, string author, int pages);
    Book(int num, string title, string author, int pages, double price);

    // Getters
    int getNum() const;
    string getTitle() const;
    string getAuthor() const;
    int getPageCount() const;
    string getISBN() const;
    bool getAvailability() const;
    optional<string> getPurchasePrice() const;

    // Setters
    void setBookInfo(string title, string author, int pages);
    void setISBN(string isbn);
    void setAvailability(bool status);
    void setPurchasePrice(double price);
};

class Library {
private:
    vector<Book> bookInventory;

public:
    // Constructor
    Library();
    Library(vector<Book> inv);

    bool searchForBook(); // By Name, Author, ISBN, or Page Count Range
    void getBookInfo(Book book) const;
    void checkOut();
    void checkIn();
    void addBook();
    void buyBook(Book book);
};

#endif //LC_PROJECT2_LIBRARY_H
