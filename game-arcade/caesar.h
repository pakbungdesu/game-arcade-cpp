
#pragma once
#include <iostream>
#include <vector>
using namespace std;


vector<int> process(vector<char> letter, string message, int shift, string direction) {
    vector<int> res;
    int new_idx;
    shift %= 26;

    for (char ele : message) {
        for (int i = 0; i < letter.size(); i++) {
            if (letter[i] == ele) {
                if (direction == "encode") {
                    new_idx = (i + shift) % 26;

                }
                else { // decode
                    new_idx = (i - shift) % 26;

                    if (new_idx < 0) {
                        new_idx += 26;
                    }
                }
                res.push_back(new_idx);
            }
        }
    }
    return res;
}

void reader(vector<char> letter, vector<int> idx, string& output) {
    for (char ele : idx) {
        output += letter[ele];
    }
}

void play_caesar() {

    cout << "   .o88b.  .d8b.  d88888b .d8888.  .d8b.  d8888b.  \n"
        "  d8P  Y8 d8' `8b 88'     88'  YP d8' `8b 88  `8D  \n"
        "  8P      88ooo88 88ooooo `8bo.   88ooo88 88oobY'  \n"
        "  8b      88   88 88    `     88  88   88 8b       \n"
        "  Y8b  d8 88   88 88.     db   8D 88   88 88 `88.  \n"
        "   `Y88P' YP   YP Y88888P `8888Y' YP   YP 88   YD  \n"
        "                                                   \n"
        "                                                   \n"
        "   .o88b. d888888b d8888b. db   db d88888b d8888b. \n"
        "  d8P  Y8   `88'   88  `8D 88   88 88'     88  `8D \n"
        "  8P         88    88oodD' 88ooo88 88ooooo 88oobY' \n"
        "  8b         88    88      88   88 88      88`8b   \n"
        "  Y8b  d8   .88.   88      88   88 88.     88 `88. \n"
        "   `Y88P' Y888888P 88      YP   YP Y88888P 88   YD \n";

    vector<char> letter = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

    while (true) {

        // declare
        int shift;
        string next, direction, message, output = "";
        // input
        cout << "\n\nType 'encode' to encrypt, type 'decode' to decrypt:\n"; cin >> direction;
        cout << "Type your message:\n"; cin >> message;
        cout << "Type the shift number:\n"; cin >> shift;

        // output
        vector<int> vector_idx = process(letter, message, shift, direction);
        reader(letter, vector_idx, output);
        cout << "Here's the encode result: " << output;

        // loop
        cout << "\nType 'yes' if you want to go again. Otherwise type 'no'.\n"; cin >> next;
        if (next == "no") {
            break;
        }
    }
}