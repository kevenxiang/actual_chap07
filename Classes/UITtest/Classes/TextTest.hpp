//
//  TextTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef TextTest_hpp
#define TextTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"

class TextTest : public BaseTest {
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(TextTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;

};

#endif /* TextTest_hpp */
