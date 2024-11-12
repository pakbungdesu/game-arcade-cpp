
#pragma once
#include <iostream>
#include <ctime>
#include <string>
using namespace std;


void play_numberGuess() {

    cout <<
        "   _   _   _   _   _   _    _   _   _   _   _   _   _   _\n"
        "  / \\ / \\ / \\ / \\ / \\ / \\  / \\ / \\ / \\ / \\ / \\ / \\ / \\ / \\\n"
        " ( N | u | m | b | e | r )( G | u | e | s | s | i | n | g )\n"
        "  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/  \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/ \\_/";

    string level;
    int lives, guess;

    cout << "\n\nI'm thinking of a number between 1 and 100.\n";
    do {
        cout << "Choose a difficulty. Type 'easy' or 'hard'\n";
        cin >> level;
    } while (level != "easy" && level != "hard");

    lives = (level == "easy") ? 10 : 7;

    srand(time(0));
    int n = rand() % 101;

    while (lives > 0) {
        cout << "You have " << lives << " attempts remaining to guess the number\n";
        cout << "Make a guess\n";

        while (!(cin >> guess)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        if (guess != n) {
            if (lives > 1) {
                if (guess > n) { cout << "Too high. Guess again.\n"; }
                else { cout << "Too low. Guess again.\n"; }
            }
            lives--;
        }
        else {
            cout << "You got it! ";
            break;
        }
    }

    if (lives == 0) {
        cout << "You've run out of lives! Better luck next time.\n";
    }
    cout << "The answer was " << n;
}