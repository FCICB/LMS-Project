#include <bits/stdc++.h>
#include "book.h"
#include "record.h"

using namespace std;

class BookNotFoundException : public std::exception {
public:
    const char *what() const throw() {
        return "Book not found.";
    }
};

void Record::loadFromFile(const string &fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Failed to open file: " << fileName << endl;
        throw runtime_error("Failed to open file");
    }
    books.clear();
    string title, author, isbn;

    while (file >> title >> author >> isbn) {
        Book book(title, author, isbn);
        books.push_back(book);
    }
    if (file.bad()) {
        cerr << "Error reading from file: " << fileName << endl;
        throw runtime_error("Error reading from file");
    } else if (file.fail()) {
        cerr << "Failed to read data from file: " << fileName << endl;
        throw runtime_error("Failed to read data from file");
    }
    file.close();
}

void Record::addBook(const Book &book) {
    books.push_back(book);
}

void Record::editBook(const string &title) {
    for (auto &book :books) {
        if (book.getTitle() == title) {
            // display existing book information
            cout << "Current book info:\n";
            book.displayBook();

            // get updated info from user
            string newTitle, newAuthor, newISBN;

            cout << "Enter new title: ";
            getline(cin, newTitle);
            while (newTitle.empty()) {
                cerr << "Title cannot be empty. Please enter a valid title.\n";
                getline(cin, newTitle);
            }

            cout << "Enter new author: ";
            getline(cin, newAuthor);
            while (newAuthor.empty()) {
                cerr << "Author cannot be empty. Please enter a valid title.\n";
                getline(cin, newAuthor);
            }

            cout << "Enter new ISBN: ";
            getline(cin, newISBN);
            while (newISBN.empty()) {
                cerr << "ISBN cannot be empty. Please enter a valid title.\n";
                getline(cin, newISBN);
            }

            // update book info
            book.setTitle(newTitle);
            book.setAuthor(newAuthor);
            book.setISBN(newISBN);

            cout << "Book info updated successfully.\n";
            return;

        }
    }
    throw BookNotFoundException();

}

void Record::deleteBook(const string &title) {
    for (auto it = books.begin(); it != books.end(); it++) {
        if ((*it).getTitle() == title) {
            books.erase(it); // remove book from vector
            cout << "Book deleted successfully.\n";
            return;
        }

    }
    throw BookNotFoundException();
}

void Record::displayAllRecords() const {
    cout << "Displaying all records:\n";
    for (const auto &book:books) {
        book.displayBook();
    }
}

void Record::displayRecordByTitle(const string &title) const {
    bool found = false;
    for (const auto &book:books) {
        if (book.getTitle() == title) {
            cout << "Displaying record with title: " << title << endl;
            book.displayBook();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found with title: " << title << endl;
    }
}

void Record::displayRecordByAuthor(const string &author) const {
    bool found = false;
    for (const auto &book:books) {
        if (book.getAuthor() == author) {
            cout << "Displaying record with author: " << author << endl;
            book.displayBook();
            found = true;
        }
    }
    if (!found) {
        cout << "No record found with author: " << author << endl;
    }
}

void Record::displayRecordByISBN(const string &isbn) const {
    bool found = false;
    for (const auto &book:books) {
        if (book.getISBN() == isbn) {
            cout << "Displaying record with ISBN: " << isbn << endl;
            book.displayBook();
            found = true;
            break;
        }
    }
    if (!found) {
        cout << "No record found with ISBN: " << isbn << endl;
    }
}
