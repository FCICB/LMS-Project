#include <bits/stdc++.h>
#include "book.h"

using namespace std;

// constructor
Book::Book(string title, string author, string ISBN, bool available) :
        title(title), author(author), ISBN(ISBN), available(available) {}


// Getter and setter function

string Book::getTitle() const {
    return title;
}

void Book::setTitle(const string &title) {
    if (!title.empty()) {
        this->title = title;
    } else {
        cout << "Error: Title cannot be empty.\n";
    }
}


string Book::getAuthor() const {
    return author;
}

void Book::setAuthor(const string &author) {
    if (!author.empty()) {
        this->author = author;
    } else {
        cout << "Error: Author cannot be empty.\n";
    }
}


string Book::getISBN() const {
    return ISBN;
}

void Book::setISBN(const string &ISBN) {
    if (!ISBN.empty()) {
        this->ISBN = ISBN;
    } else {
        cout << "Error: ISBN cannot be empty.\n";
    }
}

bool Book::getAvailable() const {
    return available;
}

void Book::setAvailable(bool available) {
    this->available = available;
}

void Book::displayBook() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << ISBN << endl;
    cout << "Availability: " << (available ? "Available" : "Not Available") << endl;
}

// operator overloading for comparison based on availability

bool Book::operator<(const Book &b) const {
    return available < b.available;
}

bool Book::operator>(const Book &b) const {
    return available > b.available;
}

bool Book::operator==(const Book &b) const {
    return available == b.available;
}

void Book::search(const std::string &keyword) const {
    if (title.find(keyword) != string::npos ||
        author.find(keyword) != string::npos ||
        ISBN.find(keyword) != string::npos) {
        cout << "Book Found: " << title << " by " << author << "(ISBN: " << ISBN << ")" << endl;
    } else {
        cout << "No books found matching the keyword: " << keyword << endl;
    }
}
int main(){
    // Create a book object
    Book book1("So Good They Can't Ignore You", "Cal Newport", "145-550-9124", true);

    // Display book details
    std::cout << "Book 1 Details:\n";
    book1.displayBook();

    // Update book details using setters
    book1.setTitle("How to Fail at Almost Everything and Still Win Big");
    book1.setAuthor("Scott Adams");
    book1.setISBN("159-184-7745");
    book1.setAvailable(false);

    // Display updated book details
    std::cout << "\nBook 1 Details after update:\n";
    book1.displayBook();

    // Compare books based on availability
    Book book2("Harry Potter and the Sorcerer's Stone", "J.K. Rowling", "9780590353427", false);
    if (book1 > book2) {
        std::cout << "\nBook 1 is available while Book 2 is not.\n";
    } else if (book1 < book2) {
        std::cout << "\nBook 1 is not available while Book 2 is.\n";
    } else {
        std::cout << "\nBook 1 and Book 2 have the same availability status.\n";
    }

}



