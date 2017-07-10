//
//  TextFieldTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef TextFieldTest_hpp
#define TextFieldTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"
#include "ui/CocosGUI.h"

using namespace ui;

class TextFieldTest : public BaseTest {
protected:
    // 定义Text，用于显示文本框事件类型
    Text *_displayValueLabel;
    Text *_messageValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(TextFieldTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* TextFieldTest_hpp */
