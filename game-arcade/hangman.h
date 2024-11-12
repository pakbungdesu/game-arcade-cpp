
#pragma once
#include <iostream>
#include <cstdlib> // random library
#include <ctime> // change the random every time
#include <cmath> // for ceil
#include <vector>
#include "data.h"
using namespace std;


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

bool contain1(vector <int> find_array, int check_idx) {
    for (int f : find_array) {
        if (f == check_idx) {
            return true;
        }
    }
    return false;
}

bool contain2(string word, char guess_check) {
    for (char x : word) {
        if (x == guess_check) {
            return true;
        }
    }
    return false;
}


void display(string myword, int w_length, vector <int> show_char) {
    cout << "\n";
    for (int i = 0; i < w_length; i++) {
        if (contain1(show_char, i)) {
            cout << myword[i] << " ";
        }
        else {
            cout << "_ ";
        }
    }
}


vector <int> update_show(string myword, int w_length, vector <int> show_char, char guess) {
    vector <int> unique;

    for (int i = 0; i < w_length; i++) {
        if (myword[i] == guess) {
            show_char.push_back(i);
        }
    }

    for (int j : show_char) {
        if (!contain1(unique, j)) {
            unique.push_back(j);
        }
    }
    return unique;
}

void play_hangman() {

    // random a word
    srand(time(0));
    int w = rand() % 1023;
    string myword = words(w);
    int lengthW = myword.length();

    // specify the shown index
    int times = ceil(lengthW * 0.4);
    vector <int> show_letter;

    for (int i = 0; i < times; i++) {
        int idx = rand() % lengthW;
        show_letter.push_back(idx);
    }


    char guess;
    int lives = 7;

    while (lives > 0) {
        display(myword, lengthW, show_letter);
        cout << "\nYour lives: " << lives;
        cout << "\nGuess a letter: "; cin >> guess;

        bool check = contain2(myword, guess);
        if (check == false) {
            cout << "\nYou're incorrect. There is no " << guess << " in the word!\n";
            lives -= 1;
            picHang(lives);
        }
        else {
            cout << "\nYou're right!\n";
            show_letter = update_show(myword, lengthW, show_letter, guess);
        }

        if (show_letter.size() == lengthW) {
            display(myword, lengthW, show_letter);
            cout << "\nYou win! Congratulation.";
            break;
        }
    }
    if (lives == 0) {
        cout << "\nYou lost!\nThe word is " << myword;
    }
}