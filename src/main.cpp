#include <iostream>
#include <vector>
#include <string>
#include "../include/book.h"
#include "../include/library.h"

using namespace std;

void displayMenu() {
    cout << "\n========== Library Management System ==========" << endl;
    cout << "1. Add a new book" << endl;
    cout << "2. Search for a book by published year" << endl;
    cout << "3. Check out a book" << endl;
    cout << "4. Return a book" << endl;
    cout << "5. List all books" << endl;
    cout << "6. Search by book title" << endl;
    cout << "7. View book borrow history" << endl;
    cout << "8. Remove a book" << endl;
    cout << "9. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

int main() {
    Library library;
    int choice;
    bool running = true;
    
    while(running) {
        displayMenu();
        cin >> choice;
        cin.ignore();
        
        switch (choice) {
            case 1: {
                string title, author, isbn, genre;
                int year, copies;
                
                cout << "Enter book title: ";
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter published year: ";
                cin >> year;
                cin.ignore();
                cout << "Enter ISBN: ";
                getline(cin, isbn);
                cout << "Enter genre: ";
                getline(cin, genre);
                cout << "Enter number of copies: ";
                cin >> copies;
                cin.ignore();
                
                Book newBook(title, author, year, isbn, genre, copies);
                library.addBook(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2: {
                int year;
                cout << "Enter published year to search: ";
                cin >> year;
                cin.ignore();
                
                vector<Book> results = library.searchByYear(year);
                
                if (results.empty()) {
                    cout << "No books found from year " << year << endl;
                } else {
                    cout << "Books published in " << year << ":" << endl;
                    for (const Book& book : results) {
                        book.displayInfo();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            }
            case 3: {
                string title, username;
                cout << "Enter the title of the book to check out: ";
                getline(cin, title);
                cout << "Enter your username: ";
                getline(cin, username);
                
                bool success = library.checkOutBook(title, username);
                if (success) {
                    cout << "Book '" << title << "' checked out successfully!" << endl;
                } else {
                    cout << "Failed to check out book. Either the book doesn't exist or all copies are already checked out." << endl;
                }
                break;
            }
            case 4: {
                string title, username;
                cout << "Enter the title of the book to return: ";
                getline(cin, title);
                cout << "Enter your username: ";
                getline(cin, username);
                
                bool success = library.returnBook(title, username);
                if (success) {
                    cout << "Book '" << title << "' returned successfully!" << endl;
                } else {
                    cout << "Failed to return book. The book may not exist or wasn't checked out." << endl;
                }
                break;
            }
            case 5: {
                vector<Book> allBooks = library.getAllBooks();
                if (allBooks.empty()) {
                    cout << "The library is currently empty." << endl;
                } else {
                    cout << "All Books in the Library:" << endl;
                    cout << "------------------------" << endl;
                    for (const Book& book : allBooks) {
                        book.displayInfo();
                        cout << "------------------------" << endl;
                    }
                }
                break;
            }
            case 6: {
                string title;
                cout << "Enter the title of the book to search: ";
                getline(cin, title);
                
                Book* book = library.searchByTitle(title);
                if (book != nullptr) {
                    cout << "Book found:" << endl;
                    book->displayInfo();
                } else {
                    cout << "Book not found." << endl;
                }
                break;
            }
            case 7: {
                string title;
                cout << "Enter the title of the book to view borrow history: ";
                getline(cin, title);
                
                vector<string> history = library.getSpecificBookBorrowHistory(title);
                if (history.empty()) {
                    cout << "No borrowing history for this book." << endl;
                } else {
                    cout << "Borrowing history for '" << title << "':" << endl;
                    for (const string& username : history) {
                        cout << "- " << username << endl;
                    }
                }
                break;
            }
            case 8: {
                string title;
                cout << "Enter the title of the book to remove: ";
                getline(cin, title);
                
                bool success = library.removeBook(title);
                if (success) {
                    cout << "Book '" << title << "' removed successfully!" << endl;
                } else {
                    cout << "Failed to remove book. The book may not exist in the library." << endl;
                }
                break;
            }
            case 9: {
                cout << "Thank you for using the Library Management System!" << endl;
                running = false;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
    
    return 0;
}