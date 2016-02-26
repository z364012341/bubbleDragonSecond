//*******************************************************************************
//类名称   : AddBubbleNumbleCommodity
//功能     : <加10泡泡数量道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _ADD_BUBBLE_NUMBLE_COMMODITY_H_
#define _ADD_BUBBLE_NUMBLE_COMMODITY_H_
#include "EnterGamePropsView.h"
namespace bubble_second {
    class AddBubbleNumbleCommodity : public EnterGamePropsView
    {
    public:
        CREATE_FUNC(AddBubbleNumbleCommodity);
        AddBubbleNumbleCommodity();
        ~AddBubbleNumbleCommodity();
    private:
        bool init();
    };
}
#endif // _ADD_BUBBLE_NUMBLE_COMMODITY_H_