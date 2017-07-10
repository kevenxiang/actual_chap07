//
//  PageViewTest.cpp
//  actual_chap07
//
//  Created by xiang on 2017/7/10.
//
//

#include "PageViewTest.hpp"
#include "ContentLayer.hpp"
#include "ui/CocosGUI.h"

USING_NS_CC;
using namespace ui;

Scene *PageViewTest::createScene() {
    auto scene = Scene::create();
    auto layer = PageViewTest::create();
    scene->addChild(layer);
    return scene;
}

void PageViewTest::onEnter() {
    
    Layer::onEnter();
    
    Size visibleSize = Director::getInstance()->getVisibleSize();
    // 提示信息
    _displayValueLabel = Text::create("请水平方向移动page", "", 17);
    _displayValueLabel->setPosition(Vec2(visibleSize.width/2, visibleSize.height * 0.8));
    this->addChild(_displayValueLabel);
    
    // 创建一个PageView
    auto pageView = PageView::create();
    pageView->setContentSize(Size(480.0f, 320.0f));
    // 设置PageView在屏幕居中位置
    pageView->setPosition(Vec2((visibleSize.width - pageView->getContentSize().width) / 2.0f, (visibleSize.height - pageView->getContentSize().height) / 2.0f));
    // 设置PageView的数量，本例只有3个page
    int pageCount = 3;
    // 循环添加3个Layout（关卡图片）
    for (int i = 0; i < pageCount; ++i) {
        // 创建一个Layout
        Layout *layout = Layout::create();
        layout->setContentSize(Size(480.0f, 320.0f));
        
        ImageView *imageView = ImageView::create(StringUtils::format("level%d.png", i+1));
        imageView->setContentSize(Size(480.0f, 320.0f));
        imageView->setPosition(Vec2(layout->getContentSize().width/2.0f, layout->getContentSize().height/2.0f));
        // 将ImageView添加为Layout的子节点
        layout->addChild(imageView);
        // 在i表示的位置上插入Layout
        pageView->insertPage(layout, i);
    }
    
    // 添加事件监听器
    pageView->addEventListener([=](Ref *pSender, PageView::EventType type){
        switch (type) {
            case PageView::EventType::TURNING:
            {
                PageView *pageView = dynamic_cast<PageView *>(pSender);
                // 在_displayValueLabel文本中显示PageIndex
                _displayValueLabel->setString(StringUtils::format("page = %ld",pageView->getCurPageIndex() + 1));
            }
                break;
                
            default:
                break;
        }
    });
    
    // 将PageView添加未当层的子节点
    this->addChild(pageView);
                          
}

std::string PageViewTest::getTitle() const
{
    return "PageView（分页层容器） Test ";
}
































