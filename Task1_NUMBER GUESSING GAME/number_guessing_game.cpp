#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(static_cast<unsigned>(time(nullptr)));
    int secretNumber = rand() % 100 + 1;
    
    int guess;
    int attempts = 0;
    const int maxAttempts = 6;

    cout << "-------------------------------Welcome to the Guess the Number Game!---------------------------------" << endl;

    while (attempts < maxAttempts) {
        cout << "Enter your guess (Attempt " << attempts + 1 << "/" << maxAttempts << "): ";
        cin >> guess;
        attempts++;

        switch (guess) {
            case 0:
            case 101:
                cout << "Please enter a number between 1 and 100." << endl;
                break;
            case 1000:
                cout << "Exiting the game. The secret number was " << secretNumber << "." << endl;
                return 0;
            default:
                if (guess < secretNumber) {
                    cout << "Too low! Try again." << endl;
                } else if (guess > secretNumber) {
                    cout << "Too high! Try again." << endl;
                } else {
                    cout << "Congratulations! You guessed the number " << secretNumber << " in " << attempts << " attempts." << endl;
                    return 0;
                }
        }
    }
    cout << "Sorry, you've used all " << maxAttempts << " attempts. The secret number was " << secretNumber << "." << endl;

    return 0;
}
