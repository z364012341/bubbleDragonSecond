//*******************************************************************************
//文件名         : <BubbleComponent.h>
//文件实现功能  : <彩虹封印de组件>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _BUBBLE_COMPONENT_H_
#define _BUBBLE_COMPONENT_H_
#include "BaseBubble.h"
namespace bubble_second {
    class BubbleComponent : public BaseBubble
    {
    public:
        static BubbleComponent* createWithCore(BaseBubble* bubble)
        {
            BubbleComponent *pRet = new(std::nothrow) BubbleComponent();
            if (pRet && pRet->initWithCore(bubble))
            {
                pRet->autorelease();
                return pRet;
            }
            else
            {
                delete pRet;
                pRet = NULL;
                return NULL;
            }
        }
        ~BubbleComponent();
        void setCoreBubble(BaseBubble* bubble);
        BaseBubble* getCoreBubble();
        BubbleVector getTotalBubbles();
        void bubbleEliminate(int combo = 0) override;
        void downFromAir() override;
    private:
        BubbleComponent();
        bool initWithCore(BaseBubble* bubble);
    private:
        BaseBubble* core_bubble_;
    };
}
#endif //_BUBBLE_COMPONENT_H_