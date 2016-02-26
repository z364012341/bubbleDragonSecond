//*******************************************************************************
//文件名         : <LightningBubble.h>
//文件实现功能  : <闪电泡泡, 触发消除所在的一行>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//修改记录 :
//日 期        版本     修改人              修改内容
//2015/09/15   1.0     <黄泽昊>            <新添加>
//*******************************************************************************
#ifndef _LIGHTNING_BUBBLE_H_
#define _LIGHTNING_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class LightningBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(LightningBubble);
        ~LightningBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int) override;
        float playTheSpecialEffects() override;
    private:
        LightningBubble();
        bool init();
    };
}
#endif //_LIGHTNING_BUBBLE_H_