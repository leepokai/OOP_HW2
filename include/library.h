#pragma once
#include <string>
#include <vector>
#include "book.h"
struct AVLNode{
    Book book;
    AVLNode* left;
    AVLNode* right;
    int height;
    vector<pair<string,string>> borrowHistory;
    AVLNode(const Book& b): book(b), left(nullptr), right(nullptr), height(1){}
};

class Library{
    private:
        AVLNode* titleRoot;
        AVLNode* yearRoot;
        vector<pair<string, string>> borrowHistory;

        int height(AVLNode* node);
        int balanceFactor(AVLNode* node);
        AVLNode* rightRotate(AVLNode* y);
        AVLNode* leftRotate(AVLNode* x);

        AVLNode* insertByTitle(AVLNode* node, const Book& book);
        AVLNode* removeByTitle(AVLNode* node, const string& title);
        AVLNode* searchByTitle(AVLNode* node, const string& title);
        void searchByYear(AVLNode* node, int year, vector<Book>& results);
        void inOrderTraversalByTitle(AVLNode* node, vector<Book>& books) const;
        
        AVLNode* insertByYear(AVLNode* node, const Book& book);
        AVLNode* removeByYear(AVLNode* node, int year, const string& title);
        
        

        void destroyTree(AVLNode* node);
        AVLNode* minValueNode(AVLNode* node);
        AVLNode* maxValueNode(AVLNode* node);

    public:
        Library();
        ~Library();

        void addBook(const Book& book);
        bool removeBook(const string& title);
        Book* searchByTitle(const string& title);
        vector<Book> searchByYear(int year);
        bool checkOutBook(const string& title, const string& username);
        bool returnBook(const string& title, const string& username);
        vector<Book> getAllBooks() const;
        vector<string> getSpecificBookBorrowHistory(const string& title);
        vector<pair<string, string>> getOverAllBorrowHistory();
};