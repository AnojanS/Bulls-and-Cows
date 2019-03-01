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
int32 FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry;};

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(FString) {
    return false;
}

void FBullCowGame::Reset(){
    
    constexpr int32 MAX_TRIES = 10;
    MyMaxTries = MAX_TRIES;
    
    MyCurrentTry = 1;
    return;
}









