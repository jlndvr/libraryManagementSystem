#include <iostream>
#include "Library.hpp"

using namespace std;

double libraryBudget = 5000;

int main() {
  cout << "Current library budget is: " << libraryBudget << endl;

  Library myLibrary;

  myLibrary.addBook("The Great Gatsby", 300);
  myLibrary.addBook("1984", 400);
  myLibrary.addBook("To Kill a Mocking Bird", 350);
  myLibrary.listBooks();
  myLibrary.reserveBook("1984");
  myLibrary.borrowBook("To Kill a Mocking Bird");
  
  cout << "Total number of borrowed books is: " << myLibrary.getTotalBorrowedBooks << endl;
  
}
