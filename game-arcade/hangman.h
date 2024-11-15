
#pragma once
#include <iostream>
#include <random>
#include "data.h"
using namespace std;


struct nodeHang {
    char thispos;
    int show; // 1 for show, 0 for not
    nodeHang* link;
};


void picHang(int index) {
    string all_pics[7] = {
          "  +---+\n"
          "  |   |\n"
          "  O   |\n"
          " /|\\  |\n"
          " / \\  |\n"
          "      |\n"
          "=========\n",

         "   +---+\n"
         "   |   |\n"
         "   O   |\n"
         "  /|\\  |\n"
         "  /    |\n"
         "       |\n"
         " =========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|\\  |\n"
        "      |\n"
        "      |\n"
        "=========\n",

        "  +---+\n"
        "  |   |\n"
        "  O   |\n"
        " /|   |\n"
        "      |\n"
        "      |\n"
        "=========\n",

      "  +---+\n"
      "  |   |\n"
      "  O   |\n"
      "  |   |\n"
      "      |\n"
      "      |\n"
      "=========\n",

      "  +---+\n"
      "  |   |\n"
      "  O   |\n"
      "      |\n"
      "      |\n"
      "      |\n"
      "=========\n",

      "  +---+\n"
      "  |   |\n"
      "      |\n"
      "      |\n"
      "      |\n"
      "      |\n"
      "=========\n"
    };

    cout << all_pics[index];
}


void QueueChar(nodeHang*& first, string myword, int len) {
    // random device
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1);
    nodeHang* q = NULL;

    for (int i = 0; i < len; i++) {

        nodeHang* p = new nodeHang;
        p->thispos = myword[i];
        p->link = NULL;

        int open = dis(gen);
        p->show = open;

        if (first == NULL) {
            first = p;
            q = p;
        }
        else {
            q->link = p;
            q = p;
        }
    }
}


void displayChar(nodeHang* first) {
    for (nodeHang* temp = first; temp != NULL; temp = temp->link) {
        if (temp->show == 1) {
            cout << temp->thispos << " ";
        }
        else { cout << " _ "; }
    }
    cout << endl;
}


void checkAndUpdate(nodeHang* first, char guess, int& lives) {
    bool found = false;

    for (nodeHang* temp = first; temp != NULL; temp = temp->link) {
        if (temp->thispos == guess) {
            found = true;
            temp->show = 1;
        }
    }

    if (found == true) {
        cout << "You're right!" << endl;
    }
    else {
        lives -= 1;
        cout << "You're incorrect. There is no " << guess << " in the word!" << endl;
    }
}

bool completeOrNot(nodeHang* first) {
    bool complete = true;

    for (nodeHang* temp = first; temp != NULL; temp = temp->link) {
        if (temp->show != 1) { complete = false; }
    }
    if (complete == true) { cout << "You win! Congratulation." << endl; }
    return complete;
}


void play_hangman(){
    // random device
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 1022);
    int idx = dis(gen);

    string myword = words(idx);
    int len = myword.length();
    nodeHang* first = NULL;

    QueueChar(first, myword, len);
    bool complete = false;
    char guess;
    int lives = 7;

    while (lives > 0 && complete != true) {
        cout << endl;
        if (lives < 7) { picHang(lives); }
        displayChar(first);
        cout << "Your lives: " << lives << endl;
        cout << "Guess a letter: "; cin >> guess;
        checkAndUpdate(first, guess, lives);
        complete = completeOrNot(first);
    }

    cout << endl;
    if (lives == 0) { cout << "You lost! "; }
    cout << "The word is " << myword << endl;
    delete(first);
}