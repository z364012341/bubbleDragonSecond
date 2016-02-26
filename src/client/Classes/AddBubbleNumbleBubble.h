//*******************************************************************************
//文件名         : <AddBubbleNumbleBubble.h>
//文件实现功能  : <++泡泡, 增加发射球数量>
//作者         : <黄泽昊.,.>
//版本         : <1.0>
//-------------------------------------------------------------------------------
//修改记录 :
//日 期        版本     修改人              修改内容
//2015/09/15   1.0     <黄泽昊>            <新添加>
//*******************************************************************************
#ifndef _ADD_BUBBLE_NUMBLE_BUBBLE_H_
#define _ADD_BUBBLE_NUMBLE_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class AddBubbleNumbleBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(AddBubbleNumbleBubble);
        ~AddBubbleNumbleBubble();
    public:
        void downFromAir() override;
        void bubbleEliminate(int numble = 0) override;
        float playTheSpecialEffects() override;
    private:
        AddBubbleNumbleBubble();
        bool init();
    };
}
#endif //_ADD_BUBBLE_NUMBLE_BUBBLE_H_