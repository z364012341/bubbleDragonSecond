//*******************************************************************************
//类名称   : AimingLineCommodity
//功能     : <瞄准线道具>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _AIMING_LINE_COMMODITY_H_
#define _AIMING_LINE_COMMODITY_H_
#include "EnterGamePropsView.h"
namespace bubble_second {
    class AimingLineCommodity : public EnterGamePropsView
    {
    public:
        CREATE_FUNC(AimingLineCommodity);
        ~AimingLineCommodity();
    private:
        AimingLineCommodity();
        bool init();
    };
}
#endif //_AIMING_LINE_COMMODITY_H_