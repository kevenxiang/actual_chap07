//
//  TextTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#include "TextTest.hpp"
#include "ContentLayer.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene *TextTest::createScene() {
    auto scene = Scene::create();
    auto layer = TextTest::create();
    scene->addChild(layer);
    return scene;
}

void TextTest::onEnter() {
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 使用系统字体创建一个Text
    auto text1 = Text::create("HelloWorld", "Arial", 20);
    text1->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2+50));
    this->addChild(text1);
    
    auto text2 = Text::create("HelloWorld", "fonts/Marker Felt.ttf", 20);
    text2->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2 - 50));
    this->addChild(text2);
    
}

std::string TextTest::getTitle() const {
    return "Text（文本） Test";
}















































