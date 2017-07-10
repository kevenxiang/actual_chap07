//
//  CheckBoxTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef CheckBoxTest_hpp
#define CheckBoxTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"
#include "ui/CocosGUI.h"

using namespace ui;

class CheckBoxTest : public BaseTest {
protected:
    // 文本，用来显示CheckBox事件类型
    Text *_displayValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(CheckBoxTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* CheckBoxTest_hpp */
