// ==========================================
// Mini Project: Number Guessing Game in C++
// ==========================================

#include <iostream>
#include <random>      // for random number generation
#include <limits>      // for input validation
#include <string>

using namespace std;

// Function to safely take integer input
int getIntegerInput() {
    int value;
    while (true) {
        if (cin >> value) {
            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        } else {
            // Invalid input
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter an integer: ";
        }
    }
}

// Function to generate random number in given range
int generateRandomNumber(int min, int max) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main() {
    cout << "=====================================\n";
    cout << "       NUMBER GUESSING GAME          \n";
    cout << "=====================================\n";

    bool playAgain = true;

    while (playAgain) {
        int minRange = 1, maxRange = 100, maxAttempts = 7;
        int choice;

        cout << "\nSelect Difficulty Level:\n";
        cout << "1. Easy   (Range: 1–50, 10 attempts)\n";
        cout << "2. Medium (Range: 1–100, 7 attempts)\n";
        cout << "3. Hard   (Range: 1–500, 10 attempts)\n";
        cout << "Enter choice (1–3): ";
        choice = getIntegerInput();

        if (choice == 1) { maxRange = 50; maxAttempts = 10; }
        else if (choice == 2) { maxRange = 100; maxAttempts = 7; }
        else if (choice == 3) { maxRange = 500; maxAttempts = 10; }
        else {
            cout << "Invalid choice! Defaulting to Medium.\n";
            maxRange = 100; maxAttempts = 7;
        }

        int secretNumber = generateRandomNumber(minRange, maxRange);
        int attempts = 0;
        bool guessed = false;

        cout << "\nI have selected a number between " << minRange << " and " << maxRange << ".\n";
        cout << "You have " << maxAttempts << " attempts to guess it!\n\n";

        while (attempts < maxAttempts) {
            cout << "Attempt " << (attempts + 1) << "/" << maxAttempts << " - Enter your guess: ";
            int guess = getIntegerInput();

            if (guess < minRange || guess > maxRange) {
                cout << "Please enter a number between " << minRange << " and " << maxRange << ".\n";
                continue;
            }

            attempts++;

            if (guess == secretNumber) {
                guessed = true;
                int score = (maxAttempts - attempts + 1) * 10;
                cout << "\n🎉 Congratulations! You guessed the number in " << attempts << " attempt(s)!\n";
                cout << "Your Score: " << score << endl;
                break;
            } else if (guess < secretNumber) {
                cout << "Too Low! Try again.\n";
            } else {
                cout << "Too High! Try again.\n";
            }
        }

        if (!guessed) {
            cout << "\n❌ Out of attempts! The correct number was " << secretNumber << ".\n";
        }

        cout << "\nDo you want to play again? (y/n): ";
        char ch;
        cin >> ch;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (ch != 'y' && ch != 'Y') {
            playAgain = false;
        }
    }

    cout << "\n=====================================\n";
    cout << "       Thanks for Playing! 🎮        \n";
    cout << "=====================================\n";
    return 0;
}
