//
//  ImageViewTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/5.
//
//

#include "ImageViewTest.hpp"
#include "ContentLayer.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene *ImageViewTest::createScene() {
    auto scene = Scene::create();
    auto layer = ImageViewTest::create();
    scene->addChild(layer);
    return scene;
}

void ImageViewTest::onEnter() {
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // 添加背景
    auto background = Sprite::create("background.png");
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(background);
    
    // 创建一个ImageView
    auto imageView = ImageView::create("ccicon.png");
    imageView->setScale(2);
    imageView->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(imageView);
    
}

std::string ImageViewTest::getTitle() const {
    return "ImageView（图片） Test ";
}

























