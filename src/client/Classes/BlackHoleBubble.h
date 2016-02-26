//*******************************************************************************
//文件名         : <DarkCloudBubble.h>
//文件实现功能  : <阴云泡泡, 遮盖>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BLACK_HOLE_BUBBLE_H_
#define _BLACK_HOLE_BUBBLE_H_
#include "cocos2d.h"
#include "BaseBubble.h"
#include "cocostudio\CocoStudio.h"
namespace bubble_second {
    class BlackHoleBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(BlackHoleBubble);
        ~BlackHoleBubble();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        //吞噬小球
        void swallowBubble(BaseBubble* bubble);
        cocos2d::Vec2 getControlPointWithVectors(const cocos2d::Vec2& point_1, const cocos2d::Vec2& point_2);
        //是否需要消除
        bool isNeedEliminate();
        //因为黑洞小球有三条命
        bool needRemoveFromBubbleMap() override;
        void forceEliminate();
    private:
        BlackHoleBubble();
        bool init();
        void swallowBubbleOnce();
        void addSwallowTimes();
        //void initAnimation();
        void setBubbleTexture(BubbleType) override;
        void addTouchEventListener() override;
        void removeTouchEventListener() override;
        //播放一级动画
        void playFirstAction();
        //阿基米德螺线动作
        void playAchimedeanSpiralAction(BaseBubble* bubble);
    private:
        int swallow_times_;
        BubbleVector swallow_vector_;
        cocostudio::Armature* armature_;
    };
}
#endif //_BLACK_HOLE_BUBBLE_H_