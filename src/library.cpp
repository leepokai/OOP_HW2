#include "../include/library.h"
#include <iostream>

int max(int a,int b){
    return (a > b) ? a : b;
}

Library::Library() : titleRoot(nullptr), yearRoot(nullptr) {}

Library::~Library(){
    destroyTree(titleRoot);
    destroyTree(yearRoot);
}

int Library::height(AVLNode* node){
    if(node == nullptr) return 0;
    return node->height;
}

int Library::balanceFactor(AVLNode* node){
    if(node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

// 輸入進來的 current 是被旋轉下去的
AVLNode* Library::rightRotate(AVLNode* current){
    AVLNode* child = current->left;
    AVLNode* grandchild = child->right;

    child->right = current;
    current->left = grandchild;

    // 先把 current 調整正確 child->right 就可以獲得正確的高度了
    current->height = max(height(current->right),height(current->left)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;
    
    return child;
}

AVLNode* Library::leftRotate(AVLNode* current){
    AVLNode* child = current -> right;
    AVLNode* grandchild = child -> left;

    child -> left = current;
    current -> right = grandchild;
    
    current->height = max(height(current->right),height(current->left)) + 1;
    child->height = max(height(child->left), height(child->right)) + 1;

    return child;
}

AVLNode* Library::insertByTitle(AVLNode* node, const Book& book){
    if(node == nullptr){
        // 如果樹是空的話那就把根節點設定為這個 new book
        return new AVLNode(book);
    }

    if(book.getTitle() < node->book.getTitle()){
        node->left = insertByTitle(node->left, book);
    }
    else if(book.getTitle() > node->book.getTitle()){
        node->right = insertByTitle(node->right, book);
    }
    else{
        cout<<"You can't add the title which has been added into the library\n";
        return node;
    }

    node->height = max(height(node->left),height(node->right)) + 1;

    int balance = balanceFactor(node);

    if(balance > 1 && balanceFactor(node->left) >= 0){// remove 時有可能發生 balanceFactor(node->left) == 0 的情形
        return rightRotate(node);
    }
    if(balance > 1 && balanceFactor(node->left) < 0){
        node->left = leftRotate(node->left); // 我是 grandparent
        return rightRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) <= 0){
        return leftRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

AVLNode* Library::insertByYear(AVLNode* node, const Book& book) {
    if (node == nullptr) {
        return new AVLNode(book);
    }

    if (book.getYear() < node->book.getYear() || 
        (book.getYear() == node->book.getYear() && book.getTitle() < node->book.getTitle())) {
        node->left = insertByYear(node->left, book);
    } else if (book.getYear() > node->book.getYear() || 
              (book.getYear() == node->book.getYear() && book.getTitle() > node->book.getTitle())) {
        node->right = insertByYear(node->right, book);
    } else {
        return node; 
    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && balanceFactor(node->left) >= 0){// remove 時有可能發生 balanceFactor(node->left) == 0 的情形
        return rightRotate(node);
    }
    if(balance > 1 && balanceFactor(node->left) < 0){
        node->left = leftRotate(node->left); // 我是 grandparent
        return rightRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) <= 0){
        return leftRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}



AVLNode* Library::minValueNode(AVLNode* node){
    AVLNode* current = node;
    while(current && current->left!=nullptr){
        current = current->left;
    }
    return current; 
}
AVLNode* Library::maxValueNode(AVLNode* node){
    AVLNode* current = node;
    while(current && current->right!=nullptr){
        current = current->right;
    }
    return current; 
}

AVLNode* Library::removeByTitle(AVLNode* node, const string& title){
    if(node == nullptr) return nullptr;

    if(title < node->book.getTitle()){
        node->left = removeByTitle(node->left, title);
    }
    else if(title > node->book.getTitle()){
        node->right = removeByTitle(node->right, title);
    }
    else {
        if(node->left == nullptr){
            AVLNode* temp = node->right;
            delete node;
            return temp;
        }
        else if(node->right == nullptr){
            AVLNode* temp = node->left;
            delete node;
            return temp;
        }

        AVLNode* temp = minValueNode(node->right);
        node->book = temp->book;
        node->right = removeByTitle(node->right, temp->book.getTitle());
        // 把 temp->book.gettitle 變成我們想要 remove 的 title 其實就是變相把我們下移的 node 進行移除

    }

    node->height = 1 + max(height(node->left), height(node->right));
    int balance = balanceFactor(node);

    if(balance > 1 && balanceFactor(node->left) >= 0){// remove 時有可能發生 balanceFactor(node->left) == 0 的情形
        return rightRotate(node);
    }
    if(balance > 1 && balanceFactor(node->left) < 0){
        node->left = leftRotate(node->left); // 我是 grandparent
        return rightRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) <= 0){
        return leftRotate(node);
    }
    if(balance < -1 && balanceFactor(node->right) > 0){
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

AVLNode* Library::removeByYear(AVLNode* node, int year, const string& title){
    if(node == nullptr) return nullptr;

    if(node->book.getYear() < year){
        node->right = removeByYear(node->right, year, title);
    }
    else if(node->book.getYear() > year){
        node->left = removeByYear(node->left, year, title);
    }
    else{
        if(node->book.getTitle() < title){
            node->right = removeByYear(node->right, year, title);
        }
        else if(node->book.getTitle() > title){
            node->left = removeByYear(node->left, year, title);
        }
        else{
            if(node->left == nullptr){
                AVLNode* temp = node->right;
                delete node;
                return temp;
            }
            else if(node->right == nullptr){
                AVLNode* temp = node->left;
                delete node;
                return  temp;
            }

            AVLNode* temp = minValueNode(node->right);
            node->book = temp->book;
            node->right = removeByYear(node->right, year, temp->book.getTitle());
            return node;
        }   
    }

    node->height = max(height(node->right), height(node->left)) + 1;
    int balance = balanceFactor(node);
    if(balance > 1 && balanceFactor(node->left) >= 0){
        return rightRotate(node);
    }
    else if(balance > 1 && balanceFactor(node->left) < 0){
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) <= 0) {
        return leftRotate(node);
    }
    if (balance < -1 && balanceFactor(node->right) > 0) {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }
    return node;
}

void Library::inOrderTraversalByTitle(AVLNode* node,vector<Book>& books) const{
    if(node!=nullptr) {
        inOrderTraversalByTitle(node->left, books);
        books.push_back(node->book);
        inOrderTraversalByTitle(node->right, books);
    }
    
}

void Library::searchByYear(AVLNode* node,int year, vector<Book>& results){
    if(node==nullptr) return;

    if(node->book.getYear() < year){
        searchByYear(node->right, year, results);
    }
    else if(node->book.getYear() >year){
        searchByYear(node->left, year, results);
    }
    else{
        searchByYear(node->left, year, results);
        results.push_back(node->book);
        searchByYear(node->right, year, results);
    }
}
AVLNode* Library::searchByTitle(AVLNode* node, const string& title){
    if(node == nullptr || node->book.getTitle() == title){
        return node;
    }
    if(title < node->book.getTitle()){
        return searchByTitle(node->left, title);
    }
    return searchByTitle(node->right, title);
}



void Library::destroyTree(AVLNode* node){
    if(node!=nullptr){
        destroyTree(node->left);
        destroyTree(node->right);
        delete node;
    }
}

void Library::addBook(const Book& book){
    titleRoot = insertByTitle(titleRoot,book);
    yearRoot = insertByYear(yearRoot, book);
}

bool Library::removeBook(const string& title){
    AVLNode* node = searchByTitle(titleRoot, title);
    if(node == nullptr) return false;

    int year = node->book.getYear();
    titleRoot = removeByTitle(titleRoot, title);
    yearRoot = removeByYear(yearRoot, year, title);
    return true;
}

bool Library::checkOutBook(const string& title, const string& username){
    AVLNode* node = searchByTitle(titleRoot, title);
    if(node == nullptr) return false;

    bool success = node->book.checkOut(username);
    if(success){
        borrowHistory.push_back({username, title});
    }
    return success;
}

bool Library::returnBook(const string& title, const string& username){
    AVLNode* node = searchByTitle(titleRoot, title);
    return node ? (node->book.returnBook()) : false;
}

vector<Book> Library::getAllBooks() const{
    vector<Book> books;
    inOrderTraversalByTitle(titleRoot, books);
    return books;
}

vector<string> Library::getSpecificBookBorrowHistory(const string& title){
    AVLNode* node = searchByTitle(titleRoot, title);
    return node ? node->book.getBorrowHistory() : vector<string>();
}

vector<pair<string, string>> Library::getOverAllBorrowHistory(){
    return borrowHistory;
}
Book* Library::searchByTitle(const string& title) {
    AVLNode* node = this->searchByTitle(titleRoot, title);
    return node ? &(node->book) : nullptr;
}
vector<Book> Library::searchByYear(int year) {
    vector<Book> results;
    this->searchByYear(yearRoot, year, results);
    return results;
}