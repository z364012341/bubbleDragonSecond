//*******************************************************************************
//类名称   : WindmillBubble
//功能     : <风车泡泡类>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _WINDMILL_BUBBLE_H_
#define _WINDMILL_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class WindmillBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(WindmillBubble);
        ~WindmillBubble();
        void setParent(cocos2d::Node* parent) override;
        void bubbleEliminate(int combo = 0) override;
    private:
        WindmillBubble();
        bool init();
        void setBubbleTexture(BubbleType type) override;
        cocos2d::Node* getFlyingTexture();
        cocos2d::Action* getFlyingAction();
        cocos2d::CardinalSplineBy* getArchimedeanSpiralAction();
    private:
        cocos2d::Sprite* sp_ = nullptr;
    };
}
#endif //_WINDMILL_BUBBLE_H_