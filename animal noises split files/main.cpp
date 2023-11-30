#include "sheep.h"
#include "cow.h"
#include "frisian.h"
#include <iostream>
#include <vector>
#include <memory>
#include <limits>

int getUserInput(const std::string& prompt) {
    int userInput;
    while (true) {
        std::cout << prompt;
        if (std::cin >> userInput && userInput >= 0) {
            break;
        }
        else {
            std::cin.clear(); // Clear input buffer to restore cin to a usable state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
            std::cout << "Invalid input. Please enter a non-negative integer.\n";
        }
    }
    return userInput;
}

int main() {
    // Create a vector of unique pointers to Animal
    std::vector<std::unique_ptr<Animal>> animalContainer;

    // Get user input for the number of Sheep
    int numSheep = getUserInput("Enter the number of Sheep: ");

    // Get user input for the number of Cows
    int numCows = getUserInput("Enter the number of Cows: ");

    // Get user input for the number of Frisian Cows
    int numFrisians = getUserInput("Enter the number of Frisian Cows: ");

    // Add instances of different classes to the container based on user input
    for (int i = 0; i < numSheep; ++i) {
        animalContainer.push_back(std::make_unique<Sheep>());
    }

    for (int i = 0; i < numCows; ++i) {
        animalContainer.push_back(std::make_unique<Cow>());
    }

    for (int i = 0; i < numFrisians; ++i) {
        animalContainer.push_back(std::make_unique<Frisian>());
    }

    // Access and call speak() for each object in the container
    for (const auto& animal : animalContainer) {
        animal->speak();
    }

    return 0;
}
