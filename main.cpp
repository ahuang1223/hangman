#include <iostream>
#include <vector>
#include <string>
#include <random>

std::string getRandomWord(char type){
    std::vector<std::string> fruits;
    std::string newFruits[] = {"apple", "banana", "cherry", "duran", "grapes", "strawberry"};
    std::vector<std::string> subjects; 
    std::string newSubjects[] = {"math", "art", "english", "science", "history", "sex ed"};
    fruits.insert(fruits.end(), std::begin(newFruits), std::end(newFruits));
    subjects.insert(subjects.end(), std::begin(newSubjects), std::end(newSubjects));
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(0,5);
    int randomIndex = dist(gen);
    if (type == 'f'){
        return fruits[randomIndex];
    } else {
        return subjects[randomIndex];
    };
}

void displayWord(std::string actualWord, std::vector<char> guessedLetters){
    for(char letter : actualWord){
        if(std::find(guessedLetters.begin(), guessedLetters.end(), letter) != guessedLetters.end()){
            std::cout << letter << " ";
        } else {
            std::cout << "_ ";
        }
    }
    std::cout << std::endl;
}

int main(){
    char type;
    std::cout << "Let's play hangman!" << std::endl << "Choose between fruits and school subjects('f' for fruits and 's' for school subjects)" << std::endl;
    std::cin >> type;
    std::string actualWord = getRandomWord(type);
    std::vector<char> wordLetters(actualWord.begin(), actualWord.end());
    int tries = 3;
    std::vector<char> letters;
    char guessedLetter;
    std::string guessedWord;
    std::vector<char> guessedLetters;
    do {
        std::cout << "Guess a letter. You have " << tries << " tries left." << std::endl;
        tries--;
        std::cin >> guessedLetter;
        guessedLetters.push_back(guessedLetter);
        bool there = false;
        for(char letter : wordLetters) {
            if (guessedLetter == letter){
                there = true;
                break;
            }
        }
        if (there == true){
            std::cout << "Letter is there" << std::endl;
        } else {
            std::cout << "Letter is not there" << std::endl;
        }
        displayWord(actualWord, guessedLetters);
    }while (tries != 0);
    std::cout << "guess the word now" << std::endl;
    std::cin >> guessedWord;
    if(guessedWord == actualWord){
        std::cout << "Congratulations!";
    } else{
        std::cout << "Incorrect, the actual word is " << actualWord;
    }
    return 0;
}
