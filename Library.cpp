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
    "6: Exit program\n";
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

void Library::getBookInfo(const Book& book) const {
    string available;
    available = book.getAvailability() ? "Yes" : "No";
    cout << "No. " + to_string(book.getNum()) +
            "\nTitle: " + book.getTitle() +
            "\nAuthor: " + book.getAuthor() +
            "\nPages: " + to_string(book.getPublicationYear()) +
            "\nAvailable: " + available;
    if (book.getPurchasePrice()) {
        cout << "\nPurchase Price: " + to_string(*book.getPurchasePrice()) + "\n\n";
    } else {
        cout << "\nThat book is not available for purchase.\n\n";
    }
}

int Library::getLibSize() const {
    return(bookInventory.size());
}

void Library::checkOut(istream &ins, ostream &outs) {
    int id;
    outs << "Enter the No. of the book you wish to check out:\n";
    ins >> id;
    while (ins.fail()) {
        ins.clear();
        ins.ignore();
        outs << "Invalid input.\n";
        outs << "Enter the No. of the book you wish to check out:\n";
        ins >> id;
    }
    bool found = false;
    for (Book& b : bookInventory) {
        if (b.getNum() == id) {
            found = true;
            if (b.getAvailability()) {
                b.setAvailability(false);
                outs << "Checking out the following book: ";
                getBookInfo(b);
            } else {
                outs << "That book is already checked out.";
            }
        }
    }
    if (!found) {
        outs << "Could not find a book with that No.\n";
    }
}

void Library::checkIn(istream &ins, ostream &outs) {
    int id;
    outs << "Enter the No. of the book you are checking in:\n";
    ins >> id;
    while (ins.fail()) {
        ins.clear();
        ins.ignore();
        outs << "Invalid input.\n";
        outs << "Enter the No. of the book you are checking in:\n";
        ins >> id;
    }
    bool found = false;
    for (Book& b : bookInventory) {
        if (b.getNum() == id) {
            found = true;
            if (!b.getAvailability()) {
                b.setAvailability(true);
                outs << "Checking in the following book: ";
                getBookInfo(b);
            } else {
                outs << "That book is already checked in." << endl;
            }
        }
    }
    if (!found) {
        outs << "Could not find a book with that No." << endl;
    }
}

void Library::addBook(istream &ins, ostream &outs) {
    int num, year;
    string title, author;
    num = getLibSize() + 1;
    outs << "What is the title of the book?\n";
    ins.ignore();
    getline(ins, title);
    outs << "\n";
    outs << "What is the author of the book?\n";
    getline(ins, author);
    outs << "\n";
    outs << "What year was this book published?\n";
    while (!(cin >> year)) {
        cin.ignore();
        outs << "Invalid input. Please try again.\n";
        outs << "What year was this book published?\n";
    }
    Book newBook(num, title, author, year);
    bookInventory.emplace_back(newBook);
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

        books.emplace_back(Book(num, title, author, year));
    }
    fin.close();
}