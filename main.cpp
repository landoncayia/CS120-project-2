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
        while ((!(cin >> choice)) || (choice != 1 && choice != 2 && choice != 3 &&
                choice != 4 && choice != 5 && choice != 6)) {
            cin.ignore();
            cout << "Invalid input. Please try again." << endl;
            Library::displayMenu();
        }
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
                //library.addBook();
                break;
            case 5:
                //library.buyBook();
                break;
            case 6:
                exit = true;
                break;
            default:
                cout << "Something went wrong." << endl;
                break;
        }
    }
    return 0;
}