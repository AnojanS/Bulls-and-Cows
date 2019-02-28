//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

#include "FBullCowGame.hpp"

int FBullCowGame::GetMaxTries() const {return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry;};

bool FBullCowGame::IsGameWon() const {
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) { 
    return false;
}

void FBullCowGame::Reset(){
    return;
}








