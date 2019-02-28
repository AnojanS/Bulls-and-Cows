//
//  FBullCowGame.cpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

#include "FBullCowGame.hpp"

int FBullCowGame::GetMaxTries() { return MyMaxTries;};
int FBullCowGame::GetCurrentTry() { return MyCurrentTry;};

void FBullCowGame::Reset(){
    return;
}

bool FBullCowGame::IsGameWon() {
    return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) { 
    return false;
}









