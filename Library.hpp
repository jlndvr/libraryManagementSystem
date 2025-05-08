#include <vector>
#include <string>

using namespace std;

extern double libraryBudget;

class Library {
private:
 static int totalBorrowedBooks;
 vector<string> bookList;
 mutable int reservedCount;
 mutable vector<string> reservedBooks;
public:
 void reserveBook(string title) const;
 static int getTotalBorrowedBooks();
 void addBook(string title, double bookCost);
 bool borrowBook(string title);
 void listBooks();
 Library();
};
