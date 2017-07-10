//
//  SliderTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/6.
//
//

#ifndef SliderTest_hpp
#define SliderTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"
#include "ui/CocosGUI.h"

class SliderTest : public BaseTest {
protected:
    // 文本，用来显示滑动条的进度值
    cocos2d::ui::Text *_displayValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(SliderTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
    
};

#endif /* SliderTest_hpp */
