#include "book.h"
#include "borrow.h"
#include "record.h"
#include "bits/stdc++.h"

using namespace std;

void displayMenu() {
    cout << "--------------------------" << endl;
    cout << "Library Record System" << endl;
    cout << "--------------------------" << endl;
    cout << "1. Load data from file" << endl;
    cout << "2. Add a book" << endl;
    cout << "3. Edit a book" << endl;
    cout << "4. Delete a book" << endl;
    cout << "5. Display all records" << endl;
    cout << "6. Display record by title" << endl;
    cout << "7. Display record by author" << endl;
    cout << "8. Display record by ISBN" << endl;
    cout << "9. Borrow a book" << endl;
    cout << "10. Return a book" << endl;
    cout << "11. Exit" << endl;
    cout << "--------------------------" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Record record;
    record.addBook(Book("How to Fail at Almost Everything and Still Win Big", "Scott Adams", "159-184-7745"));
    record.addBook(Book("So Good They Can't Ignore You", " Cal Newport", "145-550-9124"));
    record.addBook(Book("Agile Software Development Principles, Patterns, and Practices", "Robert C. Martin",
                        "978-1-292-02594-0"));
    record.addBook(Book("Steal Like an Artist: 10 Things Nobody Told You About Being Creative", " Austin Kleon",
                        "978-076-116-9253"));

    int choice;
    string title, author, isbn;

    while (true) {
        displayMenu();
        cin >> choice;
        switch (choice) {
            case 0:{
                string fileName;
                cout<<"Enter file name: ";
                cin>>fileName;
                record.loadFromFile(fileName);
            }
            case 1: {
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Book Author: ";
                getline(cin, author);
                cout << "Enter Book ISBN: ";
                getline(cin, isbn);
                Book newBook(title, author, isbn);
                record.addBook(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: {
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                record.editBook(title);
                break;
            }
            case 3: {
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                record.deleteBook(title);
                break;
            }
            case 4: {
                record.displayAllRecords();
                break;
            }
            case 5: {
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, title);
                record.displayRecordByTitle(title);
                break;
            }
            case 6: {
                cout << "Enter Book Title: ";
                cin.ignore();
                getline(cin, author);
                record.displayRecordByAuthor(title);
                break;
            }
            case 7: {
                cout << "Enter Book ISBN: ";
                cin.ignore();
                getline(cin, isbn);
                record.displayRecordByISBN(isbn);
                break;
            }
            case 8:{
                string title,borrower;
                cout<<"Enter book title to borrow: ";
                getline(cin,title);
                cout<<"Enter borrower's name: ";
                getline(cin,borrower);


            }
            case 9:{

            }
            case 11: {
                cout << "Exiting" << endl;
                return 0;
            }
            default: {
                cerr << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}
