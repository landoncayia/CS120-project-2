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
object for testing. I have implemented this solution, but it messed up the order
of my commits. That is why they are a bit scattered about in their current state.
It is required to modify the functions that are being tested to match the way
they are called in `testing.cpp`. It is required that they accept the `ifstream`
object created in the testing file that opens and reads `testCases.txt` to test
certain user input cases.


## Bug Fixing
As I found logic and runtime errors, I fixed them and noted them in the commit
comments. There were quite a bit more than I was expecting. Most of them had to
do with me not using reference variables when I should have been. That meant that
when a book was passed to a function and then modified only the book's copy was
modified, not the actual book from the `Library` instance's `bookInventory` field.


## Sources
Book csv file from:  
https://github.com/zygmuntz/goodbooks-10k/blob/master/samples/books.csv