
#pragma once
#include <iostream>;
using namespace std;


void greeting() {
    cout <<
        " ____            _      ____                         ____       _                      _\n"
        "|  _ \\ ___   ___| | __ |  _ \\ __ _ _ __   ___ _ __  / ___|  ___(_)___ ___  ___  _ __  | |\n"
        "| |_) / _ \\ / __| |/ / | |_) / _` | '_ \\ / _ \\ '__| \\___ \\ / __| / __/ __|/ _ \\| '__| | |\n"
        "|  _ < (_) | (__|   <  |  __/ (_| | |_) |  __/ |     ___) | (__| \\__ \\__ \\ (_) | |    |_|\n"
        "|_| \\_\\___/ \\___|_|\\_\\ |_|   \\__,_| .__/ \\___|_|    |____/ \\___|_|___/___/\\___/|_|    (_)\n"
        "                                  |_|                                                    \n";

}


void picRPS(int pic_index) {
    string rock_pic =
        "    _______\n"
        "---'   ____)\n"
        "      (_____)\n"
        "      (_____)\n"
        "      (____)\n"
        "---.__(___)\n";

    string paper_pic =
        "     _______\n"
        "---'    ____)____\n"
        "           ______)\n"
        "          _______)\n"
        "         _______)\n"
        "---.__________)\n";

    string scissor_pic =
        "    _______\n"
        "---'   ____)____\n"
        "          ______)\n"
        "       __________)\n"
        "      (____)\n"
        "---.__(___)\n";

    string all_pics[3] = { rock_pic, paper_pic, scissor_pic };
    cout << all_pics[pic_index];
}


void to_lower(string& sometxt) {
    for (auto& x : sometxt) {
        x = tolower(x);
    }
}


int calculate_score(int user1, int user2) {
    int score[3][3] = { {1, 0, 2}, {2, 1, 0}, {0, 2, 1} };
    return score[user1][user2];
}


int hand_tonum(string user_hand) {
    if (user_hand == "rock") {
        return 0;
    }
    else if (user_hand == "paper") {
        return 1;
    }
    else {
        return 2;
    }
}


void play_RPS() {

    greeting();

    int i = 1, total_user = 0, total_bot = 0;
    int user_num, user_score, bot_score;
    string con, user_hand;

    cout << "\nDo you want to continue or stop? "; cin >> con;
    to_lower(con);

    while (con != "stop") {

        cout << "\nRound " << i;
        cout << "\nWhat do you choose?: "; cin >> user_hand;

        to_lower(user_hand);
        user_num = hand_tonum(user_hand);

        int bot_hand = rand() % 3;
        cout << "\nYour hand:\n";
        picRPS(user_num);
        cout << "\nBot hand:\n";
        picRPS(bot_hand);

        user_score = calculate_score(user_num, bot_hand);
        bot_score = calculate_score(bot_hand, user_num);

        cout << "\nYour score +" << user_score;
        cout << "\nBot score +" << bot_score;

        total_user += user_score;
        total_bot += bot_score;
        cout << "\nDo you want to continue or stop? "; cin >> con;
        to_lower(con);
        i += 1;
    }

    cout << "\nYour total score: " << total_user;
    cout << "\nBot' total score: " << total_bot;

    if (total_user > total_bot) {
        cout << "\nYou win! Congratulation.";
    }
    else if (total_user == total_bot) {
        cout << "\nIt's a tied match.";
    }
    else {
        cout << "\nYou lost. Wanna give another try?";
    }
}