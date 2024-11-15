
#pragma once
#include <iostream>
using namespace std;


struct nodeCs {
    int before;
    int after;
    nodeCs* link;
};


void queueBefore(nodeCs*& first, string input, int len) {
    nodeCs* q = NULL;

    for (int i = 0; i < len; i++) {
        nodeCs* p = new nodeCs;
        p->before = ((int)input[i]) % 97;
        p->after = 0;
        p->link = NULL;

        if (first == NULL && q == NULL) {
            first = p;
            q = p;
        }
        else {
            q->link = p;
            q = p;
        }
    }
}


void encodeDecode(nodeCs*& first, int shift, string direc) {
    int new_idx;
    shift %= 26;

    for (nodeCs* temp = first; temp != NULL; temp = temp->link) {
        if (direc == "encode") {
            new_idx = (temp->before + shift) % 26;
        }
        else {
            new_idx = (temp->before - shift) % 26;
            if (new_idx < 0) { new_idx += 26; }
        }
        temp->after = new_idx;
    }
}


void codeReader(nodeCs* first) {
    for (nodeCs* temp = first; temp != NULL; temp = temp->link) {
        int idx = temp->after + 97;
        char casting = static_cast<char>(idx);
        cout << casting;
    }
    cout << endl;
}


void picCipher() {
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
}


void play_caesar() {
    picCipher();
    string next = "yes";

    while (next != "no") {

        // declare
        nodeCs* first = NULL;
        int shift, len;
        string direc, message;

        // input
        cout << "\nType 'encode' to encrypt, type 'decode' to decrypt: "; cin >> direc;
        cout << "Type your message in lower case: "; cin >> message;
        cout << "Type the shift number: "; cin >> shift;
        len = message.length();

        // output
        queueBefore(first, message, len);
        encodeDecode(first, shift, direc);
        cout << "Here's the encode result: "; codeReader(first);

        // loop
        cout << "\nType 'yes' if you want to go again. Otherwise type 'no': "; cin >> next;
    }
}