#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

int main() {
    // Seed the random number generator with the current time
    std::srand(std::time(0));
    
    // Generate a random number between 1 and 100
    int randomNumber = std::rand() % 100 + 1;
    int userGuess = 0;

    std::cout << "Guess the number (between 1 and 100): ";

    // Loop until the user guesses the correct number
    while (true) {
        std::cin >> userGuess;

        if (userGuess < randomNumber) {
            std::cout << "Too low. Try again: ";
        } else if (userGuess > randomNumber) {
            std::cout << "Too high. Try again: ";
        } else {
            std::cout << "Congratulations! You guessed the correct number: " << randomNumber << std::endl;
            break;
        }
    }

    return 0;
}

