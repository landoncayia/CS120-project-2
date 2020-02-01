#include "Library.h"

void testCreateBook();
void testCreateLibrary();
void testDisplayInfo(Book book);

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

    // Search for `The Great Gatsby` using cin to give input
    cout << "Searching for `The Great Gatsby` - should find the book and print its information..." << endl;
    cout << "Type `1` and then `The Great Gatsby` when prompted..." << endl << endl;
    testLib.searchForBook();
    cout << "If the book info was displayed, the test was a success." << endl << endl;

    // Try to check this book out
    cout << "Try to check out `The Great Gatsby`..." << endl;
    cout << "Enter `5` when prompted..." << endl << endl;
    testLib.checkOut();


    testLib.checkIn();
    return 0;
}