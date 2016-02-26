//*******************************************************************************
//类名称   : AddSpecialCommodity
//功能     : <加3特殊泡泡道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _ADD_SPECIAL_COMMODITY_H_
#define _ADD_SPECIAL_COMMODITY_H_
#include "EnterGamePropsView.h"
namespace bubble_second {
    class AddSpecialCommodity : public EnterGamePropsView
    {
    public:
        CREATE_FUNC(AddSpecialCommodity);
        AddSpecialCommodity();
        ~AddSpecialCommodity();
        bool init();
    };
}
#endif //_ADD_SPECIAL_COMMODITY_H_