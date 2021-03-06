//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

#include "FBullCowGame.hpp"
#include <string>
#include <iostream>
#include <map>
#define TMap std::map

using FString = std::string;
using int32 = int;

//Constructor
FBullCowGame::FBullCowGame() {Reset();}

//Getters
int32 FBullCowGame::GetCurrentTry() const {return MyCurrentTry;}
int32 FBullCowGame::GetHiddenWordLength() const {return MyHiddenWord.length();}
bool FBullCowGame::IsGameWon() const {return bGameIsWon;}


void FBullCowGame::Reset(){
    
    const FString HIDDEN_WORD = "planet";
    MyHiddenWord = HIDDEN_WORD;
    MyCurrentTry = 1;
    bGameIsWon = false;
    return;
}

int32 FBullCowGame::GetMaxTries() const {
    TMap <int32,int32> WordLengthtoMaxTries {{3,4},{4,7},{5,10},{6,15},{7,20}};
    return WordLengthtoMaxTries[MyHiddenWord.length()];
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const {
    
    //if user attempt isn't an isogram return error
    if (!IsIsogram(Guess)){
        return EGuessStatus::Not_Isogram;
    }
    //if user attempt isn't all lowercase letters return error
    else if (!IsLowerCase(Guess)){
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

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess) { //receives a valid guess, increments attempt
    
    MyCurrentTry++;
    FBullCowCount BullCowCount;
    int32 WordLength = MyHiddenWord.length(); //assume same length as guess
    
    //loop through all letters from hidden word
    for (int32 i = 0 ; i < WordLength ; i++){
        //compare letters against the user's guess
        for (int32 j = 0 ; j < WordLength ; j++){
            // if they match
            if(Guess[j] == MyHiddenWord[i]){
                //if they are in teh same place
                if (i==j){ //in same place
                    BullCowCount.Bulls++;
                }
                else {
                    BullCowCount.Cows++;
                }
            }
        }
    }
    if (BullCowCount.Bulls == WordLength){
        bGameIsWon = true;
    }
    else{
        bGameIsWon = false;
    }
    return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const{
    //treat 0 and 1 letter words as isograms
    if (Word.length() <=1){return true;}
    TMap<char,bool> LetterSeen; //setup map
    
    for(auto Letter:Word){
        Letter = tolower(Letter); //handle lowercase letters only
        if (LetterSeen[Letter]){
            return false; //not an isogram
        }
        else{
            LetterSeen[Letter] = true;
        }
    }
    
    return true;
}

bool FBullCowGame::IsLowerCase(FString Word) const {
    for (auto Letter : Word){
        if (!islower(Letter)){
            return false;
        }
    }
    return true;
}










