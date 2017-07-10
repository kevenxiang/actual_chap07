//
//  ScrollViewTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/10.
//
//

#ifndef ScrollViewTest_hpp
#define ScrollViewTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"

class ScrollViewTest : public BaseTest {
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(ScrollViewTest);
    
    virtual void onEnter() override;
    
    virtual std::string getTitle() const override;
};

#endif /* ScrollViewTest_hpp */
