//*******************************************************************************
//类名称   : ColorBombBubble
//功能     : <用作发射出去使用了道具的彩球炸弹>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _COLOR_BOMB_BUBBLE_H_
#define _COLOR_BOMB_BUBBLE_H_
#include "cocos2d.h"
#include "ColorBubble.h"
namespace bubble_second {
    class ColorBombBubble : public ColorBubble
    {
    public:
        CREATE_FUNC(ColorBombBubble);
        virtual ~ColorBombBubble();
    public:
        void dispatchEventAfterShooted() override;
        void bubbleEliminate(int = 0) override;
        float playTheSpecialEffects() override;
        void downFromAir() override;
    private:
        ColorBombBubble();
        bool init();
    };
}
#endif //_COLOR_BOMB_BUBBLE_H_