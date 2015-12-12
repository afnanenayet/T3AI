//
//  AI.hpp
//  T3AI
//
//  Created by Afnan Enayet on 12/10/15.
//  Copyright © 2015 Afnan Enayet. All rights reserved.
//

#ifndef AI_hpp
#define AI_hpp

class AI
{
private:
    float timeLimit;
    // Node for a the AI tree
    struct node
    {
        node * root = nullptr,
        * left = nullptr,
        * right = nullptr;
    };
    
public:
    // Pass time limit for computation in SECONDS
    AI(float timeAlloc);
    int * nextMove ();
};

#endif /* AI_hpp */
