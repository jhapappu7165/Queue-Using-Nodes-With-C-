#include "Pappu_Jha_QUEUENODE.h"
#include "Pappu_Jha_Queue.h"
#include "Pappu_Jha_Simulation.h"

#include <iostream>
#include <string>
using namespace std;

int main() {
    while (true) {
        vector<string> list;
        list.clear();

        int num_people;
        cout << "How many are you? ";
        cin >> num_people;

        for (int i=0; i<num_people; i++) {
            string name;
            cout << "Enter Person " << i+1 << "'s name: ";
            cin >> name;
            list.push_back(name);
        }

        int skip_num;
        cout << "Give me a number: ";
        cin >> skip_num;

        cout << "Now we begin....";

        Simulation obj(list, skip_num);

        
        cout << endl << "Kill List: " << endl;
        vector<string> eliminated = obj.GetEliminationList();

        for (int k = 0; k < eliminated.size(); k++){
            cout << '\t' << k+1 << "." << eliminated[k] << endl;
        }

        cout << endl << endl;
        cout << "*********************************" << endl;
        cout << "Survivor: " << obj.GetSurvivor() << endl;
        cout << "*********************************" << endl;

        cout << endl << endl;
        cout << "Want to run another round?" << endl;
        cout << '\t' << "For Yes, enter 1." << endl;
        cout << '\t' << "For No, enter any other number." << endl;
        cout << "--: ";

        int decisive_num;
        cin >> decisive_num;
        if (decisive_num == 1)
            continue;
        else
            break;
    }
}
