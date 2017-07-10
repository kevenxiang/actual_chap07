//
//  LoadingBarTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/5.
//
//

#include "LoadingBarTest.hpp"
#include "ContentLayer.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene *LoadingBarTest::createScene() {
    auto scene = Scene::create();
    auto layer = LoadingBarTest::create();
    scene->addChild(layer);
    return scene;
}

void LoadingBarTest::onEnter() {
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 为了看的更清楚，添加一个背景
    auto background = Sprite::create("background.png");
    background->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    this->addChild(background);
    
    // 文本，用来显示进度条的值
    _displayValueLabel = Text::create("Percent = 0", "", 20);
    _displayValueLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height*0.8));
    this->addChild(_displayValueLabel);
    
    // 创建一个LoadingBar
    auto loadingBar = LoadingBar::create("loadingbar.png");
    // 设置进度条从左向右递增
    loadingBar->setDirection(LoadingBar::Direction::LEFT);
    // 设置tag值，之后在update函数中可以通过getChildByTag函数获取这个LoadingBar对象
    loadingBar->setTag(100);
    // 设置坐标位置
    loadingBar->setPosition(Vec2(visibleSize.width/2, visibleSize.height/2));
    // 将LoadingBar添加为当前层的子节点
    this->addChild(loadingBar);
    // 启用定时器回调更新函数
    this->scheduleUpdate();
    
}

// update函数
void LoadingBarTest::update(float delta) {
    //自增
    _count++;
    // 当_count变量的值大于100，归零
    if (_count > 100) {
        _count = 0;
    }
    // 通过tag值获得LoadingBar对象
    auto loadingBar = static_cast<LoadingBar *>(this->getChildByTag(100));
    // 修改LoadingBar对象的进度
    loadingBar->setPercent(_count);
    // 在文本中显示LoadingBar对象当前的进度
    _displayValueLabel->setString(StringUtils::format("Percent = %0.0f", loadingBar->getPercent()));
    
}

std::string LoadingBarTest::getTitle() const {
    return "LoadingBar（进度条） Test ";
}



































