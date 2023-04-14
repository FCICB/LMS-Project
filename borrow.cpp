#include <bits/stdc++.h>
#include "book.h"
#include "borrow.h"
#include "record.h"

using namespace std;

string Borrow::getName() const {
    return name;
}

void Borrow::borrow(Book *book) {
    if (book == nullptr) {
        throw invalid_argument("Invalid book pointer");
    }
    if (book->isAvailable()) {
        borrowedBooks.push_back(book);
        book->search("");
        cout << "Book borrowed: " << book->getTitle() << " by " << book->getAuthor() << "(ISBN: " << book->getISBN()
             << ")" << endl;
    } else {
        throw runtime_error("Error: Book not available for borrowing: ");
    }
}

void Borrow::returnBook(Book *book) {
    if (book == nullptr) {
        throw invalid_argument("Invalid book pointer");
    }

    // check if book is borrowed
    bool found = false;
    for (auto it = borrowedBooks.begin(); it != borrowedBooks.end(); it++) {
        if (*it == book) {
            found = true;
            borrowedBooks.erase(it); // remove book from borrowed books list
            book->setAvailable(true); // update books availability status.
            cout << "Book returned: " << book->getTitle() << " by " << book->getAuthor() << "(ISBN: " << book->getISBN()
                 << ")" << endl;
            break;
        }
    }
    if(!found){
        throw runtime_error("Error: Book not borrowed by this borrower\n");
    }
}