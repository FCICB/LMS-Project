#pragma once
#include <bits/stdc++.h>
#include "book.h"
#include "record.h"
class Borrow {
private:
    std::string name;
    std::vector<Book*>borrowedBooks;
public:
    // constructor
    Borrow(const std::string& name);

    // getter
    std::string getName() const;

    // borrow function
    void borrow(Book* book);

    // return function
    void returnBook(Book* book);
};

