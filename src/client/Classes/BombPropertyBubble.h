//*******************************************************************************
//类名称   : BombPropertyBubble
//功能     : <一炸炸两圈的炸弹道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BOMB_PROPERTY_BUBBLE_H_
#define _BOMB_PROPERTY_BUBBLE_H_
#include "cocos2d.h"
#include "ColorBubble.h"
namespace bubble_second {
    class BombPropertyBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(BombPropertyBubble);
        virtual ~BombPropertyBubble();
    public:
        void dispatchEventAfterShooted() override;
        void bubbleEliminate(int = 0) override;
        float playTheSpecialEffects() override;
        void downFromAir() override;
    private:
        BombPropertyBubble();
        bool init();
    };
}
#endif //_BOMB_PROPERTY_BUBBLE_H_