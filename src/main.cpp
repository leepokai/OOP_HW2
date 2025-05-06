#include <iostream>
#include <vector>
#include <string>
#include "../include/book.h"
#include "../include/library.h"

using namespace std;

void displayMenu() {
    cout << "========== Library Management System ==========" << endl;
    cout << "1. Add a new book" << endl;
    cout << "2. Search for a book by published year" << endl;
    cout << "3. Check out a book" << endl;
    cout << "4. Return a book" << endl;
    cout << "5. List all books" << endl;
    cout << "6. Search by book title" << endl;
    cout << "7. View book borrow history" << endl;
    cout << "8. Show most popular books" << endl;
    cout << "9. Exit" << endl;
    cout << "=============================================" << endl;
    cout << "Enter your choice: ";
}

int main(){
    Library library;
    int choice;
    bool running = true;
    while(running){
        displayMenu();
        cin >> choice;
        cin.ignore();
        switch (choice){
            case 1:{
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
                
                Book newBook(title, author, year, isbn, genre, copies);
                library.addBook(newBook);
                cout << "Book added successfully!" << endl;
                break;
            }
            case 2:{
                int year;
                cout<< "Enter published year to search: (Gregorian calendar)";
                cin>>year;
                
            }
        }
    }
}