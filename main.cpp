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
Ftext GetValidGuess();
bool AsktoPlayAgain();

FBullCowGame BCGame; // instantiate a new game

//MAIN------------------------------------------------------
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

//Function Implementations---------------------------------------------------------------------------
void PrintIntro (){
    
    //game intro
    std::cout << "Welcome to the Bulls and Cows word game!\n";
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram?\n";
    std::cout << std::endl;
    return;
}


void PlayGame() {
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    //loop for the number of turns asking for guesses
    for (int32 i=1; i <= MaxTries; i++){
        Ftext Guess = GetValidGuess();
        
        //Submit valid guess to game and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);
        
        //Print number of bulls and cows
        //std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << "    Cows = " << BullCowCount.Cows << std::endl << std::endl;
        std::cout << std::endl;
    }
    
    // TODO summarize game
}

Ftext GetValidGuess(){
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    Ftext Guess =  "";
    do {
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout <<  "Attempt #" << CurrentTry << " | Enter your guess: ";
        getline(std::cin,Guess);
        
        EGuessStatus Status = BCGame.CheckGuessValidity(Guess);
        switch (Status){
        case EGuessStatus::Wrong_Length:
            std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word";
            break;
        case EGuessStatus::Not_Isogram:
            std::cout << "Please enter a word without repeating letters";
            break;
        case EGuessStatus::Not_Lowercase:
            std::cout << "Please enter enter all lowercase letters";
            break;
        default:
            return Guess;
        }
        std::cout << std::endl;
    }while(Status != EGuessStatus::OK); //keep looping until user enters guess with no errors
    return Guess;
}

bool AsktoPlayAgain(){
    std::cout << "Would you like to play again?";
    Ftext Response = "";
    getline(std::cin,Response);
    std::cout << std::endl;
    
    return (Response[0]=='y') || (Response[0]=='Y');
    
    
}

