//
//  LoadingBarTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/5.
//
//

#ifndef LoadingBarTest_hpp
#define LoadingBarTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"
#include "ui/CocosGUI.h"

class LoadingBarTest : public BaseTest {
protected:
    // 整型变量，用来表示进度条的进度
    int _count;
    // 文本，用来显示进度条的值
    cocos2d::ui::Text *_displayValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(LoadingBarTest);
    
    virtual void onEnter() override;
    
    // 在定时器方法中更新进度条
    virtual void update(float delta);
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* LoadingBarTest_hpp */
