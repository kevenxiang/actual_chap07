//
//  ControlSliderTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/3.
//
//

#ifndef ControlSliderTest_hpp
#define ControlSliderTest_hpp

#include <stdio.h>
#include "cocos2d.h"
// 包含所需文件
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"
// 使用命名空间cocos2d::extension
using namespace cocos2d::extension;

class ControlSliderTest : public cocos2d::Layer {
    
private:
    // 标签，用于显示滑块值
    cocos2d::Label *_displayValueLabel;
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    // 回调函数，当滑块被拖动时被调用
    void valueChanged(Ref *sender, Control::EventType controlEvent);
    
    // 选择器回调函数
    void menuCloseCallback(cocos2d::Ref *pSender);
    
    CREATE_FUNC(ControlSliderTest);
};

#endif /* ControlSliderTest_hpp */






































