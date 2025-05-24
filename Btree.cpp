#include "Btree.h"

// Կոնստրուկտոր
BinaryTree::BinaryTree() : root(nullptr) {}

// Ներքին insert ֆունկցիա
Node* BinaryTree::insert(Node* node, int value) 
{
    if (!node) return new Node(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else
        node->right = insert(node->right, value);
    return node;
}

// print inorder 
void BinaryTree::inorder(Node* node) 
{
    if (!node) return;

    inorder(node->left);

    std::cout << node->data << " ";

    inorder(node->right);
}

void BinaryTree::preorder(Node* node) 
{
    if (!node) return;

    std::cout << node->data << " ";

    preorder(node->left);

    preorder(node->right);
}

void BinaryTree::postorder(Node* node) 
{
    if (!node) return;

    postorder(node->left);

    postorder(node->right);

    std::cout << node->data << " ";
}

bool BinaryTree::find(Node* node, int value) 
{
    if (!node) return false;

    if (value == node->data) return true;

    if (value < node->data)
        return find(node->left, value);
    else
        return find(node->right, value);
}

int BinaryTree::min(Node* node) 
{
    if (!node) throw std::runtime_error("Tree is empty");

    while (node->left) 
        node = node->left;

    return node->data;
}

int BinaryTree::max(Node* node) 
{
    if (!node) throw std::runtime_error("Tree is empty");

    while (node->right) 
        node = node->right;
    return node->data;
}

Node* BinaryTree::minValueNode(Node* node) 
{
    Node* current = node;

    while (current && current->left)
        current = current->left;
    return current;
}

Node* BinaryTree::erase(Node* node, int value) 
{
    if (!node) return node;

    if (value < node->data)
        node->left = erase(node->left, value);
    else if (value > node->data)
        node->right = erase(node->right, value);
    else {
        //if find the node 
        if (!node->left) 
        {
            Node* temp = node->right;
            delete node;
            return temp;
        } 
        else if (!node->right) 
        {
            Node* temp = node->left;
            delete node;
            return temp;
        }

        Node* temp = minValueNode(node->right);
        node->data = temp->data;
        node->right = erase(node->right, temp->data);
    }
    return node;
}

// public metodes
void BinaryTree::insert(int value) { root = insert(root, value); }
void BinaryTree::inorder() { inorder(root); std::cout << std::endl; }
void BinaryTree::preorder() { preorder(root); std::cout << std::endl; }
void BinaryTree::postorder() { postorder(root); std::cout << std::endl; }
bool BinaryTree::find(int value) { return find(root, value); }
int BinaryTree::min() { return min(root); }
int BinaryTree::max() { return max(root); }
void BinaryTree::erase(int value) { root = erase(root, value); }


