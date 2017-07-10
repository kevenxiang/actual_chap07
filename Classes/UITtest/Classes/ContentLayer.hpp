//
//  ContentLayer.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef ContentLayer_hpp
#define ContentLayer_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class ContentLayer : public cocos2d::Layer {
protected:
    //记录滑动的开始坐标
    Vec2 _beginPos;
    //菜单
    Menu *_itemMenu;
    
public:
    static Scene *createScene();
    
    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
    
    CREATE_FUNC(ContentLayer);
    
    // 点击每一个菜单项时的回调函数
    void menuCallback(Ref *sender);
    
    // 触碰事件回调函数
    bool onTouchBegan(Touch *touch, Event *event);
    void onTouchMoved(Touch *touch, Event *event);
};

#endif /* ContentLayer_hpp */


























