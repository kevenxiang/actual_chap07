//
//  BaseTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/4.
//
//

#ifndef BaseTest_hpp
#define BaseTest_hpp

#include <stdio.h>
#include "cocos2d.h"

USING_NS_CC;

class BaseTest : public cocos2d::Layer {
public:
    virtual bool init();
    
    // 显示标题，该函数应该由子类重写
    virtual std::string getTitle() const;
    
    //返回菜单
    virtual void backCallback(Ref *pSender);
};

#endif /* BaseTest_hpp */
