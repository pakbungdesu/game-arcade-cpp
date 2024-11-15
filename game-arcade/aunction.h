
#pragma once
#include <iostream>
using namespace std;


struct nodeAunc {
    string name;
    double bid;
    nodeAunc* link;
};


void picAunc() {
    cout << "               ___________                                \n"
        "               \\         /                               \n"
        "                )_______(                                 \n"
        "                |'''''''|_.-._,.---------.,_.-._          \n"
        "                |       | | |               | | ''-.      \n"
        "                |       |_| |_             _| |_..-'      \n"
        "                |_______| '-' `'---------'` '-'           \n"
        "                )'''''''(                                 \n"
        "               /_________\\                               \n"
        "             .-------------.                              \n"
        "            /_______________\\                            \n";
}


void Enqueue(nodeAunc*& first) {

    string other = "yes";
    nodeAunc* q = NULL;
    while (other == "yes") {
        nodeAunc* p = new nodeAunc;
        cout << "\nWhat is your name?: "; cin >> p->name;
        cout << "What is your bit?: $"; cin >> p->bid;
        p->link = NULL;

        if (first == NULL && q == NULL) {
            first = p;
            q = p;
        }
        else {
            q->link = p;
            q = p;
        }
        cout << "Are there any other bidders? Type 'yes' or 'no': "; cin >> other;
    }
}


void Process(nodeAunc* first, string& max_name, double& max_bid) {

    while (first != NULL) {
        if (first->bid > max_bid) {
            max_bid = first->bid;
            max_name = first->name;
        }
        first = first->link;
    }
}


void play_aunction() {
    picAunc();
    string other = "yes", max_name;
    double max_bid = 0.0;
    nodeAunc* first = NULL;

    Enqueue(first);
    Process(first, max_name, max_bid);
    cout << "\nThe winner is " << max_name << " with a bid of $" << max_bid;
    delete(first);
}
