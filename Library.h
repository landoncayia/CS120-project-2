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


// TODO: Implement optional stuff
// TODO: Implement smart pointers
// TODO: Implement addBook and buyBook

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

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Allows the user to search for a book by title or by author
    void searchForBook(istream &ins, ostream &outs);

    // Requires: A Book object
    // Modifies: Nothing
    // Effects: Displays a book's number, name, author, page count, and availability to the user
    void getBookInfo(const Book& book) const;

    // Requires: Nothing
    // Modifies: Nothing
    // Effects: Returns the size of (number of books in) the library
    int getLibSize() const;

    // Requires: Nothing
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book out, making it not available
    void checkOut(istream &ins, ostream &outs);

    // Requires: Nothing
    // Modifies: isAvailable field
    // Effects: Allows the user to check a book in, making it available
    void checkIn(istream &ins, ostream &outs);

    // Requires: TBD
    // Modifies: TBD
    // Effects: TBD
    void addBook(istream &ins, ostream &outs);

    // Requires: TBD
    // Modifies: TBD
    // Effects: TBD
    void buyBook();

    // Requires: Filename and empty book vector reference
    // Modifies: The book vector that is passed in, the Library's bookInventory field
    // Effects: Builds a library using the book csv file
    static void BuildLibraryFromCSV(const string& filename, vector<Book> &books);
};

#endif //LC_PROJECT2_LIBRARY_H
