# Landon Cayia - Project 2
My second CS120 Project

## First Part

#### Why did you choose this class?
I chose this class because I felt that a system for managing library books would
be more applicable for the purposes of this assignment. If code were reused from
Project 1, it would be necessary to write another global function that used my
`HangmanGame` class. I could not think of a way to use the class for anything
other than its basic functionality, so I wrote a new class instead. I also felt
inspired to do something different that may teach me C++ techniques that I did
not learn in lecture.

#### Why does it make sense for the purchasePrice field to be an optional?
It makes sense for the `purchasePrice` field to be an optional because not every
book in the library is available for purchase. It it useful to be able to know
1) Whether the field was initialized or not, to know whether the book is for sale.
2) The value of the field if it was initialized, so that the user can know the
purchase price of the book.

If an optional were not used here, this would require two separate variables: a
`bool` for whether the book is for sale or not, and a `double` for its price.
A field of type `optional<double>` covers both of these bases.

#### Why did I use a smart pointer for _____?


#### How did I use the class with a function?
I wrote a global function called `initializeLibrary` that reads a csv file
containing information about numerous library books and adds them to a vector
that stores the books in an instance of the library class, called bookInventory.

## Second Part
For the test cases, I began by using `testing.cpp` to simply try to use the
program for its basic functionality. This includes creation of a Book vector
and the initialization of the Library. I did not anticipate that a ton of
testing would be needed.  

It was fairly difficult to write testing cases for this program in the same way 
that we did so in class because my program does not have functions that take
input directly as parameters, but rather require input from the user as the
functions run.

## Third Part

#### Did all test cases pass on the first try?
Definitely not. There was a lot that was wrong with the program. The executables
for `main.cpp` and `testing.cpp` were not implemented correctly, so they could
not be run separately. There were also a lot of logic errors and inconsistencies
that I would not have caught otherwise.

## Fourth Part

#### Why do you think you did not have these cases before you implemented the algorithm(s)?
Because of the fact that I was experiencing difficulty with testing the way
we did in lecture, I didn't have many test cases by the second step.  

I contacted Lisa regarding my testing method, and she suggested creating a file
that holds potential user input and to pass it to my functions with an `ifstream`
object for testing. I have implemented this solution by modifying functions that
involve user input to have `istream ins&` and `ostream &outs` as parameters.
When they are called by `main.cpp`, I simply pass in `cin` and `cout`. When they
are called by `testing.cpp`, I pass in `fin` for the `testCases.txt` file and
`cout` for output to the console.

## Documentation for `testCases.txt`
#### `searchForBook` function
##### Test 1
`1, The Great Gatsby`  
Selects the option to search by title, should find this book.
##### Test 2
`1, abcdefg`  
Selects the option to search by title, should not find this book.
##### Test 3
`2, F. Scott Fitzgerald`  
Selects the option to search by author, should find this author.
##### Test 4
`2, Dr. Seuss`  
Selects the option to search by author, should not find this author.
##### Test 5
`2, J.K. Rowling`  
Selects the option to search by author, should find multiple books by this
author and display them all. This is meant to test the capability to find
substrings with the search function and to check whether multiple results
can be displayed.
##### Test 6
`1, The Hunger Games`  
Selects the option to search by title, should find this book (checking first
index).
##### Test 7
`1, Fifty Shades Darker`  
Selects the option to search by title, should find this book (checking last
index).
##### Test 8
`1, 1984`  
Selects the option to search by title, should find this book (checking a
numerical title).
##### Test 9
`1, the hunger`  
Selects the option to search by title, should find this book. This is meant
to test the capability to find substrings and tests lower case searches.


#### `checkIn` and `checkOut` functions
##### Test 1
`5`  
Attempts to check out Book No. 5 (The Great Gatsby) once. Should succeed.
##### Test 2
`5`  
Attempts to check in Book No. 5 (The Great Gatsby) once. Should succeed
since it is currently checked out.
##### Test 3
`5, 5`  
Attempts to check out Book No. 5 (The Great Gatsby) twice in a row. Should
fail the second time.
##### Test 4
`5, 5`  
Attempts to check in Book No. 5 (The Great Gatsby) twice in a row. Should
fail the second time.
##### Test 5
`105`  
Attempts to check out Book No. 105 (does not exist). Should fail.
##### Test 6
`-5`  
Attempts to check in Book No. -5 (does not exist). Should fail.


#### `addBook` function
##### Test 1
`Memes, Bob Ross, 2020`  
Attempts to add a Book to the Library. Should succeed.
##### Test 2
`Failure, Landon Cayia, word, 2019`  
Attempts to add a Book to the library with a bad year. Should fail then
succeed when corrected.
##### Test 3
`Extra Memes, Bob Ross, -2018, 2018`  
Attempts to add a Book to the library with a bad year. Should fail then
succeed when corrected.


#### `setBookPrice` function
##### Test 1
`5, 12.05`
Attempts to set the price for Book No. 5 (The Great Gatsby) to $12.05. Should
succeed.
##### Test 2
`144`
Attempts to set the price for Book No. 144 (does not exist). Should fail.
##### Test 3
`1, -2`
Attempts to set the price for Book No. 2 (Harry Potter and the Philosopher's
Stone) to $-2. Should fail.


#### `buyBook` function
##### Test 1
`5`  
Attempts to purchase Book No. 5 (The Great Gatsby). Should succeed since the
book is for sale and has a price.


## Bug Fixing
As I found logic and runtime errors, I fixed them and noted them in the commit
comments. There were quite a bit more than I was expecting. Most of them had to
do with me not using reference variables when I should have been. That meant that
when a book was passed to a function and then modified only the book's copy was
modified, not the actual book from the `Library` instance's `bookInventory` field.


## Sources
Book csv file from:  
https://github.com/zygmuntz/goodbooks-10k/blob/master/samples/books.csv