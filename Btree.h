#ifndef BTREE_H
#define BTREE_H

#include <iostream>
#include <stdexcept>

struct Node 
{
    int data;
    Node* left;
    Node* right;

    Node(int value) 
        : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree 
{
private:
    Node* root;

    Node* insert(Node* node, int value);
    void inorder(Node* node);
    void preorder(Node* node);
    void postorder(Node* node);
    bool find(Node* node, int value);
    int min(Node* node);
    int max(Node* node);
    Node* minValueNode(Node* node);
    Node* erase(Node* node, int value);

public:
    BinaryTree();
    void insert(int value);
    void inorder();
    void preorder();
    void postorder();
    bool find(int value);
    int min();
    int max();
    void erase(int value);
};

#endif // BTREE_H
