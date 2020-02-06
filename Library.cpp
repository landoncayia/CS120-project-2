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

optional<double> Book::getPurchasePrice() const {
    return purchasePrice;
}

void Book::setAvailability(bool status) {
    isAvailable = status;
}

void Book::setPurchasePrice(double price) {
    purchasePrice = price;
}

/************* Library implementation ******************/

Library::Library() {
    bookInventory = {};
}

Library::Library(vector<Book> inv) {
    BuildLibraryFromCSV("books.csv", inv);
    bookInventory = inv;
}

void Library::displayMenu() {
    cout <<
    endl <<
    "Enter your choice as an integer:\n" <<
    "1: Search for book\n" <<
    "2: Check a book out by ID\n" <<
    "3: Check a book in by ID\n" <<
    "4: Donate a book (add to library)\n" <<
    "5: Purchase a book by ID (if available to purchase)\n" <<
    "6: Set the price of a book (this would be an admin action in a regular program)\n" <<
    "7: Exit program\n";
}

int Library::getBookNum(istream &ins, ostream &outs) const {
    int id = -1;
    outs << "Enter the No. of the book:\n";
    ins >> id;
    if (ins.fail()) {
        ins.clear();
        ins.ignore();
        outs << "Invalid input.\n";
    } else {
        ins.ignore();
    }
    return id;
}

void Library::searchForBook(istream &ins, ostream &outs) {
    int choice = 0;
    outs << "Search by\n"
            "1) Title\n"
            "2) Author\n";
    ins >> choice;
    while (ins.fail() || (choice != 1 && choice != 2)) {
        ins.clear();
        ins.ignore();
        outs << "Invalid input.\n";
        outs << "Search by\n"
                "1) Title\n"
                "2) Author\n";
        ins >> choice;
    }
    bool found = false;
    switch (choice) {
        case 1: { // Search by Title
            string searchTerm;
            ins.ignore();
            outs << "Enter a book title: ";
            getline(ins, searchTerm);
            outs << endl;
            transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
            for (const Book& b : bookInventory) {
                string tempTitle = b.getTitle();
                transform(tempTitle.begin(), tempTitle.end(), tempTitle.begin(), ::tolower);
                if (tempTitle.find(searchTerm) != string::npos) {
                    found = true;
                    outs << "Found book.\n\n";
                    getBookInfo(b);
                }
            }
            if (!found) {
                outs << "Could not find any books with those search terms." << endl;
            }
            break;
        }
        case 2: { // Search by Author
            string searchTerm;
            ins.ignore();
            outs << "Enter a book author: ";
            getline(ins, searchTerm);
            outs << endl;
            transform(searchTerm.begin(), searchTerm.end(), searchTerm.begin(), ::tolower);
            for (const Book& b : bookInventory) {
                string tempAuthor = b.getAuthor();
                transform(tempAuthor.begin(), tempAuthor.end(), tempAuthor.begin(), ::tolower);
                if (tempAuthor.find(searchTerm) != string::npos) {
                    found = true;
                    outs << "Found book.\n\n";
                    getBookInfo(b);
                }
            }
            if (!found) {
                outs << "Could not find any books with those search terms." << endl;
            }
            break;
        }
        default: {
            outs << "There was a problem. Please try again." << endl;
        }
        break;
    }
}

void Library::getBookInfo(const Book& b) const {
    string available;
    available = b.getAvailability() ? "Yes" : "No";
    cout << "No. " + to_string(b.getNum()) +
            "\nTitle: " + b.getTitle() +
            "\nAuthor: " + b.getAuthor() +
            "\nPages: " + to_string(b.getPublicationYear()) +
            "\nAvailable: " + available;
    if (b.getPurchasePrice()) {
        printf("\nPurchase price: $%.2f\n\n", *b.getPurchasePrice());
    } else {
        cout << "\nThis book is not available for purchase.\n\n";
    }
}

int Library::getLibSize() const {
    return(bookInventory.size());
}

void Library::checkOut(istream &ins, ostream &outs) {
    int id = getBookNum(ins, outs);
    bool found = false;
    if (id != -1) {
        for (Book& b : bookInventory) {
            if (b.getNum() == id) {
                found = true;
                if (b.getAvailability()) {
                    b.setAvailability(false);
                    outs << "Checking out the following book:\n";
                    getBookInfo(b);
                } else {
                    outs << "This book is already checked out.\n";
                }
            }
        }
        if (!found) {
            outs << "Could not find a book with that No.\n";
        }
    }
}

void Library::checkIn(istream &ins, ostream &outs) {
    int id = getBookNum(ins, outs);
    bool found = false;
    if (id != -1) {
        for (Book& b : bookInventory) {
            if (b.getNum() == id) {
                found = true;
                if (!b.getAvailability()) {
                    b.setAvailability(true);
                    outs << "Checking in the following book:\n";
                    getBookInfo(b);
                } else {
                    outs << "This book is already checked in.\n" << endl;
                }
            }
        }
        if (!found) {
            outs << "Could not find a book with that No.\n" << endl;
        }
    }
}

void Library::addBook(istream &ins, ostream &outs) {
    int num, year;
    string title, author;
    num = getLibSize() + 1;
    outs << "What is the title of the book?\n";
    getline(ins, title);
    outs << "\n";
    outs << "What is the author of the book?\n";
    getline(ins, author);
    outs << "\n";
    outs << "What year was this book published?\n";
    ins >> year;
    if (ins.fail() || year < 0) {
        ins.clear();
        string junk;
        getline(ins, junk);

        outs << "Invalid input.\n";
    } else {
        ins.ignore();
        Book newBook(num, title, author, year);
        bookInventory.emplace_back(newBook);
    }
}

void Library::buyBook(istream &ins, ostream &outs) {
    int id = getBookNum(ins, outs);
    bool found = false;
    if (id != -1) {
        for (Book& b : bookInventory) {
            if (b.getNum() == id) {
                found = true;
                if (b.getPurchasePrice()) {
                    printf("\nPurchasing book for $%.2f\n\n", *b.getPurchasePrice());
                    bookInventory.erase(bookInventory.begin() + id - 1);
                } else {
                    outs << "\nThis book is not available for purchase.\n\n";
                }
            }
        }
        if (!found) {
            outs << "Could not find a book with that No." << endl;
        }
    }
}

void Library::setBookPrice(istream &ins, ostream &outs) {
    int id = getBookNum(ins, outs);
    bool found = false;
    if (id != -1) {
        for (Book& b : bookInventory) {
            if (b.getNum() == id) {
                found = true;
                double price;
                outs << "Enter the price:\n";
                ins >> price;
                if (ins.fail() || price < 0) {
                    ins.clear();
                    ins.ignore();
                    outs << "Invalid input.\n";
                } else {
                    b.setPurchasePrice(price);
                }
            }
        }
        if (!found) {
            outs << "Could not find a book with that No." << endl;
        }
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

        auto bookFromCSV = make_unique<Book>(num, title, author, year);

        books.emplace_back(*bookFromCSV);
    }
    fin.close();
}