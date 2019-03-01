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

using Ftext = std::string;
using int32 = int;

//Function Prototypes
void PrintIntro();
void PlayGame();
Ftext GetGuess();
bool AsktoPlayAgain();

//Main------------------------------------------------------
int main(int32 argc, const char * argv[]) {
    
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
//END OF MAIN-----------------------------------------------

//Function Implementations
void PrintIntro (){
    //game intro
    constexpr int32 WORD_LENGTH = 5;
    
    std::cout << "Welcome to the Bulls and Cows word game!\n";
    std::cout << "Can you guess the " << WORD_LENGTH << " letter isogram?\n";
    std::cout << std::endl;
    return;
}

FBullCowGame BCGame; // instantiate a new game

void PlayGame() {
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    //loop for the number of turns asking for guesses
    constexpr int32 NUMBER_OF_TURNS = 10;
    for (int32 i=1; i<=NUMBER_OF_TURNS; i++){
        Ftext Guess = GetGuess(); //TODO make guess checking validation
        
        //Submit valid guess to game
        //Print number of bulls and cows
        
        std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << std::endl;
    }
    
    // TODO summarize game
}

Ftext GetGuess(){
    int32 CurrentTry = BCGame.GetCurrentTry();
    //get a guess from player
    std::cout <<  "Attempt #" << CurrentTry << " | Enter your guess: ";
    Ftext Guess =  "";
    getline(std::cin,Guess);
    return Guess;
}

bool AsktoPlayAgain(){
    std::cout << "Would you like to play again?";
    Ftext Response = "";
    getline(std::cin,Response);
    std::cout << std::endl;
    
    return (Response[0]=='y') || (Response[0]=='Y');
    
    
}

