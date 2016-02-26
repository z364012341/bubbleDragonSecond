//*******************************************************************************
//类名称   : NullBubble
//功能     : <作为空的不可见也不可消除的泡泡>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _NULL_BUBBLE_H_
#define _NULL_BUBBLE_H_
#include "BaseBubble.h"
namespace bubble_second {
    class NullBubble : public BaseBubble
    {
    public:
        CREATE_FUNC(NullBubble);
        virtual ~NullBubble();
        void bubbleEliminate(int combo = 0) override;
        bool needRemoveFromBubbleMap() override;
    private:
        NullBubble();
        bool init();
    };
}
#endif //_NULL_BUBBLE_H_