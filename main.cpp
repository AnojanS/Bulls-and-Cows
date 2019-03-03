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
#include <map>
#define TMap std::map

using Ftext = std::string;
using int32 = int;

//Function Prototypes
void PrintIntro();
void PlayGame();
Ftext GetValidGuess();
bool AsktoPlayAgain();
void PrintGameSummary();

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
    std::cout << "\n\nWelcome to the Bulls and Cows word game!\n";
    std::cout << std::endl;
    std::cout << "          }   {         ___ " << std::endl;
    std::cout << "          (o o)        (o o) " << std::endl;
    std::cout << "   /-------\\ /          \\ /-------\\ " << std::endl;
    std::cout << "  / | BULL |O            O| COW  | \\ " << std::endl;
    std::cout << " *  |-,--- |              |------|  * " << std::endl;
    std::cout << "    ^      ^              ^      ^ " << std::endl;
    std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram?\n";
    std::cout << std::endl;
    return;
}


void PlayGame() {
    
    BCGame.Reset();
    int32 MaxTries = BCGame.GetMaxTries();
    
    //loop for the number of turns asking for guesses
    //game NOT won and attempts remaining
    while(!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries){
        Ftext Guess = GetValidGuess();
        
        //Submit valid guess to game and receive counts
        FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
        
        
        //std::cout << "Your guess was: " << Guess << std::endl;
        std::cout << "Bulls = " << BullCowCount.Bulls;
        std::cout << "    Cows = " << BullCowCount.Cows << "\n\n";
    }
    
    PrintGameSummary();
}

Ftext GetValidGuess(){
    EGuessStatus Status = EGuessStatus::Invalid_Status;
    Ftext Guess =  "";
    do {
        //get guess from player
        int32 CurrentTry = BCGame.GetCurrentTry();
        std::cout << std::endl << "Attempt " << CurrentTry << " of " << BCGame.GetMaxTries() << " | Enter your guess: ";
        getline(std::cin,Guess);
        
        Status = BCGame.CheckGuessValidity(Guess);
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
            break; //passed all input error checks
        }
    } while(Status != EGuessStatus::OK); //keep looping until user enters guess with no errors
    return Guess;
}

bool AsktoPlayAgain(){
    std::cout << "Would you like to play again with the same hidden word? (y/n)";
    Ftext Response = "";
    getline(std::cin,Response);
    std::cout << std::endl;
    
    return (Response[0]=='y') || (Response[0]=='Y');
}

void PrintGameSummary(){
    if (BCGame.IsGameWon()){
        std::cout << "Congratulations! You've figured out the isogram and won the game\n";
    }
    else{
        std::cout << "You've lost. Better luck mext time";
    }
};

