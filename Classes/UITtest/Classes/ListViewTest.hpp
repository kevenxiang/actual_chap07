//
//  ListViewTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/10.
//
//

#ifndef ListViewTest_hpp
#define ListViewTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"
#include "ui/CocosGUI.h"

class ListViewTest : public BaseTest {
protected:
    //文本
    cocos2d::ui::Text *_displayValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(ListViewTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* ListViewTest_hpp */
