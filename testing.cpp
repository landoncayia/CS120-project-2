#include "Library.h"

void testSearchForBook(ifstream &fin, Library &testLib);
void testCheckInCheckOut(ifstream &fin, Library &testLib);

/*
 * In order to test, functions in 'Library.h' and 'Library.cpp' must be modified to accept ifstream objects. This is
 * done to simulate potential user input from a .txt file in the Input-For-Testing folder. The testing part of this
 * program CANNOT be run if the functions are not modified to accept ifstream objects.
 */

int main() {
    // Should create an empty vector
    cout << "Creating empty Book vector..." << endl;
    vector<Book> books;
    cout << "Done with no errors." << endl << endl;

    // 99 books should be read in as that is how many are in the csv file
    cout << "Building library with Book vector and CSV..." << endl;
    Library testLib(books);
    if (testLib.getLibSize() == 99) {
        cout << "Done with no errors." << endl << endl;
    } else {
        cout << "One or more books were not added to the Library." << endl;
    }

    // This .txt file contains test cases for functions
    ifstream fin;
    fin.open("../Input-For-Testing/testCases.txt");

    // Test searching for books
    testSearchForBook(fin, testLib);

    // Test checking books out/in
    testCheckInCheckOut(fin, testLib);

    return 0;
}

void testSearchForBook(ifstream &fin, Library &testLib) {
    cout << "===== TESTING SEARCH FUNCTIONALITY" << endl;
    cout << "===== TEST 1 =====" << endl;
    cout << "Searching for `The Great Gatsby` - should find the book and print its information..." << endl << endl;
    testLib.searchForBook(fin);
    cout << "\nIf the book info was displayed, the test was a success." << endl << endl;

    cout << "===== TEST 2 =====" << endl;
    cout << "Searching for 'The Hunger Games: Catching Fire' - should not find the book..." << endl << endl;
    testLib.searchForBook(fin);
    cout << "\nIf an error message was displayed, the test was a success." << endl << endl;

    cout << "===== TEST 3 =====" << endl;
    cout << "Searching for the author 'F. Scott Fitzgerald' - should find a book..." << endl << endl;
    testLib.searchForBook(fin);
    cout << "\nIf all books by this author are displayed, the test was a success." << endl;
    cout << "If some books are missing, then this needs fixing." << endl << endl;

    cout << "===== TEST 4 =====" << endl;
    cout << "Searching for the author 'Dr. Seuss' - should not find anything..." << endl << endl;
    testLib.searchForBook(fin);
    cout << "\nIf an error message was displayed, the test was a success." << endl << endl;
}

void testCheckInCheckOut(ifstream &fin, Library &testLib) {
    cout << "===== TESTING CHECK IN/OUT FUNCTIONALITY =====" << endl;
    cout << "===== TEST 1 =====" << endl;
    cout << "Trying to check out `The Great Gatsby`, should succeed..." << endl << endl;
    testLib.checkOut(fin);
    cout << "\nIf the book is no longer available, the test was a success." << endl << endl;

    cout << "===== TEST 2 =====" << endl;
    cout << "Trying to check in `The Great Gatsby`, should succeed..." << endl << endl;
    testLib.checkIn(fin);
    cout << "\nIf the book is now available, the test was a success." << endl;

    cout << "===== TEST 3 =====" << endl;
    cout << "Trying to check out `The Great Gatsby` twice, should fail..." << endl << endl;
    testLib.checkOut(fin);
    testLib.checkOut(fin);
    cout << "\nIf the book was checked out and then an error message was displayed, the test was a success." << endl;
}