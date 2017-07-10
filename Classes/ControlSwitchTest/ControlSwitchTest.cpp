//
//  ControlSwitchTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/3.
//
//

#include "ControlSwitchTest.hpp"

USING_NS_CC;

Scene *ControlSwitchTest::createScene() {
    auto scene = Scene::create();
    auto layer = ControlSwitchTest::create();
    scene->addChild(layer);
    return scene;
}

bool ControlSwitchTest::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // 设置标签初始文字、位置，并添加为当前层的子节点
    _displayValueLabel = Label::createWithSystemFont("on", "", 20);
    _displayValueLabel->setPosition(Vec2(visibleSize.width/2-50, visibleSize.height/2));
    this->addChild(_displayValueLabel);
    
    //创建一个开关按钮
    auto switchControl = ControlSwitch::create(Sprite::create("switch-mask.png"), Sprite::create("switch-on.png"), Sprite::create("switch-off.png"), Sprite::create("switch-thumb.png"), Label::createWithSystemFont("On", "", 16), Label::createWithSystemFont("Off", "", 16));
    // 绑定事件处理函数，当开关按钮切换时被调用
    switchControl->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlSwitchTest::valueChanged), Control::EventType::VALUE_CHANGED);
    switchControl->setPosition(Vec2(visibleSize.width/2+100, visibleSize.height/2));
    this->addChild(switchControl);
    
    return true;
}

// 事件处理函数，当开关按钮切换时被调用
void ControlSwitchTest::valueChanged(cocos2d::Ref *sender, Control::EventType controlEvent) {
    ControlSwitch *pSwitch = (ControlSwitch *)sender;
    //更新标签内容
    if (pSwitch->isOn()) {
        _displayValueLabel->setString("On");
    } else {
        _displayValueLabel->setString("Off");
    }
}



























