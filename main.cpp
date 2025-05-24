#include "Btree.h"

int main() {
    BinaryTree tree;

    // Ծառի մեջ մի քանի ամբողջ թվեր ավելացնել
    tree.insert(50);
    tree.insert(30);
    tree.insert(20);
    tree.insert(40);
    tree.insert(70);
    tree.insert(60);
    tree.insert(80);

    // Ցուցադրել ծառի բովանդակությունը
    std::cout << "Inorder traversal: ";
    tree.inorder();

    std::cout << "Preorder traversal: ";
    tree.preorder();

    std::cout << "Postorder traversal: ";
    tree.postorder();

    std::cout << "Min value: " << tree.min() << std::endl;
    std::cout << "Max value: " << tree.max() << std::endl;

    // Տեղեկություն որոնել
    int searchValue = 40;
    std::cout << "Searching for " << searchValue << ": "
              << (tree.find(searchValue) ? "Found" : "Not found") << std::endl;

    // Տվյալ հեռացնել
    tree.erase(40);
    std::cout << "After deleting 40, inorder traversal: ";
    tree.inorder();

    return 0;
}
