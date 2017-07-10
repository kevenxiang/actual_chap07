//
//  ControlSliderTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/3.
//
//

#include "ControlSliderTest.hpp"
USING_NS_CC;

Scene *ControlSliderTest::createScene() {
    auto scene = Scene::create();
    auto layer = ControlSliderTest::create();
    scene->addChild(layer);
    return scene;
}

bool ControlSliderTest::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    //关闭菜单
    auto closeItem = MenuItemImage::create("CloseNormal.png", "CloseSelected.png", CC_CALLBACK_1(ControlSliderTest::menuCloseCallback, this));
    closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width/2, origin.y + closeItem->getContentSize().height/2));
    
    //创建菜单
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);
    
    // 设置标签初始文字、位置，并添加为当前层的子节点
    _displayValueLabel = Label::createWithSystemFont("请使用拇指移动滑块.", "", 20);
    _displayValueLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2+100));
    addChild(_displayValueLabel);
    
    // 创建一个拖动滑块
    auto slider = ControlSlider::create("sliderTrack.png", "sliderProgress.png", "sliderThumb.png");
    // 设置拖动滑块的范围最小值
    slider->setMinimumValue(0.0f);
    // 设置拖动滑块的范围最大值
    slider->setMaximumValue(10.0f);
    // 绑定事件处理函数，当滑块被拖动时被调用
    slider->addTargetWithActionForControlEvents(this, cccontrol_selector(ControlSliderTest::valueChanged), Control::EventType::VALUE_CHANGED);
    slider->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(slider);
    
    return true;
}

// 事件处理函数，当滑块被拖动时被调用
void ControlSliderTest::valueChanged(cocos2d::Ref *sender, Control::EventType controlEvent) {
    // 将pSender类型转成拖动滑块ControlSlider
    ControlSlider *pSlider = (ControlSlider *)sender;
    // 获取滑块的当前值，并更新标签内容
    _displayValueLabel->setString(StringUtils::format("滑块值 = %.02f", pSlider->getValue()));
}

void ControlSliderTest::menuCloseCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
    MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.","Alert");
    return;
#endif
    
    Director::getInstance()->end();
    
#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif
}



























