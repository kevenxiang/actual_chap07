//
//  ControlSwitchTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/3.
//
//

#ifndef ControlSwitchTest_hpp
#define ControlSwitchTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "extensions/GUI/CCControlExtension/CCControlSwitch.h"
#include "extensions/GUI/CCControlExtension/CCControlSlider.h"
// 使用命名空间cocos2d::extension
using namespace cocos2d::extension;

class ControlSwitchTest : public cocos2d::Layer {
private:
    // 标签，用于开关值
    cocos2d::Label *_displayValueLabel;
    
public:
    static cocos2d::Scene *createScene();
    
    virtual bool init();
    
    //回调函数，当滑块被拖动时被调用
    void valueChanged(Ref *sender, Control::EventType controlEvent);
    
    CREATE_FUNC(ControlSwitchTest);
};

#endif /* ControlSwitchTest_hpp */
