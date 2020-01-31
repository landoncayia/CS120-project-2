#ifndef LC_PROJECT2_LIBRARY_H
#define LC_PROJECT2_LIBRARY_H
#include <algorithm>
#include <memory>
#include <iostream>
#include <optional>
#include <string>
#include <vector>

using namespace std;


// TODO: Implement optional stuff
// TODO: Implement smart pointers
// TODO: Implement addBook and buyBook

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
    // Requires: Book no., title, author, page count, and price (if applicable)
    // Modifies: Nothing
    // Effects: Creates a Book object
    Book(int num, string title, string author, int pages);
    Book(int num, string title, string author, int pages, double price);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value specified by the function
    int getNum() const;
    string getTitle() const;
    string getAuthor() const;
    int getPageCount() const;
    string getISBN() const;
    bool getAvailability() const;
    optional<string> getPurchasePrice() const;

    // Setters
    // Requires: The data that the field specified should be changed to
    // Modifies: The field(s) specified by the function
    // Effects: Modifies certain fields based on the function
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
    // Requires: Nothing or a vector of books to initialize the library with
    Library();
    Library(vector<Book> inv);

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Allows the user to search for a book by title or by author
    bool searchForBook();

    // Requires: A Book object
    // Modifies: Nothing
    // Effects: Displays a book's number, name, author, page count, and availability to the user
    void getBookInfo(Book book) const;

    // Requires: Nothing
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book out, making it not available
    void checkOut();

    // Requires: Nothing
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book in, making it available
    void checkIn();

    // Requires: TBD
    // Modifies: TBD
    // Effects: TBD
    void addBook();

    // Requires: TBD
    // Modifies: TBD
    // Effects: TBD
    void buyBook();
};

#endif //LC_PROJECT2_LIBRARY_H
