#pragma once
#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string data;
    Node* next;
    Node* prev;

    Node (Node* next = nullptr, Node* prev = nullptr) {
        this->next = next;
        this->prev = prev;
    }
};
