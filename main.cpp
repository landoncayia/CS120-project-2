#include "Library.h"

int main() {
    vector<Book> initialBooks;
    cout << "Building library..." << endl;
    Library library(initialBooks);
    cout << "Library built." << endl;
    library.searchForBook();
    return 0;
}