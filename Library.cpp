#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#include "removeElement.hpp"
#include "Library.hpp"

using namespace std;

int Library::totalBorrowedBooks = 0;

Library::Library() {
  reservedCount = 0;
}

int Library::getTotalBorrowedBooks() {
  return totalBorrowedBooks;
}

void Library::reserveBook (string title) const {
  bool existsInLibrary = false;
  bool alreadyReserved = false;
    // Check if book exists in library
    for (auto book : bookList) {
        if (book == title) {
            existsInLibrary = true;
            break;
        }
    }
    // Check if already reserved
    for (auto reserved : reservedBooks) {
        if (reserved == title) {
            alreadyReserved = true;
            break;
        }
    }
    // Try to reserve
    if (existsInLibrary && !alreadyReserved) {
        reservedBooks.push_back(title);
        ++reservedCount;
        cout << "Book reserved: " << title << endl;
        cout << "Reserved book count: " << reservedCount << endl;
    } 
    else cout << "Book not reserved!" << endl;
}

void Library::addBook(string title, double bookCost) {
  if (bookList.size() <= 100) { 
    bookList.push_back(title);
    libraryBudget -= bookCost;
  }
  else cout << "Library is full!" << endl;
}

bool Library::borrowBook(string title) {
  for (auto _bookList : bookList) {
    if (_bookList == title) {
      ++totalBorrowedBooks;
      removeElement(bookList, _bookList);
      cout << "Book borrowed: " << title << endl;
      return true;
    }
  }
  cout << "Book not found!" << endl; 
  return false;
}

void Library::listBooks() {
  for (auto _bookList : bookList ) {
    cout << _bookList << endl;
  }
}
