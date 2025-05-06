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