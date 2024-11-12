
#pragma once
#include <iostream>
#include <map>
using namespace std;


void picCal() {
    cout <<
        "   _____________________                                                                                           \n"
        "  |  _________________  |                                                                                          \n"
        "  | | Pythonista   0. | |  .----------------.  .----------------.  .----------------.  .----------------.          \n"
        "  | |_________________| | | .--------------. || .--------------. || .--------------. || .--------------. |         \n"
        "  |  ___ ___ ___   ___  | | |     ______   | || |      __      | || |   _____      | || |     ______   | |         \n"
        "  | | 7 | 8 | 9 | | + | | | |   .' ___  |  | || |     /  \\     | || |  |_   _|     | || |   .' ___  |  | |        \n"
        "  | |___|___|___| |___| | | |  / .'   \\_|  | || |    / /\\ \\    | || |    | |       | || |  / .'   \\_|  | |     \n"
        "  | | 4 | 5 | 6 | | - | | | |  | |         | || |   / ____ \\   | || |    | |   _   | || |  | |         | |        \n"
        "  | |___|___|___| |___| | | |  \\ `.___.'\\  | || | _/ /    \\ \\_ | || |   _| |__/ |  | || |  \\ `.___.'\\  | |   \n"
        "  | | 1 | 2 | 3 | | x | | | |   `._____.'  | || ||____|  |____|| || |  |________|  | || |   `._____.'  | |         \n"
        "  | |___|___|___| |___| | | |              | || |              | || |              | || |              | |         \n"
        "  | | . | 0 | = | | / | | | '--------------' || '--------------' || '--------------' || '--------------' |         \n"
        "  | |___|___|___| |___| |  '----------------'  '----------------'  '----------------'  '----------------'          \n"
        "  |_____________________|                                                                                          \n";

}

void calculator(double& n1, double& n2, int& process, double& res) {
    if (process == 1) {
        res = n1 + n2;
    }
    else if (process == 2) {
        res = n1 - n2;
    }
    else if (process == 3) {
        res = n1 * n2;
    }
    else {
        res = n1 / n2;
    }
}

void play_calculator() {

    picCal();

    std::map <int, string> display;
    display.insert(make_pair(1, " + "));
    display.insert(make_pair(2, " - "));
    display.insert(make_pair(3, " * "));
    display.insert(make_pair(4, " / "));
    double num1, num2, result;
    string con = "y";
    int pickProcess;

    cout << "\nEnter the first number: "; cin >> num1;

    while (con == "y") {
        cout << "Enter the second number: "; cin >> num2;
        cout << "Pick one operation\nPress 1: Add\nPress 2: Subtract\nPress 3: Multiply\nPress 4: Divide\n";
        cin >> pickProcess;

        calculator(num1, num2, pickProcess, result);
        cout << num1 << display[pickProcess] << num2 << " = " << result;

        cout << "\ntype 'y' to continue calculating with " << result << ", type 'n' to exit: \n"; cin >> con;
        num1 = result;
    }
}