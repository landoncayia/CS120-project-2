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
This part just involves writing test cases. Not sure whether I need to add
anything to README.md or not.

## Third Part

#### Did all test cases pass on the first try?
Write stuff here

## Fourth Part

#### 

## Fifth Part


