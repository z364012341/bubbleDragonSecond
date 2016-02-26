//*******************************************************************************
//类名称   : NullBubble
//功能     : <作为空的不可见也不可消除的泡泡>
//-------------------------------------------------------------------------------
//备注     : <>
//典型用法 : <>
//-------------------------------------------------------------------------------
//作者     : <黄泽昊>, [yyy], [zzz] ...（作者和逗号分割的修改者列表）
//*******************************************************************************
#ifndef _PROPS_SELECT_ALERT_H_
#define _PROPS_SELECT_ALERT_H_
#include "cocos2d.h"
namespace bubble_second {
    class PropsSelectAlert : public cocos2d::Node
    {
    public:
        CREATE_FUNC(PropsSelectAlert);
        ~PropsSelectAlert();
    private:
        PropsSelectAlert();
        bool init();
        void initPannel();
    };
}
#endif //_PROPS_SELECT_ALERT_H_