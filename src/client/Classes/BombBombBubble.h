//*******************************************************************************
//类名称   : BombBombBubble
//功能     : <炸弹泡泡类>
//-------------------------------------------------------------------------------
//备注     : <./.玩过无主咩  玩过就知道为什么要叫bombbomb>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BOMB_BOMB_BUBBLE_H_
#define _BOMB_BOMB_BUBBLE_H_
//#include "cocos2d.h"
#include "BaseBubble.h"
namespace bubble_second {
    class BombBombBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BombBombBubble);
        ~BombBombBubble();
    public:
        void downFromAir() override;
        //小球正常消除
        void bubbleEliminate(int combo = 0) override;
        float playTheSpecialEffects() override;
    private:
        BombBombBubble();
        bool init();
    };
}
#endif //_BOMB_BOMB_BUBBLE_H_