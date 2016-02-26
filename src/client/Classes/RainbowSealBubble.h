//*******************************************************************************
//文件名       : <RainbowSealBubble.h>
//文件实现功能  : <此泡泡自带彩虹封印, 轮回不休>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _RAINBOW_SEAL_BUBBLE_H_
#define _RAINBOW_SEAL_BUBBLE_H_
#include "BaseComponentBubble.h"
namespace bubble_second {
    class RainbowCharactor;
    class BaseBubble;
    class RainbowSealBubble : public BaseComponentBubble
    {
    public:
        CREATE_FUNC(RainbowSealBubble);
        ~RainbowSealBubble();
        //int getBubbleComponentNumble() override;
        BubbleVector disposeRainbowSeal(BubbleType color);
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
        //改变颜色
        void changeRainbowColor();
        void setSealedCharactor(RainbowCharactor* charactor);
        RainbowCharactor* getSealedCharactor();
        //float playTheSpecialEffects();
    private:
        RainbowSealBubble();
        bool init();
        //设置颜色
        void setRainbowColor(BubbleType color);
        BubbleType getRainbowColor();
        //是否跟封印颜色相等
        bool isEqualRainbowColor(BubbleType color);
        //是否已经封印了人物
        bool isSealing();
        //增加待机动画
        void addStandbyAnimation();
    private:
        //封印颜色
        BubbleType rainbow_color_;
        bool first_flag_;
        //里面封印的人物
        RainbowCharactor* sealed_charactor_;

    };
}
#endif //_RAINBOW_SEAL_BUBBLE_H_