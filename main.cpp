#include "Library.h"

int main() {
    vector<Book> initialBooks;
    cout << "Building library...\n";
    Library library(initialBooks);
    cout << "Library built.\n\n";
    cout << "Welcome to Landon Cayia's Library.\n";
    int choice;
    bool exit = false;
    while (!exit) {
        Library::displayMenu();
        cin >> choice;
        while (cin.fail() || (choice != 1 && choice != 2 && choice != 3 &&
                choice != 4 && choice != 5 && choice != 6 && choice != 7)) {
            cin.clear();
            cin.ignore();
            cout << "Invalid input. Please try again." << endl;
            Library::displayMenu();
            cin >> choice;
        }
        cin.ignore();
        switch (choice) {
            case 1:
                library.searchForBook(cin, cout);
                break;
            case 2:
                library.checkOut(cin, cout);
                break;
            case 3:
                library.checkIn(cin, cout);
                break;
            case 4:
                library.addBook(cin, cout);
                break;
            case 5:
                library.buyBook(cin, cout);
                break;
            case 6:
                library.setBookPrice(cin, cout);
                break;
            default:
                exit = true;
                break;
        }
    }
    return 0;
}