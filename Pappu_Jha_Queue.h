/*
Name: Pappu Jha
NetID: w10168315
*/

#pragma once
#include "Pappu_Jha_QUEUENODE.h"
#include <iostream>
#include <vector>
using namespace std;

class Queue {
protected:
    Node* front = nullptr;
    Node* back = nullptr;
    int node_count;

public:
    Queue() {
        node_count = 0;
    }
    
    void Enqueue (string name) {
        Node* vertex = new Node();
        vertex->data = name;
        if (node_count == 0) {
            front = back = vertex;
        }
        else {
            vertex->prev = back;
            back->next = vertex;
            back = vertex;
        }
        node_count++;
        return;
    }

    bool Dequeue() {
        if (node_count <= 1) {
            return false;
        }
        else {
            Node* temp = front; 
            front = front->next;
            delete temp;
            temp = nullptr;
            front->prev = nullptr;
            node_count--;
            return true;
        }
    }

    int GetCount() {
        return node_count;
    }

    void PrintNames() {
        Node* just = front;
        while (just!=nullptr) {
            cout << just->data << " --> ";
            just = just->next;
        }
    }
};
