#pragma once

#include <bits/stdc++.h>

class Book {
private:
    std::string title;
    std::string author;
    std::string ISBN;
    bool available;


public:
    //constructor
    Book(const std::string title,const std::string author, const std::string ISBN, bool available = true);

    // getter and setter function
    std::string getTitle() const;

    void setTitle(const std::string &title);

    std::string getAuthor() const;

    void setAuthor(const std::string &author);

    std::string getISBN() const;

    void setISBN(const std::string &ISBN);

    bool getAvailable() const;

    void setAvailable(bool available);
    bool isAvailable() const;

    // function to display book details
    void displayBook() const;

    // search for book function
    void search(const std::string &keyword) const;

    // operator overloading for comparison operators based on availability

    bool operator<(const Book &b) const;

    bool operator>(const Book &b) const;

    bool operator==(const Book &b) const;


};



