//*******************************************************************************
//文件名       : <RainbowSealManager.h>
//文件实现功能  : <彩虹封印的管理类>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _RAINBOW_SEAL_MANAGER_H_
#define _RAINBOW_SEAL_MANAGER_H_
#include "cocos2d.h"
#include "BubbleSecondConstant.h"
namespace bubble_second {
    class RainbowSealBubble;
    class RainbowCharactor;
    class RainbowSealManager
    {
    public:
        GETINSTANCE_FUNC(RainbowSealManager);
        ~RainbowSealManager();
        void clear();
        void addRainbowSealBubble(RainbowSealBubble* bubble);
        void beginSealingCharactor();
        void moveSealedCharactor(RainbowSealBubble* bubble);
        void setRainbowCharactor(RainbowCharactor* charactor);
        RainbowCharactor* getRainbowCharactor();
        bool haveBeganSealed();
        cocos2d::Color3B getColor3BWithBubbleColor(BubbleType color);
    private:
        RainbowSealManager();
        RainbowSealBubble* getNextRainbowSealBubble();
    private:
        cocos2d::Vector<RainbowSealBubble*> rainbow_seal_bubbles_;
        RainbowCharactor* rainbow_charactor_;
        std::map<BubbleType, cocos2d::Color3B> bubblecolor_to_color3b_;
    };
}
#endif //_RAINBOW_SEAL_MANAGER_H_