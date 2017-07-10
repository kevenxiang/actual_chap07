//
//  ImageViewTest.hpp
//  actual_chap07
//
//  Created by xiang on 2017/7/5.
//
//

#ifndef ImageViewTest_hpp
#define ImageViewTest_hpp

#include <stdio.h>
#include "cocos2d.h"
#include "BaseTest.hpp"

class ImageViewTest : public BaseTest {
public:
    static cocos2d::Scene *createScene();
    
    CREATE_FUNC(ImageViewTest);
    
    virtual void onEnter() override;
    
    // 标题，重写父类BaseTest的函数
    virtual std::string getTitle() const override;
};

#endif /* ImageViewTest_hpp */
