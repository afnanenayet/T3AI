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
    struct node
    {
        node * root = nullptr,
        * left = nullptr,
        * right = nullptr;
    };
    
public:
    AI();
};

#endif /* AI_hpp */
