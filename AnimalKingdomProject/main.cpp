#include "AnimalHierarchy.h"
#include "LinkedList.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));

    Ecosystem<Feline> cats;
    cats.addAnimal(make_shared<Feline>("Lion", "Panthera leo", 5));
    cats.addAnimal(make_shared<Feline>("Tiger", "Panthera tigris", 3));
    cats.addAnimal(make_shared<Feline>("Leopard", "Panthera pardus", 4));

    cout << "\n=== ECOSYSTEM ===";
    cats.showAllAnimals();

    cout << "\n\n--- Singly Linked List (Ages) ---\n";
    SinglyLinkedList<int> sll;
    for (auto& a : cats.getAnimals())
        sll.insertAtEnd(a->getAge());
    sll.display();
    sll.reverseIterative();
    sll.display();

    cout << "\n\n--- Doubly Linked List (Animal Names) ---\n";
    DoublyLinkedList<string> dll;
    for (auto& a : cats.getAnimals())
        dll.insertAtEnd(a->getName());
    dll.displayForward();
    dll.displayBackward();

    cout << "\n\n--- Binary Search Tree (Ages) ---\n";
    BinarySearchTree<int> bst;
    for (auto& a : cats.getAnimals())
        bst.insert(a->getAge());
    bst.displayInorder();
    bst.searchValue(4);
    bst.searchValue(6);

    cout << "\n✅ Demonstration complete.\n";
    return 0;
}
