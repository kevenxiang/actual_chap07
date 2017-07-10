//
//  LayoutTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/10.
//
//

#ifndef LayoutTest_hpp
#define LayoutTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"

class LayoutTest : public BaseTest {
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(LayoutTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* LayoutTest_hpp */
