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

class FBullCowGame{ //other files start with F by Unreal standards
public:
    FBullCowGame(); //constructor
    
    int GetMaxTries() const; 
    int GetCurrentTry() const;
    bool IsGameWon() const;
    
    void Reset();
    bool CheckGuessValidity(std::string);



private: //instance variables
    int MyCurrentTry ; //see constructor for initilization
    int MyMaxTries ;
};
