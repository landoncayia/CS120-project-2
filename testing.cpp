#include "Library.h"

void testSearchForBook(ifstream &fin, Library &testLib);
void testCheckInCheckOut(ifstream &fin, Library &testLib);
void testAddBook(ifstream &fin, Library &testLib);
void testSetBookPrice(ifstream &fin, Library &testLib);
void testBuyBook(ifstream &fin, Library &testLib);

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

    // Test adding books
    testAddBook(fin, testLib);

    // Test setting price
    testSetBookPrice(fin, testLib);

    // Test buying books
    testBuyBook(fin, testLib);

    return 0;
}

void testSearchForBook(ifstream &fin, Library &testLib) {
    cout << "===== TESTING SEARCH FUNCTIONALITY =====\n";
    cout << "===== TEST 1 =====\n";
    cout << "Searching for `The Great Gatsby` - should find the book and print its information...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf the book info was displayed, the test was a success.\n\n";

    cout << "===== TEST 2 =====\n";
    cout << "Searching for 'abcdefg' - should not find the book...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 3 =====\n";
    cout << "Searching for the author 'F. Scott Fitzgerald' - should find a book...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf all books by this author are displayed, the test was a success.\n";
    cout << "If some books are missing, then this needs fixing.\n\n";

    cout << "===== TEST 4 =====\n";
    cout << "Searching for the author 'Dr. Seuss' - should not find anything...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 5 =====\n";
    cout << "Searching for the author 'J.K. Rowling' - should find multiple books...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf several 'Harry Potter' books were displayed, the test was a success.\n\n";

    cout << "===== TEST 6 =====\n";
    cout << "Searching for the title 'The Hunger Games' - should find...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 7 =====\n";
    cout << "Searching for the author 'Fifty Shades Darker' - should find...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf the book info was displayed, the test was a success.\n\n";

    cout << "===== TEST 8 =====" << endl;
    cout << "Searching for the author '1984' - should find...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf the book info was displayed, the test was a success.\n\n";

    cout << "===== TEST 9 =====" << endl;
    cout << "Searching for the title 'the hunger' - should find...\n\n";
    testLib.searchForBook(fin, cout);
    cout << "\nIf the book info was displayed, the test was a success.\n\n";
}

void testCheckInCheckOut(ifstream &fin, Library &testLib) {
    cout << "===== TESTING CHECK IN/OUT FUNCTIONALITY =====\n";
    cout << "===== TEST 1 =====\n";
    cout << "Trying to check out `The Great Gatsby`, should succeed...\n";
    testLib.checkOut(fin, cout);
    cout << "\nIf the book is no longer available, the test was a success.\n\n";

    cout << "===== TEST 2 =====\n";
    cout << "Trying to check in `The Great Gatsby`, should succeed...\n\n";
    testLib.checkIn(fin, cout);
    cout << "\nIf the book is now available, the test was a success.\n\n";

    cout << "===== TEST 3 =====\n";
    cout << "Trying to check out `The Great Gatsby` twice, should fail...\n\n";
    testLib.checkOut(fin, cout);
    testLib.checkOut(fin, cout);
    cout << "\nIf the book was checked out and then an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 4 =====\n";
    cout << "Trying to check in `The Great Gatsby` twice, should fail...\n\n";
    testLib.checkIn(fin, cout);
    testLib.checkIn(fin, cout);
    cout << "\nIf the book was checked in and then an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 5 =====\n";
    cout << "Trying to check out Book No. 105 (does not exist), should fail...\n\n";
    testLib.checkOut(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 6 =====\n";
    cout << "Trying to check in Book No. -5 (does not exist), should fail...\n\n";
    testLib.checkOut(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";
}

void testAddBook(ifstream &fin, Library &testLib) {
    cout << "===== TESTING ADD FUNCTIONALITY =====\n";
    cout << "===== TEST 1 =====\n";
    cout << "Trying to add a book called 'Memes' by 'Bob Ross' written in '2020'...\n";
    testLib.addBook(fin, cout);
    cout << "\nIf no error messages were displayed, the test was a success.\n\n";

    cout << "===== TEST 2 =====\n";
    cout << "Trying to add a book called 'Failure' by 'Landon Cayia' written in 'word', should fail...\n";
    testLib.addBook(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 3 =====\n";
    cout << "Trying to add a book called 'Extra Memes' by 'Bob Ross' written in '-2018', should fail...\n";
    testLib.addBook(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";
}

void testSetBookPrice(ifstream &fin, Library &testLib) {
    cout << "===== TESTING SET PRICE FUNCTIONALITY =====\n";
    cout << "===== TEST 1 =====\n";
    cout << "Trying to set the price of Book No. 5 (The Great Gatsby) to $12.05, should succeed...\n";
    testLib.setBookPrice(fin, cout);
    cout << "\nIf no error messages were displayed, the test was a success.\n\n";

    cout << "===== TEST 2 =====\n";
    cout << "Trying to set the price of Book No. 144 (does not exist), should fail...\n";
    testLib.setBookPrice(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";

    cout << "===== TEST 3 =====\n";
    cout << "Trying to set the price of Book No. 2 (Harry Potter and the Philosopher's Stone) to $2, should fail...\n";
    testLib.setBookPrice(fin, cout);
    cout << "\nIf an error message was displayed, the test was a success.\n\n";
}

void testBuyBook(ifstream &fin, Library &testLib) {
    cout << "===== TESTING BUY FUNCTIONALITY =====\n";
    cout << "===== TEST 1 =====\n";
    cout << "Trying to buy the book 'The Great Gatsby' (id 5)...\n";
    testLib.buyBook(fin, cout);
    cout << "\nIf no error messages were displayed, the test was a success.\n";
}