//
//  main.cpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

//Preprocessor Directives
#include <iostream>
#include <string>
#include "FBullCowGame.hpp"

//Function Prototypes
void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AsktoPlayAgain();

//Main
int main(int argc, const char * argv[]) {
    
    bool bPlayAgain = false;
    do{
        PrintIntro();
        PlayGame();
        bPlayAgain = AsktoPlayAgain();
    }
    while(bPlayAgain);
    //exit the program
    std::cout << std::endl;
    return 0;
}

//Function Implementations
void PrintIntro (){
    //game intro
    constexpr int WORLD_LENGTH = 5;
    
    std::cout << "Welcome to the Bulls and Cows word game!\n";
    std::cout << "Can you guess the " << WORLD_LENGTH << " letter isogram?\n";
    std::cout << std::endl;
    return;
}

FBullCowGame BCGame; // instantiate a new game

void PlayGame() {
    
    BCGame.Reset();
    int MaxTries = BCGame.GetMaxTries();
    
    //loop for the number of turns asking for guesses
    constexpr int NUMBER_OF_TURNS = 10;
    for (int i=1; i<=NUMBER_OF_TURNS; i++){
        std::string Guess = GetGuess();
        //repeat the guess back to player
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
}

std::string GetGuess(){
    int CurrentTry = BCGame.GetCurrentTry();
    //get a guess from player
    std::cout <<  "Attempt #" << CurrentTry << " | Enter your guess: ";
    std::string Guess =  "";
    getline(std::cin,Guess);
    return Guess;
}

bool AsktoPlayAgain(){
    std::cout << "Would you like to play again?";
    std::string Response = "";
    getline(std::cin,Response);
    std::cout << std::endl;
    
    return (Response[0]=='y') || (Response[0]=='Y');
    
    
}

