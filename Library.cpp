#include "Library.h"

/************* Book implementation ******************/

Book::Book(int num, string title, string author, int year) {
    this->num = num;
    this->title = title;
    this->author = author;
    publicationYear = year;
    isAvailable = true;
    purchasePrice = nullopt;
}

Book::Book(int num, string title, string author, int year, double price) {
    this->num = num;
    this->title = title;
    this->author = author;
    publicationYear = year;
    isAvailable = true;
    purchasePrice = price;
}

int Book::getNum() const {
    return num;
}

string Book::getTitle() const {
    return title;
}

string Book::getAuthor() const {
    return author;
}

int Book::getPublicationYear() const {
    return publicationYear;
}

bool Book::getAvailability() const {
    return isAvailable;
}

void Book::setBookInfo(string title, string author, int year) {
    this->title = title;
    this->author = author;
    publicationYear = year;
}

void Book::setAvailability(bool status) {
    isAvailable = status;
}

/************* Library implementation ******************/

Library::Library() {
    bookInventory = {};
}

Library::Library(vector<Book> inv) {
    BuildLibraryFromCSV("books.csv", inv);
    bookInventory = inv;
}

bool Library::searchForBook(ifstream &cin) {
    int choice = 0;
    cout << "Search by\n"
            "1) Title\n"
            "2) Author\n";
    while (!(cin >> choice) || (choice != 1 && choice != 2 && choice != 3)) {
        cout << "Invalid input." << endl;
        cout << "Search by\n"
                "1) Title\n"
                "2) Author\n";
    }
    bool found = false;
    switch (choice) {
        case 1: { // Search by Title
            string searchTerm;
            cin.ignore();
            cout << "Enter a book title: ";
            getline(cin, searchTerm);
            transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
            for (Book b : bookInventory) {
                string tempTitle = b.getTitle();
                transform(tempTitle.begin(), tempTitle.end(), tempTitle.begin(), ::tolower);
                if (tempTitle == searchTerm) {
                    found = true;
                    cout << "Found book.\n\n";
                    getBookInfo(b);
                }
            }
            if (!found) {
                cout << "Could not find any books with those search terms." << endl;
            }
            return found;
        }
        case 2: { // Search by Author
            string searchTerm;
            cin.ignore();
            cout << "Enter a book author: ";
            getline(cin, searchTerm);
            transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
            for (const Book& b : bookInventory) {
                string tempAuthor = b.getAuthor();
                transform(tempAuthor.begin(), tempAuthor.end(), tempAuthor.begin(), ::tolower);
                if (tempAuthor == searchTerm) {
                    found = true;
                    cout << "Found book.\n\n";
                    getBookInfo(b);
                }
            }
            if (!found) {
                cout << "Could not find any books with those search terms." << endl;
            }
            return found;
        }
        default: {
            cout << "There was a problem. Please try again." << endl;
            return found;
        }
    }
}

void Library::getBookInfo(const Book& book) const {
    cout << "No. " + to_string(book.getNum()) +
            "\nTitle: " + book.getTitle() +
            "\nAuthor: " + book.getAuthor() +
            "\nPages: " + to_string(book.getPublicationYear()) +
            "\nAvailability: " + to_string(book.getAvailability())
         << endl;
}

void Library::checkOut(ifstream &cin) {
    int id;
    cout << "Enter the No. of the book you wish to check out: ";
    while (!(cin >> id)) {
        cout << "Invalid input." << endl;
        cout << "Enter the No. of the book you wish to check out: ";
    }
    bool found = false;
    for (Book b : bookInventory) {
        if (b.getNum() == id) {
            found = true;
            cout << "Checking out the following book: ";
            getBookInfo(b);
            b.setAvailability(false);
        }
    }
    if (!found) {
        cout << "Could not find a book with that No." << endl;
    }
}

int Library::getLibSize() const {
    return(bookInventory.size());
}

void Library::checkIn(ifstream &cin) {
    int id;
    cout << "Enter the No. of the book you are checking in: ";
    while (!(cin >> id)) {
        cout << "Invalid input." << endl;
        cout << "Enter the No. of the book you are checking in: ";
    }
    bool found = false;
    for (Book b : bookInventory) {
        if (b.getNum() == id) {
            found = true;
            cout << "Checking in the following book: ";
            getBookInfo(b);
            b.setAvailability(true);
        }
    }
    if (!found) {
        cout << "Could not find a book with that No." << endl;
    }
}

void Library::BuildLibraryFromCSV(const string& filename, vector<Book> &books) {
    ifstream fin;
    fin.open("../" + filename);
    if (fin) {
        string junk;
        getline(fin, junk);
    }
    while (fin && fin.peek() != EOF) {
        int num, year;
        string title, author, junk;
        char comma;

        fin >> num;
        fin >> comma;

        getline(fin, title, ',');

        getline(fin, author, ',');

        fin >> year;

        getline(fin, junk);

        books.emplace_back(Book(num, title, author, year)); // TODO: Add price somehow once you learn optionals?
    }
    fin.close();
}