#include "../include/book.h"
#include <iostream>
Book::Book(const string& title, const string& author, int year, 
    const string& isbn, const string& genre, int copies): 
    title(title), author(author), year(year), isbn(isbn), genre{genre}, availableCopies(copies){

}

Book::~Book(){
    
}

string Book::getTitle() const {
    return this->title;
}

string Book::getAuthor() const {
    return this->author;
}

int Book::getYear() const {
    return this->year;
}

string Book::getISBN() const {
    return this->isbn;
}

string Book::getGenre() const {
    return this->genre;
}

int Book::getTotalCopies() const {
    return this->totalCopies;
}

int Book::getAvailableCopies() const {
    return this->availableCopies;
}

int Book::getBorrowCount() const {
    return this->borrowCount;
}

vector<string> Book::getBorrowHistory() const {
    return this->borrowHistory;
}

bool Book::checkOut(const string& username){
    if(availableCopies > 0){
        availableCopies--;
        borrowHistory.push_back(username);
        borrowCount++;
        return true;
    }
    return false;
}

bool Book::returnBook(){
    if(availableCopies < totalCopies){
        availableCopies++;
        return true;
    }
    return false;
}

void Book::displayInfo() const {
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Genre: " << genre << endl;
    cout << "Available Copies: " << availableCopies << " of " << totalCopies << endl;
    cout << "Times Borrowed: " << borrowCount << endl;
}