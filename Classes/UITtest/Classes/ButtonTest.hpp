//
//  ButtonTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef ButtonTest_hpp
#define ButtonTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"

class ButtonTest : public BaseTest {
protected:
    cocos2d::Label *message;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(ButtonTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
    
};

#endif /* ButtonTest_hpp */
