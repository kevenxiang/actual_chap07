//
//  ListViewTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/10.
//
//

#include "ListViewTest.hpp"
#include "ContentLayer.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene *ListViewTest::createScene() {
    auto scene = Scene::create();
    auto layer = ListViewTest::create();
    scene->addChild(layer);
    return scene;
}

void ListViewTest::onEnter() {
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    
    // 提示信息
    _displayValueLabel = Text::create("请垂直方向滚动ListView", "", 20);
    _displayValueLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.8));
    this->addChild(_displayValueLabel);
    
    // 创建一个ListView
    auto listView = ListView::create();
    // 设置ListView的方向，本例为VERTICAL（垂直）
    listView->setDirection(ScrollView::Direction::VERTICAL);
    // 设置ListView的背景图片
    listView->setBackGroundImage("green_edit.png");
    // 设置背景图片作为九宫格填充
    listView->setBackGroundImageScale9Enabled(true);
    // 设置ListView的ContentSize
    listView->setContentSize(Size(480, 260));
    // 设置ListView的位置
    listView->setPosition(Vec2((visibleSize.width - listView->getContentSize().width) / 2.0f, (visibleSize.height - listView->getContentSize().height) / 2.0f));
    // 添加事件监听器
    listView->addEventListener([=](Ref *pSender, ListView::EventType type){
        switch (type) {
            case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_START: {
                ListView *listView = static_cast<ListView *>(pSender);
                log("select child start index = %ld", listView->getCurSelectedIndex());
            }
                break;
            
            case cocos2d::ui::ListView::EventType::ON_SELECTED_ITEM_END: {
                ListView *listView = static_cast<ListView *>(pSender);
                log("select child end index = %ld", listView->getCurSelectedIndex());
            }
                break;
                
            default:
                break;
        }
    });
    
    // 添加事件监听器
    listView->addEventListener([=](Ref *pSender, ScrollView::EventType type){
        switch (type) {
            case cocos2d::ui::ScrollView::EventType::SCROLL_TO_BOTTOM:
                log("SCROLL_TO_BOTTOM");
                break;
            case cocos2d::ui::ScrollView::EventType::SCROLL_TO_TOP:
                log("SCROLL_TO_TOP");
                break;
            default:
                break;
        }
    });
    // 将ListView添加为当前层的子节点
    this->addChild(listView);
    
    // 添加自定义item（10个Button）
    for (int i = 0; i < 10; ++i) {
        // 创建一个Button
        Button *custom_button = Button::create("button.png", "buttonHighlighted.png");
        // 设置Button的Name
        custom_button->setName("Title Button");
        // 设置Button是否九宫格填充
        custom_button->setScale9Enabled(true);
        custom_button->setContentSize(Size(200, 60));
        custom_button->setTitleText(StringUtils::format("listview_item_%d", i));
        custom_button->setTitleFontSize(16);
        
        // 创建一个Layout，用来添加Button
        Layout *custom_item = Layout::create();
        custom_item->setContentSize(custom_button->getContentSize());
        // 设置Layout的坐标位置
        custom_button->setPosition(Vec2(custom_item->getContentSize().width/2.0f, custom_item->getContentSize().height / 2.0f));
        // 将Button添加为Layout的字节
        custom_item->addChild(custom_button);
        // 将Layout添加为ListView的子节点
        listView->addChild(custom_item);
    }
}

std::string ListViewTest::getTitle() const {
    return "ListView(列表层容器) Test ";
}






































