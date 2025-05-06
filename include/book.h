#pragma once
#define MAX_BORROW_HISTORY 100
#include <string>
#include <vector>
using namespace std;

class Book{
    private:
        string title;
        string author;
        int year;
        string isbn;
        string genre;
        int totalCopies;
        int availableCopies;
        vector<string> borrowHistory;
        int borrowCount;
    public:
        Book(const string& title, const string& author, int year, 
             const string& isbn, const string& genre, int copies);
        ~Book();

        string getTitle() const;
        string getAuthor() const;
        int getYear() const;
        string getISBN() const;
        string getGenre() const;
        int getTotalCopies() const;
        int getAvailableCopies() const;
        int getBorrowCount() const;

        vector<string> getBorrowHistory() const;

        bool checkOut(const string& username);
        bool returnBook();
        void displayInfo() const;
};
