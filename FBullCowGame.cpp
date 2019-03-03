//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

#include "FBullCowGame.hpp"

using FString = std::string;
using int32 = int;

//Constructor
FBullCowGame::FBullCowGame() {
    Reset();
}

//Getters
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries;}
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}

bool FBullCowGame::IsGameWon() const {
    return false;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    
    //if user attempt isn't an isogram return error
    if (false){
        return EGuessStatus::Not_Isogram;
    }
    //if user attempt isn't all lowercase letters return error
    else if (false){
        return EGuessStatus::Not_Lowercase;
    }
    //if user attempt isn't correct length return error
    else if (Guess.length() != GetHiddenWordLength()){
        return EGuessStatus::Wrong_Length;
    }
    else{
        return EGuessStatus::OK;
    }
}

void FBullCowGame::Reset(){
    
    constexpr int32 MAX_TRIES = 10;
    MyMaxTries = MAX_TRIES;
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    
    MyCurrentTry = 1;
    return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) { //receives a valid guess, increments attempt
    
    //increment attempt
    MyCurrentTry++;
    
    //setup return variable
    FBullCowCount BullCowCount;
    
    //loop through all letters from the user's guess
    int32 HiddenWordLength = MyHiddenWord.length();
    for (int32 i = 0 ; i < HiddenWordLength ; i++){
        //compare letters against the hidden word
        for (int32 j = 0 ; j < HiddenWordLength ; j++){
            // if they match
            if(Guess[j] == MyHiddenWord[i]){
                //if they are in teh same place
                if (i==j){
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    
    return BullCowCount;
}












