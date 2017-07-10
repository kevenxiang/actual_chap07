//
//  BaseTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#include "BaseTest.hpp"
#include "ContentLayer.hpp"

USING_NS_CC;

bool BaseTest::init() {
    if (!Layer::init()) {
        return false;
    }
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
    
    // 返回菜单，触碰时调用backCallback函数
    auto backMenuItem = MenuItemImage::create("backNormal.png", "backNormal.png", CC_CALLBACK_1(BaseTest::backCallback, this));
//    backMenuItem->setPosition(Vec2(visibleSize.width - backMenuItem->getContentSize().width/2, backMenuItem->getContentSize().height/2));
    backMenuItem->setPosition(Vec2(visibleSize.width - 30, 50));
    auto menu = Menu::create(backMenuItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 300);
    
    // 显示Title的Label
    auto title_label = Label::createWithSystemFont(this->getTitle(), "", 30);
    title_label->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.9));
    this->addChild(title_label);
    
    return true;
}

// 获取测试标题函数，这里返回的只是一个简单的字符串，该函数应该由子类重写
std::string BaseTest::getTitle() const {
    return "base_title";
}

// 返回菜单选择场景
void BaseTest::backCallback(cocos2d::Ref *pSender) {
    Director::getInstance()->replaceScene(ContentLayer::createScene());
}































