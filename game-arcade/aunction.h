
#pragma once
#include <iostream>
#include <map> // unordered map
using namespace std;


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

void play_aunction() {

    picAunc();

    string other = "yes", name, max_name;
    int money, max_bid = 0;
    std::map <string, int> bid;

    while (other == "yes") {
        cout << "\n\nWhat is your name?: "; cin >> name;
        cout << "What is your bit?: $"; cin >> money;
        bid.insert(make_pair(name, money));

        cout << "Are there any other bidders? Type 'yes' or 'no': "; cin >> other;
    }

    for (const auto& pair : bid) {
        if (pair.second > max_bid) {
            max_bid = pair.second;
            max_name = pair.first;
        }
    }

    cout << "\n\nThe winner is " << max_name << " with a bid of $" << max_bid;
}
