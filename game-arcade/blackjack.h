
#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;


void picBJ() {
    cout <<
        "   _______ _______ _______ _______ _______ _______ _______ _______ _______ \n"
        "  |\\     /|\\     /|\\     /|\\     /|\\     /|\\     /|\\     /|\\     /|\\     /|\n"
        "  | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |\n"
        "  | |   | | |   | | |   | | |   | | |   | | |   | | |   | | |   | | |   | |\n"
        "  | |B  | | |L  | | |A  | | |C  | | |K  | | |J  | | |A  | | |C  | | |K  | |\n"
        "  | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ | +---+ |\n"
        "  |/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|/_____\\|\n";
}

// for player
void rand1(vector<int>& all_deck, vector<int>& curr_hand, int how_many) {

    for (int i = 0; i < how_many; i++) {
        // random 
        int size = all_deck.size();
        srand(time(0));
        int rand_idx = rand() % size;

        // append curr hand
        curr_hand.push_back(all_deck[rand_idx]);

        // check condition
        int total = 0;
        int idx11 = -1;
        for (int i = 0; i < curr_hand.size(); i++) {
            total += curr_hand[i];
            if (curr_hand[i] == 11) {
                idx11 = i;
            }
        }

        if (total > 21 && idx11 != -1) {
            curr_hand[idx11] = 1;
        }

        // remove from all deck
        all_deck.erase(all_deck.begin() + rand_idx);
    }
}


// for dealer
void rand2(vector<int>& all_deck, vector<int>& curr_hand) {

    while (true) {
        // random 
        int size = all_deck.size();
        srand(time(0));
        int rand_idx = rand() % size;

        // append curr hand
        curr_hand.push_back(all_deck[rand_idx]);

        // remove from all deck
        all_deck.erase(all_deck.begin() + rand_idx);

        // draw as long as total < 17
        int total = 0;
        for (int ele : curr_hand) {
            total += ele;
        }

        if (total > 17) {
            break;
        }
    }
}


void curr_score(vector<int> curr_hand, string add_text, int& curr_score) {
    curr_score = 0;
    cout << "\n" << add_text << ": [";

    for (int ele : curr_hand) {
        curr_score += ele;
        cout << ele << ",";
    }
    cout << "] current score: " << curr_score;
}


void check_bj(int curr_score, bool& bj) {
    if (curr_score == 21) {
        bj = true;
    }
}

void check_score(int sum_player, int sum_dealer) {
    if (sum_player == 21) {
        cout << "\nYou win with a Blackjack.";
    }
    else if (sum_dealer == 21) {
        cout << "\nOpponent got a Blackjack. You lose.";
    }
    else if (sum_player < 21 && sum_dealer < 21) {
        if (sum_player > sum_dealer) {
            cout << "\nYou win.";
        }
        else if (sum_player < sum_dealer) {
            cout << "\nYou lose.";
        }
        else {
            cout << "\nIt is a push.";
        }
    }
    else if (sum_player < 21) {
        cout << "\nOpponent went over. You win.";
    }
    else {
        cout << "\nYou went over. You lose.";
    }
}


void play_blackjack() {

    picBJ();
    bool blackjack = false;
    string play, another;
    cout << "\nDo you want to play Blackjack? Type 'y' or 'n': "; cin >> play;

    while (play == "y") {

        vector<int> deck = { 11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10 };
        vector<int> player, dealer;
        int player_sc, dealer_sc;

        rand1(deck, player, 2);
        curr_score(player, "Your card", player_sc);

        rand1(deck, dealer, 1);
        curr_score(dealer, "Bot's card", dealer_sc);

        check_bj(player_sc, blackjack);

        cout << "\nType 'y' to get another card, type 'n' to pass: "; cin >> another;

        while (another == "y" && blackjack == false) {
            rand1(deck, player, 1);
            curr_score(player, "Your card", player_sc);

            check_bj(player_sc, blackjack);
            cout << "\nType 'y' to get another card, type 'n' to pass: "; cin >> another;
        }

        if (blackjack == false) {
            rand2(deck, dealer);
            curr_score(dealer, "Bot's card", dealer_sc);
        }

        check_score(player_sc, dealer_sc);

        cout << "\nDo you want to go over again? Type 'y' or 'n': "; cin >> play;
    }
}