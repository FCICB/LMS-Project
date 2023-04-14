#pragma once
#include <bits/stdc++.h>
#include "book.h"

class Record {
private:
    std::vector<Book> books; // vector to hold book objects

public:

    void loadFromFile(const std::string &fileName);

    void addBook(const Book &book);

    void editBook(const std::string &title);

    void deleteBook(const std::string &title);


    // func to display entire record
    void displayAllRecords() const;

    // display record by title
    void displayRecordByTitle(const std::string &title) const;

    // display record by author
    void displayRecordByAuthor(const std::string &author) const;

    // display record by isbn
    void displayRecordByISBN(const std::string &isbn) const;


};

