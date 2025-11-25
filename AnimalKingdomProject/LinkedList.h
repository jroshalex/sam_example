#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
class SinglyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head;
public:
    SinglyLinkedList() : head(nullptr) {}
    void insertAtEnd(T value) {
        Node* newNode = new Node(value);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << "Inserted: " << value << endl;
    }
    void display() const {
        cout << "\nSLL: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " -> ";
            temp = temp->next;
        }
        cout << endl;
    }
    void reverseIterative() {
        Node *prev = nullptr, *curr = head, *next = nullptr;
        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        head = prev;
    }
};

template <typename T>
class DoublyLinkedList {
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(T d) : data(d), next(nullptr), prev(nullptr) {}
    };
    Node* head;
public:
    DoublyLinkedList() : head(nullptr) {}
    void insertAtEnd(T value) {
        Node* newNode = new Node(value);
        if (!head) head = newNode;
        else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << "Inserted: " << value << endl;
    }
    void displayForward() const {
        cout << "\nDLL Forward: ";
        Node* temp = head;
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
    void displayBackward() const {
        if (!head) return;
        Node* temp = head;
        while (temp->next) temp = temp->next;
        cout << "DLL Backward: ";
        while (temp) {
            cout << temp->data;
            if (temp->prev) cout << " <-> ";
            temp = temp->prev;
        }
        cout << endl;
    }
};
