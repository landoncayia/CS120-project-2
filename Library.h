#ifndef LC_PROJECT2_LIBRARY_H
#define LC_PROJECT2_LIBRARY_H
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <memory>
#include <optional>
#include <string>
#include <vector>

using namespace std;

// TODO: Add a smart pointer (check lecture slides from 2/4)
// TODO: Implement removing a book from the vector once it is bought
// TODO: Add some more test cases (specifically for bad input)

class Book {
private:
    int num;
    string title;
    string author;
    int publicationYear;
    bool isAvailable;
    optional<double> purchasePrice;

public:
    // Constructor
    // Requires: Book no., title, author, page count, and price (if applicable)
    // Modifies: Nothing
    // Effects: Creates a Book object
    Book(int num, string title, string author, int year);
    Book(int num, string title, string author, int year, double price);

    // Getters
    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the value specified by the function
    int getNum() const;
    string getTitle() const;
    string getAuthor() const;
    int getPublicationYear() const;
    bool getAvailability() const;
    optional<double> getPurchasePrice() const;

    // Setters
    // Requires: The data that the field specified should be changed to
    // Modifies: The field(s) specified by the function
    // Effects: Modifies certain fields based on the function
    void setAvailability(bool status);
    void setPurchasePrice(double price);
};

class Library {
private:
    vector<Book> bookInventory;

public:
    // Constructor
    // Requires: Nothing or a vector of books to initialize the library with
    // Modifies: Nothing
    // Effects: Creates a Library object that has books, calls BuildLibraryFromCSV if provided with a vector of books
    //          and fills with the contents of `books.csv`
    Library();
    explicit Library(vector<Book> inv);

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Displays the main menu for the program
    static void displayMenu();

    // Requires: istream and ostream objects
    // Modifies: Nothing
    // Effects: Gets the No. of a book from user input
    int getBookNum(istream &ins, ostream &outs) const;

    // Requires: istream and ostream objects
    // Modifies: Nothing
    // Effects: Allows the user to search for a book by title or by author
    void searchForBook(istream &ins, ostream &outs);

    // Requires: A Book object
    // Modifies: Nothing
    // Effects: Displays a book's number, name, author, page count, and availability to the user
    void getBookInfo(const Book& b) const;

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the size of (number of books in) the library
    int getLibSize() const;

    // Requires: istream and ostream objects
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book out, making it not available
    void checkOut(istream &ins, ostream &outs);

    // Requires: istream and ostream objects
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book in, making it available
    void checkIn(istream &ins, ostream &outs);

    // Requires: istream and ostream objects
    // Modifies: bookInventory vector
    // Effects: Adds a book to the library vector
    void addBook(istream &ins, ostream &outs);

    // Requires: istream and ostream objects
    // Modifies: The bookInventory vector
    // Effects: Purchases a book if it is purchasable, removing it from the Library
    void buyBook(istream &ins, ostream &outs);

    // Requires: istream and ostream objects
    // Modifies: The purchasePrice field of a book
    // Effects: Sets the price of a Book object in the Library
    void setBookPrice(istream &ins, ostream &outs);

    // Requires: Filename and empty book vector reference
    // Modifies: The book vector that is passed in, the Library's bookInventory field
    // Effects: Builds a library using the book csv file
    static void BuildLibraryFromCSV(const string& filename, vector<Book> &books);
};

#endif //LC_PROJECT2_LIBRARY_H
