/*
Name: Pappu Jha
NetID: w10168315
*/

#pragma once
#include "Pappu_Jha_QUEUENODE.h"
#include "Pappu_Jha_Queue.h"

#include <iostream>
#include <string>
using namespace std;

class Simulation:private Queue {
private:
    string survivor;
    int skip_number;
    vector<string> listPeople;
    vector<string> eliminated;

public:
    Simulation(const vector<string>& list, int num) {
        listPeople.clear();
        listPeople = list;
        skip_number = num;

        RunNewSimulation();
    }

    void RunNewSimulation() {
        eliminated.clear();

        Node* current = front;
        Node* temp = nullptr;

        while (current!=nullptr) {
            temp = current;
            current = current->next;
            delete temp;
        }

        front = back = nullptr;

        RunSimulation();
    }

    void RunSimulation() {
        for (int i=0; i<listPeople.size(); i++) {
            Enqueue(listPeople[i]);
        }

        bool status;
        string dequeued_name;

        while (node_count > 1) {
            for (int j = 0; j<skip_number-1; j++) {
                dequeued_name = front->data;

                status = Dequeue();
                if (status) {
                    Enqueue (dequeued_name);
                }
                else {
                    break;
                }
            }
            if (status!=false) {
                dequeued_name = front->data;
                status = Dequeue();
                if (status)
                    eliminated.push_back(dequeued_name);
            }
        }
    }

    vector<string> GetEliminationList() {
        return eliminated;
    }

    string GetSurvivor() {
        if (front) {
            return front->data;
        }
        else
            return "No survivor";
    }
};
