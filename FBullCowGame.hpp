//
//  FBullCowGame.hpp
//  BullCowGame
//
//  Created by Anojan Sabaratnam on 2019-02-17.
//  Copyright © 2019 Anojan Sabaratnam. All rights reserved.
//

#ifndef FBullCowGame_hpp
#define FBullCowGame_hpp

#include <stdio.h>
#include<string>

#endif /* FBullCowGame_hpp */

using FString = std::string;
using int32 = int;

struct FBullCowCount{
    int32 Bulls = 0;
    int32 Cows = 0;
};

enum class EGuessStatus{
    Invalid_Status,
    OK,
    Not_Isogram,
    Wrong_Length,
    Not_Lowercase
};

class FBullCowGame{ //other files start with F by Unreal standards
public:
    FBullCowGame(); //constructor
    
    int32 GetMaxTries() const;
    int32 GetCurrentTry() const;
    int32 GetHiddenWordLength() const;
    bool IsGameWon() const;
    EGuessStatus CheckGuessValidity(FString) const;
    
    void Reset();
    FBullCowCount SubmitGuess(FString);


private: //instance variables
    int32 MyCurrentTry ; //see constructor for initilization
    int32 MyMaxTries ;
    FString MyHiddenWord;
};
