#include "Library.h"

void testCreateBook();
void testCreateLibrary();
void testDisplayInfo(Book book);

int main() {
    vector<Book> books;
    Library testLib(books);
    testLib.searchForBook(); // Test things here, such as individual words or confusing input
    testLib.checkOut();
    testLib.checkIn();
    return 0;
}